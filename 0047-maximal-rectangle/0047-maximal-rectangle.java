class Solution {
    private int [] getNSL(int[] height)
    {
        int n= height.length;
        int[] NSL= new int[n];
        Stack<Integer>st = new Stack<>();

        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                NSL[i]=-1;
            }
            else
            {
                while(!st.empty() && height[st.peek()]>= height[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    NSL[i]=-1;
                }
                else
                {
                    NSL[i]=st.peek();
                }
                
            }
            st.push(i);
        }
        return NSL;
    }

    private int [] getNSR(int[] height)
    {
        int n=height.length;
        int[] NSR= new int[n];
        Stack<Integer>st = new Stack<>();

        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                NSR[i]=n;
            }
            else
            {
                while(!st.empty() && height[st.peek()]>= height[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    NSR[i]=n;
                }
                else
                {
                    NSR[i]=st.peek();
                }
                
            }
            st.push(i);
        }
        return NSR;
    }
    public int getMaxArea(int []height)
    {
        int n=height.length;

        int[] NSL=getNSL(height);
        int[] NSR=getNSR(height);

        int[]width = new int[n];

        for(int i=0;i<n;i++)
        {
            width[i]=NSR[i]-NSL[i]-1;
        }
        int area=-1;

        for(int i=0;i<n;i++)
        {
            area=Math.max(area,height[i]*width[i]);
        }

        return area;
    }
    public int maximalRectangle(char[][] matrix) {
        int m=matrix.length;
        int n=matrix[0].length;

        int height[]= new int[n];

        for(int i=0;i<n;i++)
        {
            height[i]=(matrix[0][i]=='1') ?1: 0;
        }

        int maxArea=getMaxArea(height);

        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')
                {
                    height[j]=0;
                }
                else
                {
                    height[j]=height[j]+1;
                }
            }
            maxArea=Math.max(getMaxArea(height),maxArea);
        }

        return maxArea;
    }
}