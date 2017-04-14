/*
Given an unsorted array return whether an increasing subsequence of length 3
exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
      if (nums.size() < 3)
        return false;

      vector<int> seq { nums[0] };
      for (auto i = 1; i < nums.size(); ++i) {
        switch (seq.size()) {
          case 1:
            if (nums[i] < seq[0])
              seq[0] = nums[i];
            else if (nums[i] > seq[0])  // note!: 处理相同数字
              seq.emplace_back(nums[i]);
            break;
          case 2:
            if (nums[i] > seq[1])
              return true;

            if (nums[i] < seq[0])
              seq.emplace_back(nums[i]);
            else if (nums[i] > seq[0])  // note!: 处理相同数字
              seq[1] = nums[i];

            break;
          case 3:
            if (nums[i] > seq[1])
              return true;

            if (nums[i] > seq[2]) {  // note!: 处理相同数字
              // remove the first two elements
              std::swap(seq[0], seq[2]);
              seq[1] = nums[i];
              seq.pop_back();
            }
            break;
          default:
            assert(0 && "fatal error!!");
        }

        cout << "seq: ";
        for (auto x : seq) {
          cout << x << ' ';
        }
        cout << '\n';
      }


      return false;
    }
};

int main() {
  Solution().increasingTriplet(vector<int> { 1, 1, -2, 6 });
  return 0;
  assert(Solution().increasingTriplet(vector<int> { 1, 2, 3, 4, 5 }));
  assert(!Solution().increasingTriplet(vector<int> { 5, 4, 3, 2, 1 }));

  assert(Solution().increasingTriplet(vector<int> { 4, 9, 1, 3, 5 }));
  assert(Solution().increasingTriplet(vector<int> { 4, 9, 1, 10 }));
  assert(!Solution().increasingTriplet(vector<int> { 4, 9, 1, 8 }));
  assert(!Solution().increasingTriplet(vector<int> { 4, 9, 1, 1, 1, 8 }));
  assert(Solution().increasingTriplet(vector<int> { 4, 9, 1, 8, 3, 2, 5 }));
  assert(Solution().increasingTriplet(vector<int> { 4, 4, 9, 9, 1, 1, 8, 3, 2, 5 }));

  return 0;
}
