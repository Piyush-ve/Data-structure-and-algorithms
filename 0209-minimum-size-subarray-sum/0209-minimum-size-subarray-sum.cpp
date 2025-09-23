class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int Min=INT_MAX;

        int i=0;
        int j=0;

        
        long long curr=0;
        while(j<nums.size())
        {
            curr+=nums[j];
            while(curr>=target )
            {
               Min=min(Min,j-i+1);
               curr-=nums[i];
               i++;
            }
            j++;

        }
        return Min==INT_MAX?0:Min;
    }
};