class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0;
        int ans=0;


        for(int i=0;i<bank.size();i++)
        {
            string str=bank[i];
            int curr=0;
            for(auto it: str)
            {
                if(it=='1')
                {
                    curr++;
                }
            }
            ans+=(prev*curr);
            if(curr!=0)
                prev=curr;
        }
        return ans;
    }

};