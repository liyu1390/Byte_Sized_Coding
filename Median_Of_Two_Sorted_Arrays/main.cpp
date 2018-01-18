double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> A, B;
    if (nums1.size() < nums2.size())
        A = nums1, B = nums2;
    else
        A = nums2, B = nums1;
    
    int m = A.size(), n = B.size();
    int imin = 0, imax = m;
    int halfSize = (m + n + 1)/2;
    int i, j;
    while (true)
    {
        i = (imin + imax)/2;
        j = halfSize - i;
        if ((i == 0 or j == n or (A[i-1] <= B[j]))
             and (j == 0 or i == m or (B[j-1] <= A[i])))
        {
            int leftMax;
            if (i == 0)
                leftMax = B[j-1];
            else if (j == 0)
                leftMax = A[i-1];
            else
                leftMax = max(A[i-1], B[j-1]);
            
            if ((n+m)%2 == 1)
                return leftMax;
            
            int rightMax;
            if (j == n)
                rightMax = A[i];
            else if (i == m)
                rightMax = B[j];
            else
                rightMax = min(A[i], B[j]);
            
            return (leftMax + rightMax) / 2.0;   
        }
        else if (A[i-1] > B[j])
        {
            imax = i - 1;
        }
        else if (A[i] < B[j-1])
        {
            imin = i + 1;
        }
    }
}