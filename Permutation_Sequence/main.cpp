string getPermutation(int n, int k) {
    vector<int> outputVec = createSet(n);
    permutate(outputVec, n, 0, k-1);
    return createString(outputVec);
}

void permutate(vector<int> &perm, int n, int start, int k)
{
    int cycle = k/factorial(n-start-1);
    if (cycle != 0)
    {
        int tmp = perm[cycle+start];
        perm.erase(perm.begin()+cycle+start);
        perm.insert(perm.begin()+start, tmp);
    }
    if (k%factorial(n-start-1) == 0)
        return;
    permutate(perm, n, start+1, k%factorial(n-start-1));
}


vector<int> createSet(int n)
{
    vector<int> output;
    for(int i = 1; i <= n; i++)
        output.push_back(i);
    return output;
}

string createString(const vector<int> &perm)
{
    std::stringstream result;
    std::copy(perm.begin(), perm.end(), std::ostream_iterator<int>(result, ""));
    return result.str();
}

int factorial(int n)
{
    if(n > 1) return n * factorial(n - 1);
    return 1;
}