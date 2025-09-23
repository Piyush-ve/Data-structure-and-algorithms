class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax(n,0);
        vector<int>rightMax(n,0);

        for(int i=1;i<n;i++)
        {
            leftMax[i]=max(leftMax[i-1],height[i-1]);
        }

        for(int j=n-2;j>=0;j--)
        {
            rightMax[j]=max(rightMax[j+1], height[j+1]);
        }


        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(min(leftMax[i], rightMax[i])>0)
            {
                int curr=min(leftMax[i], rightMax[i])-height[i];
                if(curr>0)
                {
                    ans+=curr;
                }

            }
        }
        return ans;
    }
};