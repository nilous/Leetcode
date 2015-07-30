#include <math.h>
#include <stdio.h>

bool isPalindrome(int x) {
    if (x < 0) return false;

    int xx = x;
    int n = 1;
    while ((xx /= 10) > 0)
        n++;
    
    int head, tail;
    int hn, tn;
    for (head = n-1, tail = 0; head > tail; head--, tail++) {
        hn = (x/static_cast<int>(pow(10.0, head)))%10;
        tn = (x%static_cast<int>(pow(10.0,tail+1)))/pow(10.0,tail);
        if (hn != tn)
            return false;
    }
    return true;
}