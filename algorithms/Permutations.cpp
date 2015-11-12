/**
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool NextPermutation(vector<int> &elements) {
    if (elements.size() < 2) return false;

    int i, j;
    i = j = elements.size() - 1;

    while (i > 0 && elements[i-1] >= elements[i]) --i;

    if (i == 0) return false;

    while (elements[i-1] >= elements[j]) --j;
    swap(elements[i-1], elements[j]);
    reverse(elements.begin()+i, elements.end());
    return true;
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());
    do {
       result.push_back(nums); 
    } while (NextPermutation(nums));

    return result;
}

int main(int ac, char **av) {
    vector<int> v{1,1,3};

    for (auto v : permute(v)) {
        for (auto i : v)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
