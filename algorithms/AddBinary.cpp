/**
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

#include <assert.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// Digit to Integer
#define d2i(x) ((x)-'0')
#define i2d(x) ((x)+'0')

string addBinary(string a, string b) {
    string r;

    int tmp;
    auto carry = 0;
    for (int ai = a.size()-1, bi = b.size()-1; ;) {
        if (ai == -1 && bi == -1) break;

        tmp = (ai == -1 ? 0 : d2i(a[ai])) + (bi == -1 ? 0 : d2i(b[bi])) + carry;
        carry = (tmp > 1) ? 1 : 0;
        r += i2d(tmp%2);


        if (ai != -1) --ai;
        if (bi != -1) --bi;
    }

    if (carry) r += '1';
    std::reverse(r.begin(), r.end());
    return r;
}

int main(int ac, char **av) {
    cout << addBinary("110", "1");
    //assert(addBinary("11", "1") == "100");
    return 0;
}
