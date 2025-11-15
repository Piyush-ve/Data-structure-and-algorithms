class Solution {
public:
int timer=1;
    void dfs(unordered_map<int,vector<int>>&mp, int Tin[], int Lin[], vector<bool>&vis, vector<vector<int>>&ans ,int u, int parent)
    {
        vis[u]=true;
        Tin[u]=Lin[u]=timer;
        timer++;

        for(auto v: mp[u])
        {
            if(v==parent)continue;
            if(!vis[v])
            {
                dfs(mp,Tin,Lin,vis,ans,v,u);

                Lin[u]= min(Lin[u], Lin[v]);

                // u---v
                if(Lin[v] > Tin[u])//then it is a bridge
                {
                    ans.push_back({v, u});
                }
            }
            else
            {
                Lin[u]= min(Lin[u], Lin[v]);

            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        int Tin[n]; //time of insertion
        int Lin[n]; //lowest time of insertion

        vector<vector<int>>ans;
        vector<bool>vis(n,false);

        dfs(mp,Tin,Lin,vis,ans,0, -1);

        return ans;
    }
};