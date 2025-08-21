class Solution {
public:
    bool search(vector<int>& nums, int target) {
                int i=0;
        int j=nums.size()-1;

        int ans=-1;

        while(i<=j)
        {
            int mid= (i+j)/2;

            if(nums[mid]==target)
            {   
                ans=mid;
                break;
            }
            // Handle duplicates
            else if (nums[i] == nums[mid] && nums[mid] == nums[j]) {
                i++;
                j--;
            }

            else if(nums[mid] >=nums[i])
            {
                if(nums[i]<=target && target<nums[mid])
                {
                    //search in left
                    j=mid-1;
                }
                else 
                {
                    //search in right
                    i=mid+1;
                }
                
            }
            else
            {
               if(nums[mid]<target && target<=nums[j])
                {
                    //search in right
                    i=mid+1;
                }
                else 
                {

                    //search in right
                    j=mid-1;
                } 
            }
        }

        return (ans==-1) ? false : true;
    }
};