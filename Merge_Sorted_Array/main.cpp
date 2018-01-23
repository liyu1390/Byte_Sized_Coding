void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int cur1 = m - 1, cur2 = n - 1;
    for(int i = m + n - 1; i >= 0; --i)
    {
        if (cur1 < 0)
        {
            nums1[i] = nums2[cur2];
            cur2--;
        }
        else if (cur2 < 0 || (nums1[cur1] > nums2[cur2]))
        {
            nums1[i] = nums1[cur1];
            cur1--;
        }
        else 
        {
            nums1[i] = nums2[cur2];
            cur2--;
        }
    }
}