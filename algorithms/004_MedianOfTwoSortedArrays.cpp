/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/

#include <algorithm>
#include <iterator>
#include <vector>
using std::vector;

/**
 * 先将两个 arrays merge 起来，再算中位数。
 * 缺点：额外空间: O(m+n)
 */
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    std::vector<int> merged;

    auto it1 = nums1.begin();
    auto it2 = nums2.begin();    

    while (it1 != nums1.end() && it2 != nums2.end()) {
        auto &it = *it1 < *it2 ? it1 : it2;
        merged.push_back(*it++);
    }
    if (it1 != nums1.end())
        std::copy(it1, nums1.end(), std::back_inserter(merged));
    else if (it2 != nums2.end())
        std::copy(it2, nums2.end(), std::back_inserter(merged));

    if (merged.size() % 2 != 0)
        return merged[merged.size()/2];
    else
        return (merged[merged.size()/2-1]+merged[merged.size()/2])/2.0;
}

/**
 * 上一方法的改进：其实我们不需要拷贝原来的元素，我们只要知道中位数相关的位置即可。
 * 所以实际上时间开销是：O((m+n)/2) -> O(m+n) (数量级与原算法是一致的，但要快上一倍）
 */
/**
 * 耶！在C++答案里算最快的那一拨哦！！
 * TODO: 但是C的答案都快很多，是因为vector？有空试试用C来写。
 */
double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2) {
    auto index1 = 0u;
    auto index2 = 0u;
    
    auto total = nums1.size() + nums2.size();
    auto targetIndex = (total+1)/2-1;

    auto lastVal = 0;
    while (index1 < nums1.size() && index2 < nums2.size()) {
        lastVal = nums1[index1] < nums2[index2] ? nums1[index1++] : nums2[index2++];
        if (index1+index2-1 == targetIndex)
            break;
    }

    auto offset = targetIndex - (index1+index2-1);
    if (offset > 0) {
        if (index1 == nums1.size()) {
            index2 += offset;
            lastVal = nums2[index2-1];
        } else {
            index1 += offset;
            lastVal = nums1[index1-1];
        }
    }

    if (total % 2 != 0) {
        return lastVal;
    } else {
        auto thisVal = 0;
        if (index1 == nums1.size())
            thisVal = nums2[index2];
        else if (index2 == nums2.size())
            thisVal = nums1[index1];
        else
            thisVal = std::min(nums1[index1], nums2[index2]);

        return (lastVal+thisVal)/2.0;

    }
}

struct TestCase {
    std::vector<int> v1;
    std::vector<int> v2;
    double expected;
};

// 一些测试用例
std::vector<TestCase> cases {
    { { 1, 5, 7 }, { 3, 5, 6, 9 }, 5 },
    { { 1, 5, 7, 8 }, { 3, 5, 6, 9 }, 5.5 },
    { { }, { 3, 5, 6, 9 }, 5.5 },
    { { 1, 5, 7, 8 }, {  }, 6 },
    { { 1 }, {  }, 1 }
};

#include <assert.h>
#include <iostream>
int main(int argc, char **argv) {
    for (auto c : cases) {
        assert(findMedianSortedArrays(c.v1, c.v2) == c.expected);
        assert(findMedianSortedArrays2(c.v1, c.v2) == c.expected);
    }
}
