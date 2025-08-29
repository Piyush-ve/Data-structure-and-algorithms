class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        return 0;


        int n=s.size();

        int i=0;
        int j=0;
        

        unordered_set<char>st;
        int win=0;

        while(j<n)
        {
            st.insert(s[j]);

            while((j-i+1)>st.size())
            {
               
                if(s[j]!=s[i])
                {
                    st.erase(s[i]);
                }
                i++;
            }
            win=max(j-i+1,win);
            j++;
        }

        return win;
    }
};