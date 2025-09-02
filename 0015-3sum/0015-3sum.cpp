class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

       sort(nums.begin(),nums.end());

       int n=nums.size();
       vector<vector<int>>ans;

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
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    vector<int>Triplets={nums[i],nums[j],nums[k]};
                   
                        ans.push_back(Triplets);
                        j++;
                        k--;
                        
                        while(j<k && nums[j]==nums[j-1])
                        {
                            j++;
                        }    
  
                }
                else if(nums[i]+nums[j]+nums[k]<0)
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