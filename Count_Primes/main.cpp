int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    for (int i = 2; i*i < n; i++)
    {
        if (isPrime[i])
        {
            for(int j = i*i; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return countBools(isPrime, true);
}

int countBools(vector<bool> boolVec, bool type)
{
    int sum = 0;
    for (int i = 0; i < boolVec.size(); i++)
    {
        if (boolVec[i] == type) sum++;
    }
    return sum;     
}