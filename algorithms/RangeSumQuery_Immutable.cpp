/**
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

#include <vector>
using namespace std;

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
class NumArray {
    vector<int> sums;
public:
    explicit NumArray(vector<int> &nums)
        : sums(nums.size()+1) {
        sums[0] = 0;
        for (auto i = 1; i <= nums.size(); ++i)
            sums[i] = sums[i-1] + nums[i-1];
    }

    int sumRange(int i, int j) {
        return sums[j+1] - sums[i]; 
    }
};

