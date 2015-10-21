/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

#include <assert.h>
#include <algorithm>
#include <string>
using std::string;

bool isAnagram(string s, string t) {
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());

    return s == t;
}

#include <unordered_map>

/*
 * FIXME
 * 理论上这个解法应该是比上面的快的，但实测是慢的不像话。可能是我对hash表的操作是不对的。
 */
bool isAnagram2(string s, string t) {
    std::unordered_map<char, int> map;
    for (auto c : s) {
        if (map.find(c) != map.end())
            ++map[c];
        else
            map[c] = 1;
    }

    for (auto c : t) {
        if (map.find(c) != map.end()) {
            --map[c];
            if (map[c] == 0)
                map.erase(c);
        } else
            return false;
    }

    return map.empty();
}

struct TestCase {
    string s;
    string t;
    bool expected;
};

std::vector<TestCase> cases {
    { "anagram", "nagaram", true },
    { "", "wow", false },
    { "", "", true },
    { "anagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagramanagram",
      "nagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaramnagaram",
      true }
};

#include <time.h>
#include <iostream>

class Timer {
    std::string d;
    clock_t t;
public:
    Timer(const std::string desc) : d(desc), t(clock()) {}
    ~Timer() {
        std::cout << d << "] Time elapsed: " << ((clock()-t)/CLOCKS_PER_SEC*1000) << "ms\n";
    }
};

int main(int argc, char **argv) {
    for (auto c : cases) {
        assert(isAnagram(c.s, c.t) == c.expected);
        assert(isAnagram2(c.s, c.t) == c.expected);
    }

#define N 100000

    {
        Timer t("isAnagram()");
        for (auto i = 0; i < N; ++i)
            for (auto c : cases)
                isAnagram(c.s, c.t);
    }

    {
        Timer t("isAnagram2()");
        for (auto i = 0; i < N; ++i)
            for (auto c : cases)
                isAnagram2(c.s, c.t);
    }

    return 0;
}
