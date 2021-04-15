class Solution {
public:
    int n,m;
    int dp[201][201];
    int dfs(vector<vector<int>>& ar,int i,int j,int val)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return 0;
        if(ar[i][j]>val)
        {
            if(dp[i][j]!=-1)
                return dp[i][j];
            int a=1+dfs(ar,i-1,j,ar[i][j]);
            int b=1+dfs(ar,i+1,j,ar[i][j]);
            int c=1+dfs(ar,i,j-1,ar[i][j]);
            int d=1+dfs(ar,i,j+1,ar[i][j]);
            dp[i][j]=max(a,max(b,max(c,d)));
            return dp[i][j];
        }
        return 0;
    }
    int longestIncreasingPath(vector<vector<int>>& ar) {
        n=ar.size();
        m=ar[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,dfs(ar,i,j,-1));      
            }
        }
        
        return ans;
    }
};
