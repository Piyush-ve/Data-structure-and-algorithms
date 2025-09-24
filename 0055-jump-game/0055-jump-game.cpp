class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        int maxInd=0;
        int n=nums.size();

        while(i<n && maxInd<n-1)
        {
            maxInd=max(maxInd,nums[i]+i);
           
            if(nums[i]==0 && maxInd==i)
            {
                return false;
            }

             i++;
        }
        
        return true;

    }
};