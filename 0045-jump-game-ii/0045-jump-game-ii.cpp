class Solution {
public:
    int helper(vector<int>& nums, int i, int n, int jumps)
    {
        if(i>=n-1)
        {
            return jumps;
        }
        int Min=INT_MAX;

        for(int j=1;j<=nums[i];j++)
        {
            Min=min(Min,helper(nums, i+j, n, jumps+1));
        }
        return Min;
    }
    int jump(vector<int>& nums) {
        return helper(nums, 0, nums.size(), 0);
    }
};