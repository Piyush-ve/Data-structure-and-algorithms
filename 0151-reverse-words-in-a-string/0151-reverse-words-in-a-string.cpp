class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        reverse(s.begin(),s.end());
      
        for(int i=0;i<s.size();i++)
        {
            string a="";
            int j=i;
            while(j<s.size()&&s[j]!=' ')
            {
                a+=s[j];
                j++;
            }
            i=j;
            reverse(a.begin(),a.end());
            
            if(a.size()>0)
            {
                
                ans+=" ";
                ans+=a;
            } 
        }
        return ans.substr(1);

    }
};