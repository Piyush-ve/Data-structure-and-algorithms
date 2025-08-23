class Solution {
public:

    bool find(int day, vector<int>&bloomDay, int k,int m)
    {

        int bouquets=0;
        int flowers=0;

        for(int d: bloomDay)
        {
            if(d<=day)
            {
                flowers++;
            }
            else
            {
                flowers=0;
            }

            if(k<=flowers)
            {
                bouquets++;
                flowers=0;
            }
            if(m<=bouquets)
            {
                return true;
            }
        }
        return false;

    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();


        long long mul=(long long)m* (long long)k;
        if(mul> n)
        return -1;


        int minDays=INT_MAX;
        int maxDays=INT_MIN;


        for(int i=0;i<n;i++)
        {
            minDays=min(minDays, bloomDay[i]);
            maxDays=max(maxDays, bloomDay[i]);
        }




        long long i=minDays;
        long long j=maxDays;
        long long ans=INT_MAX;

        while(i<=j)
        {
            long long mid=(i+j)/2;

            bool canFormed = find(mid, bloomDay, k, m);

            if(canFormed && mid<=ans)
            {

                ans=mid;
                j=mid-1;
                
            }
            else
            {
                i=mid+1;
            }
        }

        return (int)ans;
    }
};