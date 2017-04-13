/*
Suppose an array sorted in ascending order is rotated at some pivot unknown
to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.
You may assume no duplicate exists in the array.
*/

#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
      //assert(nums.size() > 1);

      size_t begin = 0;
      size_t end = nums.size() - 1;

      while (1) {
        size_t mid = (end - begin) / 2 + begin;
        //cout << begin << ',' << mid << ',' << end << '\n';

        if (nums[begin] > nums[mid]) {  // 翻转点在前半段
          end = mid;
        } else if (nums[mid] > nums[end]) {  // 翻转点在后半段
          begin = mid + 1;
        } else {  // 当前序列已序
          return nums[begin];
        }
      }
    }
};



int main() {
  assert(Solution().findMin(vector<int> { 1 }) == 1);
  assert(Solution().findMin(vector<int> { 1, 0 }) == 0);
  assert(Solution().findMin(vector<int> { 4, 5, 6, 7, 0, 1, 2 }) == 0);
  assert(Solution().findMin(vector<int> { 3, 4, 5, 6, 7, 0, 1, 2 }) == 0);
  assert(Solution().findMin(vector<int> { 3, 4, 5, 6, 7, 8, 9, 2 }) == 2);
  assert(Solution().findMin(vector<int> { 1, 2, 3, 4, 5, 6, 7 }) == 1);
  return 0;
}
