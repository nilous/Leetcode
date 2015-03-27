#include <math.h>
#include <string>

using std::string;

int titleToNumber(string s) {
    int ret = 0;
    int factor = 0;
    for (auto begin = s.rbegin(), end = s.rend(); begin != end; begin++, factor++)
        ret += (*begin - 'A' + 1) * static_cast<int>(pow(26, factor));

    return ret;
}