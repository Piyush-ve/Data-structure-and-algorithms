class Solution {
public:
    bool helper(string s, int i, int count, int n, vector<vector<int>>&dp)
    {
        if(i==n )
        return count==0;
        
        if(count<0)
        return false;

        if(dp[i][count]!=-1)
        {
            return dp[i][count];
        }

        bool ans=false;

        if(s[i]=='(')
        {
            ans=helper(s, i+1, count+1, n,dp);
        }
        else if(s[i]==')')
        {
            ans= helper(s, i+1,count-1, n,dp);
        }
        else if(s[i]=='*')
        {
            bool option1= helper(s, i+1, count+1, n,dp); // * = (
            bool option2= helper(s, i+1, count-1, n,dp); // * = )
            bool option3= helper(s, i+1, count, n, dp); // * = emmpty

            ans= option1|| option2 ||option3;
        }

        return dp[i][count]=ans;
    }
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return helper(s,0,0,s.size(),dp);
    }
};

/*class Solution {
public:
    bool checkValidString(string s) {
        
        stack<char>st;
        int n=s.size();
       // int asterrick=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*' || s[i]=='(')
            {
                st.push(s[i]);
            }
            else if(s[i]==')' && st.empty())
            {
                return false;
            }
            else if(s[i]==')')
            {
                if(st.top()=='(')
                {
                    st.pop();
                }
                else if(st.top()=='*')
                {
                    int asterick=0;
                    while(!st.empty() && st.top()=='*')
                    {
                        asterick++;
                        st.pop();
                    }
                    if(!st.empty() && st.top()=='(')
                    {
                        st.pop();

                        while(asterick>0)
                        {
                            st.push('*');
                            asterick--;
                        }
                    }
                    else if(st.empty() || st.top()!='(')
                    {
                        asterick--;
                        while(asterick!=0)
                        {
                            st.push('*');
                            asterick--;
                        }

                    }
                }
                else 
                {
                   return false; 
                }
            }
        }
       cout<<st.size();
       if(st.size()>0)
       {
            cout<<st.top();
       }
        while(!st.empty() && st.top()!='(')
        {
             int asterick=0;
            while(!st.empty() && st.top()=='*')
            {
                asterick++;
                st.pop();
            }
            if(!st.empty() && asterick>0)
            {
                st.pop();
                asterick--;

                while(asterick>0)
                {
                    st.push('*');
                    asterick--;
                }
            }
        }

        return st.size()==0?true:false;
    }
};

*/