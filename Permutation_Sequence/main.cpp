string getPermutation(int n, int k) {
    vector<char> outputVec = createSet(n);
    return permutate(outputVec, n, k-1);
}

string permutate(vector<char> &perm, int n, int k)
{
    string output;
    if (n == 0)
        return output;
    int cycle = k/factorial(n-1);
    output += perm[cycle];
    perm.erase(perm.begin()+cycle);
    return output + permutate(perm, n-1, k%factorial(n-1));
}

vector<char> createSet(int n)
{
    vector<char> output;
    for(int i = 1; i <= n; i++)
        output.push_back('0' + i);
    return output;
}

int factorial(int n)
{
    if(n > 1) return n * factorial(n - 1);
    return 1;
}