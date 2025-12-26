class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>>&mp, string src, string dest, unordered_set<string>&vis, double prod, double &ans)
    {
        if(vis.find(src)!=vis.end()){
            return ;
        }
        vis.insert(src);

        if(src==dest)
        {
            ans=prod;
            return;
        }
        for(auto &p:mp[src]){
            string v=p.first;
            double val=p.second;

            dfs(mp,v,dest,vis,prod*val,ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,vector<pair<string,double>>>mp;
        for(int i=0;i<equations.size();i++)
        {
            string u= equations[i][0];
            string v=equations[i][1];

            double val=values[i];
            mp[u].push_back(make_pair(v,val));
            mp[v].push_back(make_pair(u,1.0/val));
        }

        vector<double>res;

        for(int i=0;i<queries.size();i++)
        {
            string src=queries[i][0];
            string dest=queries[i][1];

           

            double ans=-1.0;
            double prod=1.0;

            if(mp.find(src)!=mp.end()){
                unordered_set<string> vis;
                dfs(mp,src,dest,vis,prod,ans);
            }
            res.push_back(ans);
        }

        return res;
    }
};