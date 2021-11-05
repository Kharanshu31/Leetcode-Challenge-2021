class Solution {
public:
    
    int ans=0;
    
    void dfs(vector<vector<int>>& grid,int i,int j,int ssf,int tot)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1)
            return;
        
        if(grid[i][j]==2)
        {
            if(ssf==tot)
                ++ans;
            
            return;
        }
        
        grid[i][j]=-1;
        
        dfs(grid,i+1,j,ssf+1,tot);
        dfs(grid,i-1,j,ssf+1,tot);
        dfs(grid,i,j+1,ssf+1,tot);
        dfs(grid,i,j-1,ssf+1,tot);
        
        grid[i][j]=0;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int tot=0;
        int x=0;
        int y=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    x=i;
                    y=j;
                }
                if(grid[i][j]!=-1)
                {
                    ++tot;
                }
            }
        }
        
        dfs(grid,x,y,1,tot);
        
        return ans;
    }
};
