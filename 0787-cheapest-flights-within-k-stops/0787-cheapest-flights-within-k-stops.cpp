class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int price=flights[i][2];

            mp[u].push_back({v,price});
        }

        priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>>pq;//price,k,des
        pq.push({0,-1,src});

         // Track best known (node, stops) cost to prune bad paths
        vector<int> minStops(n, INT_MAX);

        while(!pq.empty())
        {
            vector<int>curr=pq.top();
            pq.pop();
            int price=curr[0];
            int stops=curr[1];
            int U=curr[2];

            // Destination reached
            if (U == dst) return price;

            // If already visited with fewer stops, skip
            if (stops >= minStops[U] || stops >= k) continue;
            minStops[U] = stops;

            for(auto it: mp[U])
            {
                int V=it.first;
                int c=it.second+price;
                int stop=stops+1;

                if(stop<=k)
                {
                    pq.push({c,stop,V});
                }
            }

           
        }
   
            return -1;

        

    }
};