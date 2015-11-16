/**
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums) {
    if (nums.size() < 2) return nums.size();

    auto lastChar = nums[0];
    auto i = 1;
    while (i < nums.size()) {
        if (nums[i] == lastChar) { nums.erase(nums.begin()+i); }
        else { lastChar = nums[i]; ++i; }
    }

    return nums.size();
}

int main(int ac, char **av) {
    cout << removeDuplicates(vector<int>{1,1,2});

    return 0;
}
