class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>pq;

        unordered_map<char,int>mp;

        string ans="";

        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }

        for(auto it: mp)
        {
            pair<int,char>p=make_pair(it.second,it.first);
            pq.push(p);
        }

        while(!pq.empty())
        {
             pair<int,char>p=pq.top();
             pq.pop();

             int f=p.first;

             while(f!=0)
             {
                ans+=p.second;
                f--;
             }
        }

       // reverse(ans.begin(),ans.end());
        return ans;

        


    }
};