class Solution {
public:
//APPROACH 1
/*
    bool is_safe(vector<vector<char>>& arr,int r,int c,char value)
    {
        //for rows
        for(int i=0;i<9;i++)
        {
            if(arr[i][c]==value)
            return false;
        }

        //for col
        for(int i=0;i<9;i++)
        {
            if(arr[r][i]==value)
            return false;
        }

        //for 3* 3 grid

        int startRow= r-(r%3);
        int startCol=c-(c%3);

        for(int i=startRow;i<startRow+3;i++)
        {
            for(int j=startCol;j<startCol+3;j++)
            {
                if(arr[i][j]==value)
                {
                    return false;
                }
                
            }
            
        }

        

        return true;
    }

    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    char val=board[i][j];
                    board[i][j]='.';

                    if(!is_safe(board,i,j,val))
                    return false;
                    board[i][j]=val;

                }
            }
        }
        return true;

      
    }
    */

    //APPROACH 2 BY USING SET

    bool validBox(vector<vector<char>>& board,int sr,int er,int sc, int ec)
    {
        //for 3*3 grid 

        unordered_set<char>s1;

         for(int i=sr;i<=er;i++)
        {

            for(int j=sc;j<=ec;j++)
            {
                if(board[i][j]=='.')
                continue;

                if(s1.find(board[i][j])!=s1.end())
                return false;

                s1.insert(board[i][j]);
            }
        }
        return true;


    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // for rows
        for(int i=0;i<9;i++)
        {
            unordered_set<char>s1;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                continue;

                if(s1.find(board[i][j])!=s1.end())
                return false;

                s1.insert(board[i][j]);
            }
        }

        //for cols
        for(int i=0;i<9;i++)
        {
            unordered_set<char>s1;
            for(int j=0;j<9;j++)
            {
                if(board[j][i]=='.')
                continue;

                if(s1.find(board[j][i])!=s1.end())
                return false;

                s1.insert(board[j][i]);
            }
        }

        //for 3* 3 grid

        for(int sr=0;sr<9;sr+=3)
        {
            int er=sr+2;
            for(int sc=0;sc<9;sc+=3)
            {
                int ec=sc+2;
                if(!validBox(board,sr,er,sc,ec))
                return false;
            }
        }
        return true;

      
    }

};