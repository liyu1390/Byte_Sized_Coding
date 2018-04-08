int majorityElement(vector<int>& nums) {
    int curCandidate;
    int count = 0;
    for (auto num : nums)
    {
    	if (count == 0)
    		curCandidate = num;
    	count += (num == curCandidate) ? 1 : -1;
    }
    return curCandidate;
}