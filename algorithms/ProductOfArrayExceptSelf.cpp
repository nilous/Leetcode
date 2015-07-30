/**
Given an array of n integers where n > 1, nums, return an array output such
that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? 
(Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(const std::vector<int> &nums) {
    std::vector<int> ret(nums.size(), 1);
    for (size_t i = 1, sz = nums.size(); i != sz; ++i) ret[i] = ret[i-1] * nums[i-1];
    int right = 1;
    for (auto i = static_cast<int>(nums.size() - 1); i >= 0; --i) { ret[i] *= right; right *= nums[i]; }
    return ret;
}

int main(int argc, char **argv) {
    for (auto x : productExceptSelf({1, 2, 3, 4}))
        std::cout << x << ' ';
    return 0;
}
