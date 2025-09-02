class Solution {
public:

    bool isPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                ans+=s[i];
            }
            else if(s[i]>='A' && s[i]<='Z')
            {
                ans+=tolower(s[i]);
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                ans+=s[i];
            }
        }
        cout<<ans;
        string rev=ans;
        reverse(rev.begin(),rev.end());

        return ans==rev;
    }
};