/**
Given two sorted integer arrays nums1 and nums2, 
merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n)
to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

std::ostream &operator<<(std::ostream &os, vector<int> &v) {
    for (auto i : v)
        os << i << ',';
    os << '\n';
    return os;
}

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j;
        i = j = 0;

        while (j < n && i < m) {
            if (nums1[i+j] <= nums2[j]) {
                ++i;
            } else {
                nums1.insert(nums1.begin()+i+j, nums2[j]);
                ++j;
            }
        }
        std::copy(nums2.begin()+j, nums2.begin()+n, nums1.begin()+m+j);
        nums1.resize(m+n);
    }
};


int main(int ac, char **av) {
    vector<int> v1 { 2, 0 };
    vector<int> v2 { 1 };

    v1.resize(v1.size()+v2.size());

    Solution().merge(v1, 1, v2, v2.size());
    cout << v1;
    return 0;
}
