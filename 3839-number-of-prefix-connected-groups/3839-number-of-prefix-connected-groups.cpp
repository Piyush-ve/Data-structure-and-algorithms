class Solution {
public:

    int prefixConnected(vector<string>& words, int k) {
          vector<string> temp = words;
        
        unordered_map<string, int> mp;
        
        for(string &word : temp) {
            if(word.length() >= k) {
                string prefix = word.substr(0, k);
                mp[prefix]++;
            }
        }
        
        int groups = 0;
        
        for(auto &it : mp) {
            if(it.second >= 2) {
                groups++;
            }
        }
        return groups;
    }
};