int trailingZeroes(int n) {
    int numFives = 0;
    for (long base = 5; base <= n; base *= 5)
    {
        numFives += floor(n/base);
    }
    return numFives;
}