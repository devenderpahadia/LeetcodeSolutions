class Solution {
public:
    
    bool solve(vector<vector<char>>& board, string word,int i,int j,int k)
    {
        if(k==word.size())
        {
            return true;
        }
        if(i<0 || j>=board[0].size() || i>=board.size() || j<0 || board[i][j]!=word[k] )
        {
            return false;
        }
        board[i][j]='0';
        
        bool res = solve(board,word,i+1,j,k+1) || solve(board,word,i,j+1,k+1) || solve(board,word,i-1,j,k+1) || solve(board,word,i,j-1,k+1);
        
        board[i][j] = word[k];
        
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        if(word.size()==0)
            return false;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0] && solve(board,word,i,j,0))
                {
                        return true;
                }
            }
        }
        return false;
    }
};