class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto it: mp)
        {
            int f=it.second;
            int el=it.first;

            pq.push(make_pair(f,el));
        }
        vector<int>ans;

        while(k!=0)
        {

            ans.push_back(pq.top().second);
            k--;
            pq.pop();
        }
        return ans;
    }
};