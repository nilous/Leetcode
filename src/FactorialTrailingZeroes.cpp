int trailingZeroes(int n) {
    int sum = 0;
    //for (int i = 5; i <= n; i *= 5)  // Overflow!!
    for(long long i = 5; n/i > 0 && i <= n; i *= 5)
        sum += n/i;
    return sum;
}