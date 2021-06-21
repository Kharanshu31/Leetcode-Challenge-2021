class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int n,m;
    // void dfs(vector<vector<int>>& grid,int i,int j,int mx,vector<vector<bool>>&vis)
    // {
    //     if(i<0 || j<0 || i>=n || j>=m)
    //         return;
    //     if(i==n-1 && j==m-1)
    //     {
    //         cout<<" mx : "<<mx<<"\n";
    //         ans=min(ans,max(mx,grid[i][j]));
    //     }
    //     vis[i][j]=true;
    //     for(auto it:dir)
    //     {
    //         int x=i+it[0];
    //         int y=j+it[1];
    //         if(x>=0 && x<n && y<m && y>=0 && !vis[x][y])
    //         {
    //             dfs(grid,x,y,max(mx,grid[x][y]),vis);
    //         }
    //     }
    // }
    
    bool check(vector<vector<int>>& grid,int mid)
    {
        if(mid<grid[0][0])
            return false;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=true;
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            if(i==n-1 && j==m-1)
            {
                return true;
            }
            for(auto it:dir)
            {
                int x=i+it[0];
                int y=j+it[1];
                if(x>=0 && x<n && y<m && y>=0 && !vis[x][y] && grid[x][y]<=mid)
                {
                    vis[x][y]=true;
                    q.push({x,y});
                }
            }
        }
        
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int low=0;
        int high=n*n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(grid,mid))
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};
