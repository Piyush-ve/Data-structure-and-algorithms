class Solution {
public:
    int maxDepth(string s) {
        int Max=0;
        int curr=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                curr++;
                Max=max(Max,curr);
            }
            else if(s[i]==')')
            {
                curr--;
            }
        }
        return Max;
    }
};