class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
            int size=nums.size();
            int begin=0;
            int end=size-1;
            int mid;
            
            while(begin<=end)
            {
                mid=(begin+end)/2;
                if(nums[mid]==target)
                return mid;

                else if(nums[mid]<target)
                {
                    begin=mid+1;
                }
                else if(nums[mid]>target)
                {
                    end=mid-1;
                }


            }
            cout<<begin<<" "<<end;
            mid=((begin+1)+end)/2;
            return mid;
    }
};