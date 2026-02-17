class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        int flag=0;
        for(int i=n;i>=0;i--)
        {
            if(digits[i]==9)
            {
                flag=1;
                digits[i]=0;
            }
            else if(digits[i]!=9)
            {
                flag=0;
                digits[i]=digits[i]+1;
                break;
            }
        }
        if(flag==1)
        {
            digits[0]=1;
            digits.push_back(0);

        }
        
        return digits;
    }
};