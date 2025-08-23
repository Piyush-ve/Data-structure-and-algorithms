class Solution {
public:
    int calculateThreshold(int divi, vector<int>& nums)
    {
        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            int c=ceil(double(nums[i])/double(divi));
            if(c==0)
            {
                c=1;
            }

            ans+=c;
        }

        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int minDivisor= 1;
        int maxDivisor= 1;

        for(int i=0;i<nums.size();i++)
        {
            maxDivisor=max(maxDivisor,nums[i]);
        }


        int i=1;
        int j=maxDivisor;
        int ans=maxDivisor;


        while(i<=j)
        {
            int mid=(i+j)/2;

            int curr=calculateThreshold(mid,nums);

            if(curr<=threshold)
            {
               // cout<<mid<<" : "<<curr<<endl;
                ans=mid;
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