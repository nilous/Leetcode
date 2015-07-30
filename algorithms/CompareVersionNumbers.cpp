#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<int> splitVersionNumbers(const string &vs) {
    vector<int> ret;
    auto it = vs.begin();
    while (1) {
        auto tmp = std::find(it, vs.end(), '.');
        ret.push_back(atoi(std::string(it, tmp).data()));
        if (tmp == vs.end())
            break;
        it = tmp + 1;
    }
    return ret;
}

int compareVersion(string version1, string version2) {
    vector<int> v1 = splitVersionNumbers(version1);
    vector<int> v2 = splitVersionNumbers(version2);

    for (size_t i = 0; i < std::min(v1.size(), v2.size()); i++) {
        if (v1[i] != v2[i])
            return v1[i] > v2[i] ? 1 : -1;
    }

    int val1, val2;
    for (size_t i = std::min(v1.size(), v2.size()); i < std::max(v1.size(), v2.size()); i++) {
        val1 = (i >= v1.size()) ? 0 : v1[i];
        val2 = (i >= v2.size()) ? 0 : v2[i];
        if (val1 != val2)
            return val1 > val2 ? 1 : -1;
    }

    return 0;
}