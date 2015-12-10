/**
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 注意要求中的: The order of elements can be changed
    int removeElement(vector<int> &nums, int val) {
        int len = nums.size();
        int i = 0;
        while (i < len) {
            if (nums[i] == val) {
                //std::swap(nums[i], nums[len-1]);  // 删除掉的就不关心了，所以也没必要swap了
                nums[i]=nums[len-1];
                --len;
            } else { ++i; }
        }
        return len;
    }
};

int main(int ac, char **av) {
    vector<int> v {1,2,3,4,3,3,7,4,6,3};
    
    int len = Solution().removeElement(v, 3);
    for (int i = 0; i < len; ++i)
        std::cout << v[i] << ',';
    std::cout << '\n';
    return 0;

}
