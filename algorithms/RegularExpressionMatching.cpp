/**
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

#include <assert.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ANYCHAR 256
#define SPLIT 257
#define MATCH 258

struct State {
    int c;
    State *out;
    State *out1;
};

struct Frag {
    State *start;
    State **out;
};

State *Compile(string p) {
    vector<Frag> v;

    for (auto c : p) {
        if (c == '*') {
            auto b = v.back();
            v.pop_back();

            auto s = new State;
            s->c = SPLIT;
            s->out = b.start;
            *b.out = s;

            b.start = s;
            b.out = &s->out1;
            v.push_back(b);
        } else {
            auto s = new State;
            s->c = (c == '.' ? ANYCHAR : c);
            Frag f;
            f.start = s;
            f.out = &s->out;
            v.push_back(f);
        }
    }

    for (auto i = 0; i < v.size()-1; ++i)
        *v[i].out = v[i+1].start;
    auto s = new State;
    s->c = MATCH;
    *v.back().out = s;

    return v[0].start;
}

vector<State *> EpsilonClosure(const vector<State *> &vs) {
    auto tmp = vs;
    auto it = tmp.end();
    State *s1, *s2;
    while ((it = find_if(tmp.begin(), tmp.end(), [](State *s){ return s->c == SPLIT; })) != tmp.end()) {
        s1 = (*it)->out;
        s2 = (*it)->out1;
        tmp.erase(it);
        tmp.push_back(s1);
        tmp.push_back(s2);
        //cout << "s1: " << s1->c << '\n';
        //cout << "s2: " << s2->c << '\n';
    }
    sort(tmp.begin(), tmp.end());
    tmp.resize(distance(tmp.begin(), unique(tmp.begin(), tmp.end())));
    return tmp;
}

vector<State *> Move(const vector<State *> &vs, char ch) {
    auto tmp = EpsilonClosure(vs);
    vector<State *> r;
    for (auto s : tmp) {
        if (s->c == ch || s->c == ANYCHAR)
            r.push_back(s->out);
    }
    return r;
}


bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();

    auto start = Compile(p);
    vector<State *> v { start };

    for (auto c : s) {
        v = Move(v, c);
        if (v.empty()) {
            //cout << "Cannot match char: " << c << '\n';
            return false;
        }
    }

    for (auto state : EpsilonClosure(v)) {
        if (state->c == MATCH) return true;
    }

    return false;
}


int main(int argc, char **argv) {

assert(!isMatch("aa","a"));
assert(isMatch("aa","aa"));
assert(!isMatch("aaa","aa"));
assert(isMatch("aa", "a*"));
assert(isMatch("aa", ".*"));
assert(isMatch("ab", ".*"));
assert(isMatch("aab", "c*a*b"));

    return 0;
}
