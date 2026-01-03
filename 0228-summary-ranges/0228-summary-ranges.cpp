class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        if(nums.size()==0)
        {
            return ans;
        }
        if(nums.size()==1)
        {
            ans.push_back(to_string(nums[0]));
            return ans;
        }

        int st= nums[0];
        int end=nums[0];

        int n=nums.size();
        for(int i=1;i<n;i++){
            if((nums[i]-end)>1)
            {
                if(st==end)
                {
                    string str=to_string(st);
                    ans.push_back(str);
                    st=nums[i];
                    end=nums[i];
                }
                else{
                        string str= to_string(st) ;
                        str+= "->" ;
                        str+= to_string(end);
                    ans.push_back(str);
                    st=nums[i];
                    end=nums[i];
                }
            }
            else
            {
                end=nums[i];
            }
        }

        if(st==end)
        {
            string str= to_string(st);
            ans.push_back(str);
            
        }
        else{
            string str= to_string(st) ;
            str+= "->" ;
            str+= to_string(end);
            ans.push_back(str);
            
        }

        return ans;
    }
};