class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();

        for(int i=0;i<nums.size();i++)
        {
           if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            
            for(int j=i+1;j<n;)
            {
  
                int k=j+1;
                int l=n-1;
                while(k<l)
                {
                    long long sum =(long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target)
                    {
                        vector<int>quad = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(quad);
                        k++;
                        l--;

                        while(k<l && nums[k]== nums[k-1]) 
                        k++;

                        while(k<l && nums[l]== nums[l+1]) 
                        l--;
        
                    }
                    else if(sum>target)
                    {
                        l--;
                    }
                    else{
                        k++;
                    }


                }

                j++;
                while(j<n && nums[j]== nums[j-1]) 
                    j++;
            }

        }

        return ans;
    }
};