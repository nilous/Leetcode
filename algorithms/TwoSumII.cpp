/**
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

/** 思路：即TwoSum.cpp中的解法1。既然是已序的，显然复杂度为O(n) */

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int b = 0, e = numbers.size() - 1;
        while (b < e) {
            auto sum = numbers[b] + numbers[e];
            if (sum == target) return vector<int> { b+1, e+1 };
            if (sum > target) --e; else ++b;
        }
        return vector<int> {};
    }
};

#include <iostream>

int main(int argc, char **argv) {
    vector<int> v{ 2, 7, 11, 15 };
    auto rv = Solution().twoSum(v, 9);
    for (auto i : rv)
        std::cout << i << ' ';
    return 0;
}
