/**
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/

#include <string>
using std::string;
#include <iostream>

// 一种相对低效的实现
string longestPalindrome(const string &s) {
    if (s.size() < 2) return s;

    auto start = 0;
    auto length = 0;
    auto len = 0;

    for (auto i = 0; i < s.size(); ++i) {
        len = 1;
        int h = 0, t = 0;
        for (h = i-1, t = i+1; h >= 0 && t < s.size(); --h, ++t) {
            if (s[h] != s[t]) break;
            len += 2;
        }
        if (len > length) { start = h+1; length = len; }
        len = 0;
        for (h = i, t = i+1; h >= 0 && t < s.size(); --h, ++t) {
            if (s[h] != s[t]) break;
            len += 2;
        }
        if (len > length) { start = h+1; length = len; }
    }

    return s.substr(start, length);
}

int main(int argc, char **argv) {
    std::cout << longestPalindrome(argv[1]) << '\n';

    return 0;
}
