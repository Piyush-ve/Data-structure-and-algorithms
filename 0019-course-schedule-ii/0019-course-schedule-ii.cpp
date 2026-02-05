class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
                unordered_map<int,vector<int>>mp;

        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            mp[v].push_back(u);
        }

        vector<int>indeg(numCourses,0);

//calculate indeg
        for(auto it:mp)
        {
            for(auto v:it.second)
            {
                indeg[v]++;
            }
        }

      queue<int>q;

      for(int i=0;i<numCourses;i++)
      {
        if(indeg[i]==0)
        {
            q.push(i);
        }
      }  
    vector<bool>vis(numCourses,false);
    vector<int> ans;
      while(!q.empty())
      {
        int curr= q.front();
        ans.push_back(curr);
        q.pop();

        vis[curr]=true;

        for(int v:mp[curr])
        {
            indeg[v]--;
            if(indeg[v]==0)
            {
                q.push(v);
            }
        }

      }

        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==false)
            {
                return {};
            }
        }

        return ans;

    }
};