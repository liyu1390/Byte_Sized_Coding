//single pass
void sortColors(vector<int>& nums) {
    int j = 0, k = nums.size() - 1, temp;
    for (int i = 0; i <= k; i++)
    {
        if (nums[i] == 0)
        {
            temp = nums[j];
            nums[j++] = nums[i];
            nums[i] = temp;
        }
        else if (nums[i] == 2)
        {
            temp = nums[k];
            nums[k--] = nums[i];
            nums[i--] = temp;
        }
    }
}