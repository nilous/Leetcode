#include <algorithm>
#include <vector>

using std::vector;

// Space complexity: O(n)
// Time complexity: O(nlogn)
vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> nums(numbers);

    int n1, n2;
    std::sort(nums.begin(), nums.end());  // O(nlogn)
    
    int sum;
    for (int head = 0, tail = nums.size()-1; head < tail;) {  // O(n)
        sum = nums[head] + nums[tail];
        if (sum == target) {
            n1 = nums[head];
            n2 = nums[tail];
            break;
        }
        if (sum < target)
            head++;
        else
            tail--;
    }

    int i1 = -1;
    int i2 = -1;

    for (size_t i = 0; i < numbers.size(); i++) { // O(n)
        if (numbers[i] == n1 && i1 == -1)
            i1 = i+1;
        // This 'else' is necessary.
        // Consider the situation that the two numbers are the same.
        else if (numbers[i] == n2 && i2 == -1)
            i2 = i+1;

        if (i1 != -1 && i2 != -1)
            break;
    }

    vector<int> ret{ i1, i2 };  // C++11 rocks!
    std::sort(ret.begin(), ret.end());
    return ret;
}