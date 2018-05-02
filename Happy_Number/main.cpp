bool isHappy(int n) {
    set<int> seen;
    while(n != 1)
    {
        if (seen.find(n) != seen.end())
            return false;
        else
            seen.insert(n);
        int sum = 0;
        while (n != 0)
        {
            sum += (pow(n%10,2));
            n /= 10;
        }
        n = sum;
    }
    return true;
}