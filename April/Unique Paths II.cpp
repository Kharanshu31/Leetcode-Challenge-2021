class Solution {
public:
    int n,m;
    int dp[101][101];
    int dfs(vector<vector<int>>&ar,int i,int j)
    {
       if(i<0 || i>=n || j<0 || j>=m)
           return 0;
        if(ar[i][j]==1)
            return 0;
        if(i==n-1 && j==m-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=dfs(ar,i+1,j)+dfs(ar,i,j+1);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>&ar) {
        memset(dp,-1,sizeof(dp));
        n=ar.size();
        m=ar[0].size();
        int ans=dfs(ar,0,0);
        return ans;
    }
};
