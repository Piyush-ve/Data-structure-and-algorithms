class Solution {
public:
int findpivot(vector<int>nums)
{
    int i=0;
    int j= nums.size()-1;

    while(i<j)
    {
        int mid=(i+j)/2;
        
        if(nums[mid]>nums[j])
        {
            i=mid+1;
        }
        else 
        {
            j=mid;
        }
    }
    return i;
}
    int findMin(vector<int>& nums) {
       //
        cout<<findpivot(nums);

        return nums[findpivot(nums)];
    }
};