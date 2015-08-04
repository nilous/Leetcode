/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

#include <string>
using std::string;

bool isIsomorphic(string s, string t) {
#define MAXCHAR 256
    char s2t[MAXCHAR] = { 0 };  // Hash map。注意这里是一个双向的映射
    char t2s[MAXCHAR] = { 0 };

    for (auto i = 0; i < s.size(); ++i) {
        if (s2t[s[i]] == 0) {
            if (t2s[t[i]] != 0) return false;
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        } else {
            if (s2t[s[i]] != t[i]) return false;
        }
    }
    return true;
}

#include <assert.h>

int main(int argc, char **argv) {
    assert(isIsomorphic("", ""));
    assert(!isIsomorphic("ab", "aa"));
    assert(isIsomorphic("egg", "add"));
    assert(!isIsomorphic("foo", "bar"));
    assert(isIsomorphic("paper", "title"));
    return 0;
}
