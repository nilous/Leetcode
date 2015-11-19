/**
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
    auto carry = 1;
    for (int i = digits.size()-1; i >= 0; --i) {
        auto tmp = digits[i] + carry;
        carry = tmp > 9 ? 1 : 0;
        digits[i] = tmp % 10; 
        if (!carry) break;
    }

    if (carry) digits.insert(digits.begin(), carry); 
    return digits;
}

int main(int ac, char **av) {
    vector<int> v{9,9,9};
plusOne(v);
    for (auto i : v)
        cout << i;
    cout << '\n';

    return 0;
}
