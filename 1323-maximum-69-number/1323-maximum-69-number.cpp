class Solution {
public:
    int findd(int n)
    {
        int idx=INT_MIN;
        int i=0;
        while(n!=0)
        {
            int r=n%10;
            n=n/10;
            if(r==6){
                idx=i;
            }
            i++;
        }
        return idx;
    }
    int maximum69Number (int num) {
        int idx=findd(num);

        if(idx==INT_MIN)
        {
            return num;
        }

        else{
            num+=3*(pow(10,idx));
        }

        return num;
    }
};