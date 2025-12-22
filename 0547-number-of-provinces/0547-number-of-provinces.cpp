class Solution {
public:
    void dfs(int u , unordered_map<int,set<int>>&mp,vector<bool>&vis)
    {
        vis[u]=true;

        set<int>neighbors=mp[u];

        for(auto v:neighbors)
        {
            if(!vis[v])
            {
                dfs(v,mp,vis);
            }
        }


    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,set<int>>mp;

        int n=isConnected.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    if(mp.count(i))
                    {
                        mp[i].insert(j);
                        mp[j].insert(i);
                    }
                    else
                    {
                        mp[i]={j};
                        mp[j]={i};
                    }

                }
            }
        }
        int count=0;
        vector<bool>vis(n,false);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,mp,vis);
                count++;
            }
        }

        return count;
    }
};