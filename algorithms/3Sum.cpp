/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using std::vector;

/**
 * 该解法会导致 Time Limit Exceeded
 * 该解法沿用的twoSum()中的方法。时间复杂度是O(n^2)。
 */
vector<vector<int>> threeSum(vector<int> &num) {
    std::sort(num.begin(), num.end());
    vector<vector<int>> result;

    for (size_t i = 0; i < num.size(); ++i) {
        if (i != 0 && num[i-1] == num[i]) continue;  // 当前数字与前一个相同，所有的可能解已包含
        int target = 0 - num[i];
        std::unordered_map<int, int> map;
        for (size_t j = i+1; j < num.size(); ++j) {
            if (map.find(num[j]) != map.end()) {
                result.push_back({ num[i], num[map[num[j]]], num[j] });  // <- 注意顺序，重要。
                // 不要break，可能有更多解
            } else {
                map[target - num[j]] = j;
            }
        }
    }

    return result;
}

/**
 * 使用了twoSum的解法1：因为今次只需要值，而不需要indexes，就可以除去繁琐的步骤。
 *
 * 时间复杂度差不多是O(n*n/2)
 */
vector<vector<int>> threeSum2(vector<int> &num) {
    std::sort(num.begin(), num.end());
    vector<vector<int>> result;

    int n = num.size();
    for (auto i = 0; i < n-2; ++i) {
        if (i != 0 && num[i-1] == num[i]) continue;
        int head = i+1;
        int tail = n-1;
        while (head < tail) {
            int sum = num[head]+num[tail]+num[i];
            if (sum == 0) {
                result.push_back({ num[i], num[head], num[tail] });
                while (head < n && num[head] == num[head+1]) ++head;  // 跳过重复元素
                while (tail > i && num[tail] == num[tail-1]) --tail;
                ++head;
                --tail;
            } else if (sum > 0) {
                while (tail > i && num[tail] == num[tail-1]) --tail;
                --tail;
            } else {
                while (head < n && num[head] == num[head+1]) ++head;
                ++head;
            }
        }
    }
    return result;
}

struct TestCase {
    vector<int> nums;
    vector<vector<int>> expected;
};

std::vector<TestCase> cases {
    { {}, {} },
    { { 1 }, {} },
    { { 1, 2 }, {} },
    { { 1, 2, 3 }, {} },
    { { 1, 2, -3 }, { { -3, 1, 2 } } },
    { { -1, 0, 1, 2, -1, 4 }, { { -1, 0, 1 }, { -1, -1, 2 } } } 
};

#include <assert.h>

int main(int argc, char **argv) {
    for (auto c : cases) {
        assert(threeSum(c.nums) == c.expected);

        //assert(threeSum2(c.nums) == c.expected);
        auto r = threeSum2(c.nums);
        std::sort(r.begin(), r.end());
        std::sort(c.expected.begin(), c.expected.end());
        assert(r == c.expected);
    }
    

    return 0;
}
