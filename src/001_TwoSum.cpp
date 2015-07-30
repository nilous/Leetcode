/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#include <algorithm>
#include <unordered_map>
#include <vector>

using std::vector;

/* 
思路：

1. 最暴力的解决方法就是两层循环来尝试每一种组合，其时间复杂度是O(n^2)。

2. 如果vector是以升序排列的，我们可以用两个游标，初始时分别指向头/尾元素。
   如果指向的元素之和小于目标值，则将头游标后移；如果大于目标值，则将尾游标前移。
   这样一来，仅仅需要一次遍历就可以找到对应元素。

   解决方法如下：
   1）赋值原vector元素到新的vector，并将新vector排序
   2）使用上述方法找到目标元素
   3）在原vector中查询目标元素对应的indexes

   额外空间复杂度：O(n)
   时间复杂度：O(nlogn) + O(n) + O(n) = O(nlogn)

*/
vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> sortedNumbers(numbers);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());  // 快排：O(nlogn)
    
    int head = 0;
    int tail = sortedNumbers.size() - 1;
    while (head < tail) {  // O(n)
        int sum = sortedNumbers[head] + sortedNumbers[tail];
        if (sum == target) break;
        if (sum < target) ++head; else --tail;
    }

    std::vector<int> indexes(2, -1);  // -1表示尚未找到
    for (size_t i = 0; i < numbers.size(); ++i) {  // O(n)
        if (numbers[i] == sortedNumbers[head] && indexes[0] == -1) indexes[0] = i + 1;
        else if (numbers[i] == sortedNumbers[tail] && indexes[1] == -1) indexes[1] = i + 1;  // 注意!：这里必须是else if而非if，因为两个数字可能是相同的

        if (indexes[0] != -1 && indexes[1] != -1) break;
    }

    std::sort(indexes.begin(), indexes.end());  // O(1)
    return indexes;
}

/*
3. 利用 map 来处理：
   遍历 numbers，将 target - numbers[i] 作为 key, i 作为 value 存进 map 中。
   如果 numbers[i] 存在于 map 中，那么该 numbers[i] 就是第二个数， 其对应的 value 就是就是第一个数的 index。

   时间/空间复杂度： O(n)
*/
vector<int> twoSum2(vector<int> &numbers, int target) {
    std::unordered_map<int, int> map;
    vector<int> indexes;

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (map.find(numbers[i]) == map.end()) {
            map[target - numbers[i]] = i;
        } else {
            indexes.push_back(map[numbers[i]] + 1);
            indexes.push_back(i + 1);
            break;
        }
    }

    return indexes;
}