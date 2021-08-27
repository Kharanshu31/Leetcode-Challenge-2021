#define n 9
class Solution {
public:
    
    bool checkrow(vector<vector<char>>& grid,int row,int num)
    {
        for(int i=0;i<n;i++)
        {
            if(grid[row][i]-'0'==num)
                return false;
        }
        return true;
    }
    
    bool checkcol(vector<vector<char>>& grid,int col,int num)
    {
        for(int i=0;i<n;i++)
        {
            if(grid[i][col]-'0'==num)
                return false;
        }
        return true;
    }
    
    bool checksub(vector<vector<char>>& grid,int i,int j,int num)
    {
        int startx=i-i%3;
        int starty=j-j%3;
        for(int k=startx;k<startx+3;k++)
        {
            for(int g=starty;g<starty+3;g++)
            {
                if(grid[k][g]-'0'==num)
                    return false;
            }
        }
        return true;
    }
    
    bool check(vector<vector<char>>& grid)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='.')
                    return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& grid,int i,int j)
    {
        if(check(grid))
        {
            return true;
        }
        
        if(j==n)
        {
            return solve(grid,i+1,0);
        }
        
        if(grid[i][j]!='.')
            return solve(grid,i,j+1);
        
        for(int num=1;num<=n;num++)
        {
            if(checkrow(grid,i,num)&&checkcol(grid,j,num)&&checksub(grid,i,j,num))
            {
                grid[i][j]=num+'0';
                if(solve(grid,i,j+1))
                    return true;
                grid[i][j]='.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& grid) {
        solve(grid,0,0);
    }
};
