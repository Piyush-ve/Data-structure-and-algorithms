class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int>st;

        for(int it: nums)
        {
            st.insert(it);
        }

        vector<int>ans;

        for(int i: st)
        {
            ans.push_back(i);
        }
        
        sort(ans.begin(), ans.end());
        nums=ans;
        return ans.size();
    }
};