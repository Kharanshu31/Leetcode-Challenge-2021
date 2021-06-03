class Solution {
public:
    int n,m;
    int ans=0;
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || j<0 || i==n || j==m)
            return;
        if(grid[i][j]==0)
            return;
        
        grid[i][j]=0;
        ans++;
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans=0;
                    dfs(grid,i,j);
                    cout<<" i : "<<i<<" j : "<<j<<" ct : "<<ans<<"\n";
                    res=max(res,ans);
                }
            }
        }
        return res;
    }
};
