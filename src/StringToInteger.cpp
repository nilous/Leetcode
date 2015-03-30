#include <math.h>
#include <string>

using std::string;

int _atoi(string str) {
    int i = 0;

    // Skip leading whitespaces
    while (isspace(str[i])) {
        i++;
        if (i >= str.size())  // The string contains only whitespaces
            return 0;
    }

    std::string s;

    int sign;
    switch (str[i]) {
    case '+':
        sign = 1;
        i++;
        break;
    case '-':
        i++;
        sign = -1;
        break;
    default:
        if (isdigit(str[i])) {
            sign = 1;
            //--i;
        } else {
            return 0;  // Not a valid number
        }
    }

    while (isdigit(str[i]) && i < str.size())
        s += str[i++];
    
    if (s.empty()) return 0;

    long long ret = 0;
    int factor = 0;
    for (auto it = s.rbegin(); it != s.rend(); it++, factor++) {
        ret += (*it-'0')*pow(10, factor);
        if (sign == 1 && ret > INT_MAX)
            return INT_MAX;
        if (sign == -1 && ret > (INT_MAX+1LL))
            return INT_MIN;
    }

    return sign * ret;
}