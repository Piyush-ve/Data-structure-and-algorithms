class Solution {
public:
     int n;

     bool checkPall(int idx, int end, string s)
     {
        string cur=s.substr(idx,end-idx+1);
        string re=cur;
        reverse(re.begin(),re.end());
        if(cur==re)
        return true;

        return false;
     }

    void helper(int idx, string &s ,vector<string>&a, vector<vector<string>>&ans)
    {
        if(idx==n)
        {
            ans.push_back(a);
        }

        for(int i=idx;i<n;i++)
        {
            if(checkPall(idx,i,s))
            {
                a.push_back(s.substr(idx,i-idx+1));
                helper(i+1,s,a,ans);
                a.pop_back();
            }
        }

        return ;
    }
    
    vector<vector<string>> partition(string s) {
        
         n=s.size();

         vector<vector<string>>ans;
         vector<string>a;

         helper(0,s,a,ans);

        return ans;
    }
};