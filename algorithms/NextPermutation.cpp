/**
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 在当前序列中，从尾端往前寻找两个相邻元素，前一个记为*i，后一个记为*ii，并且满足*i < *ii。然后再从尾端寻找另一个元素*j，
 * 如果满足*i < *j，即将第i个元素与第j个元素对调，并将第ii个元素之后（包括ii）的所有元素颠倒排序，即求出下一个序列了。
 */

void NextPermutation(vector<int> &elements) {
    if (elements.size() < 2) return;

    int i, j;
    i = j = elements.size() - 1;

    while (i > 0 && elements[i-1] >= elements[i]) --i;

    if (i == 0) {
        cout << "Reverse all elements!\n";
        reverse(elements.begin(), elements.end());
        return;
    }

    while (elements[i-1] >= elements[j]) --j;
    swap(elements[i-1], elements[j]);
    reverse(elements.begin()+i, elements.end());
}

int main(int ac, char **av) {
    vector<int> v{1,2,3,4};
    NextPermutation(v);
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';
    return 0;
}
