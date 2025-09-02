class Solution {
public:
    int maxArea(vector<int>& height) {
        int water=0;

        int n=height.size();
        int i=0;
        int j=n-1;

        while(i<j)
        {
            int curr=min(height[i],height[j])*(j-i);
           // cout<<curr<<endl;

            water=max(water,curr);
            if(height[i]>height[j])
            {
                j--;
            }
            else 
            {
                i++;
            }
            
        }


        return water;
    }
};