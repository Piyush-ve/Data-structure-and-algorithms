class Solution {
    void ans(List<List<String>> ans_board,List<List<String>>board)
    {
        List<String>vec= new ArrayList<>();

        int n=board.size();
        for(int i=0;i<n;i++)
        {
            String a="";
            for(int j=0;j<n;j++)
            {
                a+=board.get(i).get(j);
            }
            vec.add(a);
        }

        ans_board.add(vec);
    }
    public boolean safe(List<List<String>>board, int r, int c)
    {
        if(r==0)
        {
            return true;
        }

        // column

        for(int i=0;i<r;i++)
        {
            if(board.get(i).get(c).equals("Q"))
            return false;
        }

        //upper left 
        for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--)
            {
                if(board.get(i).get(j).equals("Q"))
                return false;
            }
        



        int n=board.size();
        //upper right

        for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++)
            {
                if(board.get(i).get(j).equals("Q"))
                return false;
            
        }

        return true;
    }
    public void nQueens(List<List<String>> ans_board,List<List<String>>board, int r, int n)
    {
        if(r==n)
        {
            ans(ans_board, board);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(safe(board, r, i))
            {
               board.get(r).set(i, "Q");
                nQueens(ans_board, board, r+1, n);
                 board.get(r).set(i, ".");
            }
        }
    }
    public void helper(List<List<String>>ans_board, int n)
    {
        List<List<String>>board=new ArrayList<>();

        for (int i = 0; i < n; i++) {
            List<String> row = new ArrayList<>(Collections.nCopies(n, "."));
            board.add(row);
        }
        nQueens(ans_board, board, 0, n);
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>>ans_board=new ArrayList<>();

        helper(ans_board,n);
        return ans_board;
    }
}