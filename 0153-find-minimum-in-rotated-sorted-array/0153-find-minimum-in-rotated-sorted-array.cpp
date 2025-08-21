class Solution {
public:
    int findPivot(int st,int end,vector<int>& nums)
    {
        while(st<end)
        {
           int mid=(st+end)/2;

            if(nums[mid]>nums[end])
            {
                st=mid+1;
            }
            else
            {
                end=mid;
            }
           
        }
        return st;
    }
    int findMin(vector<int>& nums) {
      int st=0;
      int end=nums.size()-1;
      int pivot= findPivot(st,end,nums);
      return nums[pivot]; 

      
    }
};