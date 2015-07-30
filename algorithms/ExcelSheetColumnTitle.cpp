#include <algorithm>
#include <string>

using std::string;

string convertToTitle(int n) {
    std::string ret;
    while (n > 0) {
        ret += 'A' + (n - 1) % 26;
        n = (n-1)/26;
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}