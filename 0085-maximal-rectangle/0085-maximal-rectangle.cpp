class Solution {
public:
    vector<int>getNSL(vector<int>&height)
    {
        int n=height.size();
        stack<int>st;

        vector<int>NSL(n,-1);
        //st.push(0);

        for(int i=0;i<n;i++)
        {
            if(st.empty())
                NSL[i]=-1;
            else
            {
                while(!st.empty() && height[st.top()]>=height[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    NSL[i]=-1;
                }
                else
                {
                    NSL[i]=st.top();
                }
            }
            st.push(i);
        }
        return NSL;

    }
    vector<int>getNSR(vector<int>&height)
    {
        int n=height.size();
        stack<int>st;

        vector<int>NSR(n,-1);
        //st.push(0);

        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
                NSR[i]=n;
            else
            {
                while(!st.empty() && height[st.top()]>=height[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    NSR[i]=n;
                }
                else
                {
                    NSR[i]=st.top();
                }
            }
            st.push(i);
        }
        return NSR;
    }
    int maxArea(vector<int>&height)
    {
        vector<int>NSL=getNSL(height);
        vector<int>NSR=getNSR(height);

        int n=height.size();

        vector<int>width(n);
        for(int i=0;i<n;i++)
        {
            width[i]=NSR[i]-NSL[i]-1;
        }

        int area=-1;

        for(int i=0;i<n;i++)
        {
            area=max(area,width[i]*height[i]);
        }

        return area;

    } 
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int>height(n);
        for(int i=0;i<n;i++)
        {
            height[i]=(matrix[0][i]=='1')? 1:0;
        }

        int Area= maxArea(height);

        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    height[j]=height[j]+1;
                }
                else
                {
                    height[j]=0;
                }
            }
            Area=max(Area,maxArea(height));

        }

        return Area;


    }
};