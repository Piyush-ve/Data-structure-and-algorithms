class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)return ;
        for(int i=0;i<m;i++)
        {
            if(nums1[i]>nums2[0])
            {
                swap(nums1[i], nums2[0]);
                sort(nums2.begin(),nums2.end());
            }
        }

        for(int i=0;i<n;i++)
        {
            nums1[m+i]=nums2[i];
        }
        return ;
    }
};