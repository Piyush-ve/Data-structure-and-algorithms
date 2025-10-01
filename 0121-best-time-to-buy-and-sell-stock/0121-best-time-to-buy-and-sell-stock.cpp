class Solution {
public:
    int maxProfit(vector<int>& prices) {
     
        int Min=prices[0];
        int maxProfit=0;

        for(int i=1;i<prices.size();i++)
        {
            int cost=prices[i]-Min;
            maxProfit=max(cost,maxProfit);
            Min=min(prices[i],Min);
        }
        return maxProfit;
    }
};