#include <algorithm>
#include <vector>

using std::vector;

int majorityElement(vector<int> &num) {
    if (num.size() == 1) return num[0];
    std::sort(num.begin(), num.end());
    int continous = 1;
    for (size_t i = 1; i < num.size(); i++) {
        if (num[i] == num[i-1]) {
            continous++;
            if (continous > num.size()/2)
                return num[i];
        }else {
            continous = 1;
        }
    }
}