#include <math.h>
#include <stdlib.h>

int reverse(int x) {
    int sign = x < 0 ? -1 : 1;

    long long xx, tmp;
    // Casting required! Make the compiler use the 'long long' version abs()
    xx = tmp = abs(static_cast<long long>(x));
    int n = 1;
    while ((tmp /= 10) > 0)
        n++;

    long long sum = 0;
    long long d, v;  // 'v' should be long long to avoid overflow
    for (int pos = 0; pos < n; pos++) {
        d = xx % static_cast<int>(pow(10.0, pos+1)) / static_cast<int>(pow(10.0, pos));
        v = static_cast<long long>(d * pow(10.0, n-pos-1));
        sum += v;

        // Handle overflow situations
        if (sign == 1 && sum > INT_MAX)
            return 0;
        else if (sign == -1 && sum > (INT_MAX+1LL))
            return 0;
    }
    return static_cast<int>(sum*sign);
}