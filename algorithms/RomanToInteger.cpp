/**
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
*/

/**
基本字符	            I V X   L   C   D   M
相应的阿拉伯数字表示为	1 5 10  50  100 500 1000

1. 相同的数字连写、所表示的数等于这些数字相加得到的数、如：III=3；
2. 小的数字在大的数字的右边、所表示的数等于这些数字相加得到的数、 如：VIII=8、XII=12；
3. 小的数字、（限于 I、X 和 C）在大的数字的左边、所表示的数等于大数减小数得到的数、如：IV=4、IX=9；
4. 正常使用时、连写的数字重复不得超过三次。（表盘上的四点钟“IIII”例外）；
5*. 在一个数的上面画一条横线、表示这个数扩大 1000 倍。
*/

#include <assert.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// 投机取巧的解法：利用转换表来转换

struct Mapping {
    string s;
    int i;
};

vector<Mapping> mappings {
    { "MMM", 3000 },
    { "MM", 2000 },
    { "M", 1000 },
    { "CM", 900 },
    { "DCCC", 800 },
    { "DCC", 700 },
    { "DC", 600 },
    { "D", 500 },
    { "CD", 400 },
    { "CCC", 300 },
    { "CC", 200 },
    { "C", 100 },
    { "XC", 90 },
    { "LXXX", 80 },
    { "LXX", 70 },
    { "LX", 60 },
    { "L", 50 },
    { "XL", 40 },
    { "XXX", 30 },
    { "XX", 20 },
    { "X", 10 },
    { "IX", 9 },
    { "VIII", 8 },
    { "VII", 7 },
    { "VI", 6 },
    { "V", 5 },
    { "IV", 4 },
    { "III", 3 },
    { "II", 2 },
    { "I", 1 }
};

bool StartsWith(string str, string sub) {
    if (str.size() < sub.size()) return false;
    return memcmp(str.data(), sub.data(), sub.size()) == 0;
}

int romanToInt1(string s) {
    auto n = 0;
    auto p = s.data();
    while (*p != '\0') {
        for (auto m : mappings) {
            if (StartsWith(p, m.s)) {
                n += m.i;
                p += m.s.size();
                break;
            }
        }
    }
    return n;
}


////////////////////////////////////////////////////////////////////////////////
//


/**
 
  龙书练习2.2.6

roman_num -> thousand hundred ten digit
thousand -> M | MM | MMM | e
hundred -> small_hundred | CD | D small_hundred | CM
small_hundred -> C | CC | CCC | e
ten -> small_ten | XL | L small_ten | XC
small_ten -> X | XX | XXX | e
digit -> small_digit | IV | V small_digit | IX
small_digit -> I | II | III | e
*/


int main(int ac, char **av) {
    cout << romanToInt(av[1]) << '\n';
    return 0;
}
