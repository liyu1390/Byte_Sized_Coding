int trailingZeroes(int n) {
    long base = 5;
    int numFives = 0;
    while (base <= n)
    {
        numFives += floor(n/base);
        base *= 5;
    }
    return numFives;
}