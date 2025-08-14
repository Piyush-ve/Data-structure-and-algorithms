class Solution {
public:
    string largestGoodInteger(string num) {
       if(num.size()<3)
       {
        return "";
       }

       string ans="";

       int n=num.size();

       for(int i=0;i<=n-3;i++)
       {
            char ch=num[i];
            bool similar=true;
            string curr="";

            for(int j=i;j<i+3;j++)
            {
                if(ch!=num[j])
                {
                    similar=false;
                    break;
                }
                curr+=num[j];
            }
            if(similar)
            {
                if(ans.size()==0)
                {
                    ans=curr;
                }
                else
                {
                    int an=stoi(ans);
                    int cur=stoi(curr);

                    if(an<cur)
                    {
                        ans=curr;
                    }
                }
            }
       }

       return ans;
    }
};