class Solution {
public:
    set<vector<int>>ans;
    void helper(vector<int>&nums, vector<int>&a, int i)
    {
        if(a.size()>1)
        {
            ans.insert(a);

        }
         if(a.size()==0 && i<nums.size())
        {
            a.push_back(nums[i]);                //including
            helper(nums, a, i+1);

            a.pop_back();                       //excluding
            helper(nums,a, i+1);
        }

        else if(a.size()>0 && i<nums.size())
        {
            if(a.back()<=nums[i])
            {
                a.push_back(nums[i]);                //including
                helper(nums, a, i+1);

                a.pop_back();                       //excluding
                helper(nums,a, i+1);
            }
            else
            {
                helper(nums,a, i+1);//not including
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      
            vector<int>a;
            helper(nums,a,0);
            vector<vector<int>>an(ans.begin(),ans.end());
            
        return an;
    }
};