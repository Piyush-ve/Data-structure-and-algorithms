class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //calculate leftMin
        int ans=0;
        int n=prices.size();

        vector<int>leftMin(n, 0);
        leftMin[0]=INT_MAX;

        for(int i=1;i<n;i++)
        {
            leftMin[i]=min(leftMin[i-1],prices[i-1]);
        }

        for(int i=1;i<n;i++)
        {
            if(prices[i]>leftMin[i])
            {
                ans=max(ans, prices[i]-leftMin[i]);
            }
        }
        return ans;
    }
};