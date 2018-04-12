bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> uniqueNums;
    for (auto num : nums)
    {
        if (uniqueNums.find(num) != uniqueNums.end())
            return true;
        uniqueNums.insert(num);
    }
    return false;
}