class Solution {
public:
    int myAtoi(string s) {
        string ans="";
        long long num=0;
        bool isPos=true;
        bool signOccur=false;
        for(int i=0;i<s.size();i++)
        {
            if(signOccur && !isdigit(s[i]))
            {
                break;
            }
            else if(ans.size()==0 && s[i]==' ')
            {
                //no problem
            }
            else if(ans.size()==0 && s[i]=='+')
            {
                //no problem
                signOccur=true;
            }
            else if(ans.size()==0 && s[i]=='-')
            {
                isPos=false;
                 signOccur=true;
            }

            else if(ans.size()!=0 && (s[i]==' ' || !(s[i]>='0' && s[i]<='9')))
            {
                break;
            }

            else if(!(s[i]>='0' && s[i]<='9') && (s[i]!='+' || s[i]!='-'))
            {
                break;
            }
            else
            {
                ans+=s[i];
                num=num*10+(s[i]-'0');
                 if(num>INT_MAX && isPos==false)
                {
                    return INT_MIN;
                }
                if(num>INT_MAX && isPos==true)
                {
                    return INT_MAX;
                }
            }
        }

        if(!isPos)
        {
            num=num*-1;
        }
        
       
        return num;
    }
};