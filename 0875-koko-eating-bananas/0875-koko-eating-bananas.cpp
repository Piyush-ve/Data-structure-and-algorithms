class Solution {
public:
    long long  calculate(int a, vector<int>&piles)
    {


        long long  c=0;
        for(int i=0;i<piles.size();i++)
        {
            
            int t=ceil((double)piles[i]/(double)a);
           

            if(t==0)
            {
                t=1;
            }

            
            c+=t;
        }
        return c;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed=1;
        int MaxSpeed=1;


        for(int i=0;i<piles.size();i++)
        {
            MaxSpeed=max(MaxSpeed, piles[i]);
        }

 

        int i=0;
        int j=MaxSpeed-1;

        int ans=INT_MAX;


        while(i<=j)
        {
            int mid=(i+j)/2;
            int ele= mid+1;
            
        //    cout<<nums[mid]<<" : "<<calculate(nums[mid],piles)<<endl;

            if(calculate(ele, piles)<=h)
            {
                ans=min(ans,ele);
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        return ans;
  
    }
};