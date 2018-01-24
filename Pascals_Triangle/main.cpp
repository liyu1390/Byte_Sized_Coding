vector<vector<int>> generate(int numRows) {
    vector<vector<int>> vec;
    if (numRows <= 0)
        return vec;
    vec.push_back({1});
    
    for (int i = 0; i < numRows-1; ++i)
    {
        vec.push_back(createNextLevel(vec[i]));
    }
    
    return vec;
}

vector<int> createNextLevel(vector<int>& vec){
    int prevWidth = vec.size();
    vector<int> newVec(prevWidth + 1);
    
    for (int i = 1; i < prevWidth; ++i)
    {
        newVec[i] = vec[i-1] + vec[i];
    }
    newVec[0] = 1, newVec[prevWidth] = 1;
    
    return newVec;
}