class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        if(grid.size()==0)return {};
        int n=grid.size();
        int range=pow(n,2);

        unordered_map<int,int>mp;
        for(int i=1;i<=range;i++)
        {
            mp[i]=0;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[grid[i][j]]++;
            }
        }
        vector<int>ans;
        for(auto it:mp)
        {
            if(it.second>1)
            {
                ans.push_back(it.first);
            }
        }
        for(auto it:mp)
        {
            if(it.second<1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;

    }
};