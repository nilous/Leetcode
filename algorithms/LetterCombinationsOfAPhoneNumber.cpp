/**
Given a digit string, return all possible letter combinations that the number could represent.

Mapping:
========
2: abc
3: def
4: ghi
5: jkl
6: mno
7: pqrs
8: tuv
9: wxyz

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> mapping = {
    " ",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

// char_loop: 每个字符应该连续“输出”几次
// overall_loop: char_loop本身应该连续“输出”几次
void DecideLoopCount(string digits, int index, int &char_loop, int &overall_loop) {
    overall_loop = 1;
    for (auto i = index-1; i != -1; --i)
        overall_loop *= mapping[digits[i]-'0'].size();

    char_loop = 1;
    for (auto i = index+1; i != digits.size(); ++i)
        char_loop *= mapping[digits[i]-'0'].size();
}


vector<string> letterCombinations(string digits) {
    for (auto it = digits.begin(); it != digits.end(); ++it)
        if (*it == '1') digits.erase(it);



    vector<string> result;

    int c, o;
    int ri;
    for (auto i = 0; i < digits.size(); ++i) {
        ri = 0;
        DecideLoopCount(digits, i, c, o);
        for (auto oi = 0; oi < o; ++oi) {
            for (auto ch : mapping[digits[i]-'0']) {
                for (auto ci = 0; ci < c; ++ci) {
                    if (ri >= result.size())
                        result.push_back(string(1, ch));
                    else
                        result[ri] = result[ri] + string(1, ch);
                    ++ri; 
                }
            }
        }
    }


    return result;
}

int main(int ac, char **av) {
    for (auto s : letterCombinations(av[1]))
        cout << s << '\n';

    return 0;
}
