class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                int curr=abs(target-sum);
                if(curr<=diff)
                {
                    diff=min(diff,curr);
                    ans=nums[i]+nums[j]+nums[k];

                }

                if(sum==target)
                {
                   
                    j++;
                    k--;

                    while(j<n && nums[j]==nums[j-1])j++;
                    while(nums[k]==nums[k+1])k--;  
                }
                else if(sum<target)
                {
                    
                    
                    j++;
                }
                else
                {
                    
                    
                    k--;
                }
            }
        }
        return ans;

    }
};