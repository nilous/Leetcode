/* Write a function to find the longest common prefix string amongst an array of strings. */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/** 初始版本。性能捉急。 */
string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) return "";
    string prefix = strs[0];

    for (size_t i = 1; i < strs.size(); ++i) {
        size_t j = 0;
        for (; j < std::min(prefix.size(), strs[i].size()); ++j) {
            if (prefix[j] != strs[i][j]) break;
        }
        prefix = prefix.substr(0, j);
    }

    return prefix;
}

/** 改进版本：避免的字符串的拷贝动作 */
string longestCommonPrefix2(vector<string> &strs) {
    if (strs.empty()) return "";

    size_t max = strs[0].size();
    for (size_t i = 1; i < strs.size(); ++i) {
        size_t j = 0;
        max = std::min(max, strs[i].size());
        for (; j < max; ++j) {
            if (strs[0][j] != strs[i][j]) break;
        }
        max = j;
    }
    return strs[0].substr(0, max);
}

int main(int argc, char **argv) {
    vector<string> vs {
        "c", "cacc", "ccc"
    };

    std::cout << longestCommonPrefix(vs) << '\n';
    std::cout << longestCommonPrefix2(vs) << '\n';
    return 0;
}
