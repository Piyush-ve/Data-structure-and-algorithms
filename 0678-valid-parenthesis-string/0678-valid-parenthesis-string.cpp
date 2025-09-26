class Solution {
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