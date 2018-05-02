bool isHappy(int n) 
{
    set<int> seen;
    while(n != 1)
    {
        if (seen.find(n) != seen.end())
            return false;
        seen.insert(n);
        n = sumOfSquaredDigits(n);
    }
    return true;
}

int sumOfSquaredDigits(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += pow(n%10,2);
        n /= 10;
    }
    return sum;
}