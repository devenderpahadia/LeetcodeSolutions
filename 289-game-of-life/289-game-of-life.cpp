class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>res(m,vector<int>(n));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                int ctr=0;
                if(i>0 && j> 0 && board[i-1][j-1]==1)
                {
                    ctr++;
                }
                if(i>0 && board[i-1][j]==1)
                {
                    ctr++;
                }
                if(i>0 && j<n-1 && board[i-1][j+1]==1)
                {
                    ctr++;
                }
                if(j<n-1 && board[i][j+1]==1)
                {
                    ctr++;
                }
                if(i<m-1 && j<n-1 && board[i+1][j+1]==1)
                {
                    ctr++;
                }
                if(i<m-1 && board[i+1][j]==1)
                {
                    ctr++;
                }
                if(i<m-1 && j>0 && board[i+1][j-1]==1)
                {
                    ctr++;
                }
                if(j>0 && board[i][j-1]==1)
                {
                    ctr++;
                }
                if(board[i][j]==1)
                {
                    if(ctr<2)
                        res[i][j] = 0;
                    else if(ctr==2 || ctr==3)
                        res[i][j] = 1;
                    else if(ctr>3)
                        res[i][j] = 0;
                }
                else
                {
                    if(ctr==3)
                        res[i][j]=1;
                }
            }
        }
        board = res;
    }
};