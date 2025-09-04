class Solution {
public:

    vector<pair<int,int>>edges={{0,1},{1,0},{-1,0},{0,-1}};
    bool helper(int i,int j, vector<vector<char>>& board, string word, int idx, vector<vector<bool>>&vis )
    {
        if(idx==word.size()-1)
        {
            return true;
        }

        idx++;
        for(auto it:edges)
        {
            int newI=i+it.first;
            int newJ=j+it.second;

            if((newI>=0 && newI<board.size()) && (newJ>=0 && newJ<board[0].size())&& !vis[newI][newJ])
            {
                if(board[newI][newJ]==word[idx])
                {

                    vis[newI][newJ]=true;
                   if( helper(newI, newJ, board, word, idx, vis)) return true;
                    vis[newI][newJ]=false;
                    
                }

            }
        }
        return false;
        

    }
    bool exist(vector<vector<char>>& board, string word) {
        queue<pair<int,int>>q;

        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    q.push({i,j});
                }
            }
        }

        vector<vector<bool>>vis(n,vector<bool>(m,false));

        while(!q.empty())
        {
            pair<int,int>curr=q.front();
            q.pop();

            int i=curr.first;
            int j=curr.second;

            vis[i][j]=true;

            if(helper(i,j, board,word,0,vis))
            return true;

            else
            vis[i][j]=false;


        }
        return false;
    }
};