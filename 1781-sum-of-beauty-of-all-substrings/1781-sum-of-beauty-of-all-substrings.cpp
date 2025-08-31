class Solution {
public:
 
    int beautySum(string s) {

        int n=s.size();
        int ans=0;

        

        for(int i=0;i<n;i++)
        {
           
           vector<int>freq(26,0);

           for(int j=i;j<n;j++)
           {
                 int Max=0;
            int Min=INT_MAX;
                freq[s[j]-'a']++;

                for(auto it: freq)
                {
                    if(it>0)
                    {
                        Max=max(Max,it);
                        Min=min(Min, it);
                    }
                    
                }

                ans+=Max-Min;

           }
        }
        return ans;
    }
};