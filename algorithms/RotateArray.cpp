#include <string.h>

void rotate(int nums[], int n, int k) {
    k %= n;
    if (k == 0) return;
    int *r = new int[n];
    memcpy(r, nums+n-k, sizeof(int)*k);
    memcpy(r+k, nums, sizeof(int)*(n-k));
    memcpy(nums, r, sizeof(int)*n);
    delete[] r;
}