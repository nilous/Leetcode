/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array,
and it should return false if every element is distinct.
*/

#include <algorithm>
#include <vector>
using std::vector;

/**
 * 先排序、再检查相邻元素是否相同。
 * 时间复杂度： O(nlogn)+O(n) = O(nlogn)
 */
bool containsDuplicate(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    for (auto i = 1; i < nums.size(); ++i) {
        if (nums[i-1] == nums[i]) return true;
    }
    return false;
}

#include <unordered_set>

bool containsDuplicate2(vector<int> &nums) {
    std::unordered_set<int> x;
    for (auto n : nums) {
        auto r = x.insert(n);
        if (!r.second) return true;
    }
    return false;
}

struct TestCase {
    std::vector<int> n;
    bool expected;
};

vector<TestCase> cases {
    { { 1,2,3 }, false },
    { { 1,2,3,1 }, true },
    { {}, false }
};

#include <assert.h>

int main(int argc, char **argv) {
    for (auto c : cases) {
        assert(containsDuplicate2(c.n) == c.expected);
    }
    return 0;
}
