
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int Max=INT_MIN;

        int prefix=1;
        int suffix=1;

        for(int i=0;i<n;i++)
        {
            prefix*=nums[i];
            Max=max(Max,prefix);
        
            if(prefix==0)
            {
                prefix=1;
              
            }

            suffix*=nums[n-(i+1)];
            Max=max(Max,suffix);
            

            if(suffix==0)
            {
                suffix=1;   
            }
        }
        return Max;
    }
};




/*

time Complexity:- o(n^2)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int Max=INT_MIN;

        int prefix=1;
        int suffix=1;
        
      //  vector<vector<int>>dp(n,vector<int>(n,INT_MIN));

        for(int i=0;i<n;i++)
        {
            int cur=1;
            for(int j=i;j<n;j++)
            {
                cur*=nums[j];
             //   dp[i][j]=cur;
                Max=max(Max,cur);
            }
        }
        return Max;
    }
};

*/