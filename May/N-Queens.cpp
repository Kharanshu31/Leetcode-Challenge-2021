class Solution {
public:
    vector<vector<string>>ans;
    int n;
    bool check(vector<string>board,int row,int col)
    {
        for(int i=0;i<n;i++)
            if(board[i][col]=='Q')
                return false;
        
        int i=row;
        int j=col;
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        
        i=row,j=col;
        while(i>=0 && j<n)
        {
            if(board[i][j]=='Q')
                return false;
            i--;
            j++;
        }
        
        return true;
        
    }
    
    void dfs(vector<string>board,int row)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(check(board,row,i))
            {
                board[row][i]='Q';
                dfs(board,row+1);
                board[row][i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int m) {
        n=m;
        vector<string>board(n,string(n,'.'));
        dfs(board,0);
        return ans;
    }
};
