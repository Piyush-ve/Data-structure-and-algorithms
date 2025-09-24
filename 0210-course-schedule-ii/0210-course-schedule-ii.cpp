class Solution {
public:
    bool dfsTopological(int src, vector<bool>&vis, vector<bool>&recPath, vector<vector<int>>& graph, stack<int>&s)
    {
        vis[src]=true;
        recPath[src]=true;

        for(int i=0;i<graph.size();i++)
        {
            int u=graph[i][1];
            int v=graph[i][0];

            if(u==src)
            {
                if(!vis[v])
                {
                    if(dfsTopological(v,vis,recPath,graph,s))
                    return true;
                }
                else
                {
                    if(recPath[v])
                    return true;
                }
            }
        }
        s.push(src);
        recPath[src]=false;
        return false;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;

        vector<bool>vis(n,false);
        vector<bool>recPath(n,false);

        stack<int>s;
        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                 if(dfsTopological(i,vis,recPath,prerequisites,s))
                return ans;
            }
           
        }

        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};