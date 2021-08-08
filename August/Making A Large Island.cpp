class Solution {
public:
    
    int n;
    unordered_map<int,int>m;
    int k=2;
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || i>=n || j<0 || j>=n)
            return;
        
        if(grid[i][j]!=1)
            return;
        grid[i][j]=k;
        m[k]++;
        
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j);
                    ans=max(ans,m[k]);
                    k++;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    int ct=0;
                    unordered_map<int,int>vis;
                    if(i-1>=0 && !vis.count(grid[i-1][j]))
                    {
                        vis[grid[i-1][j]]++;
                        ct+=m[grid[i-1][j]];
                    }
                    
                    if(j-1>=0 && !vis.count(grid[i][j-1]))
                    {
                        vis[grid[i][j-1]]++;
                        ct+=m[grid[i][j-1]];
                    }
                    
                    if(i+1<n && !vis.count(grid[i+1][j]))
                    {
                        vis[grid[i+1][j]]++;
                        ct+=m[grid[i+1][j]];
                    }
                    
                    if(j+1<n && !vis.count(grid[i][j+1]))
                    {
                        vis[grid[i][j+1]]++;
                        ct+=m[grid[i][j+1]];
                    }
                    ans=max(ans,1+ct);
                }
            }
        }
        
        return ans;
    }
};
