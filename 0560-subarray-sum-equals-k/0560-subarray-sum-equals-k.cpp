class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n=nums.size();

        unordered_map<int,int>mp;

        int result=0;

        mp[0]=1;

        int currSum=0;

        for(int i=0;i<n;i++)
        {
            currSum+=nums[i];
            if(mp.count(currSum-k))
            {
                result+=mp[currSum-k];
            }
            mp[currSum]++;
        }

        return result;
    }
};