class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];

        int i=0;
        int j=nums.size()-1;

        while(i<=j)
        {
            int mid=(i+j)/2;
            if((mid!=j) && (nums[mid]==nums[mid+1]))
            {
                cout<<"first if : ";
                if(mid%2==0)
                {
                    cout<<"nested if"<<endl;
                    //then it will search in right
                    i=mid+1;
                }
                else 
                {
                    cout<<"nested else"<<endl;
                    //it will search in left
                    j=mid-1;
                }
            }

            else if((mid != 0) && (nums[mid]==nums[mid-1]) )
            { 
                cout<<"first else if : ";
                if(mid%2!=0)
                {

                    cout<<"nested if"<<endl;
                    //then it will search in right
                    i=mid+1;
                }
                else 
                {
                    cout<<"nested else"<<endl;
                    //it will search in left
                    j=mid-1;
                }
            }

            else if(mid == i && mid ==j )
            {
                cout<<"next else if: ";
                return nums[mid];
            }

            else
            {
                return nums[mid];
            }
        }

        return -1;


    }
};