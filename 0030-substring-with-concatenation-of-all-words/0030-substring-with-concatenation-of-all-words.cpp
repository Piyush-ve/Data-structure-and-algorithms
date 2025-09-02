class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }

        int n = words.size();
        int m = words[0].size();
        int totalLen = n * m;

        vector<int> ans;

        // check each possible starting offset (0..m-1)
        for (int start = 0; start < m; start++) {
            int i = start;
            while (i <= (int)s.size() - totalLen) {
                unordered_map<string,int> cur = mp;  // reset here
                int k = i;
                int cnt = n;

                while (cnt > 0) {
                    if (k + m > s.size()) break;
                    string a = s.substr(k, m);
                    if (cur.count(a)) {
                        cur[a]--;
                        if (cur[a] == 0) cur.erase(a);
                        k += m;
                        cnt--;
                    } else {
                        break;
                    }
                }

                if (cnt == 0) ans.push_back(i);

                i += m; // ✅ jump by word length instead of 1
            }
        }

        return ans;
    }
};
