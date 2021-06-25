typedef long long ll;
class Solution {
public:
    vector<vector<int>>dir={{-1, 0},{1,0},{0,1},{0,-1}};
    const ll mod=1e9+7;
    ll dp[51][51][51];
    ll solve(int i,int j,int n,int m,int mx)
    {
        if(mx<0)
            return 0;
        if(i<0 || j<0 || i>=n || j>=m)
            return 1;
        if(dp[i][j][mx]!=-1)
            return dp[i][j][mx];
        ll ans=0;
        for(int k=0;k<4;k++)
        {
            ans+=solve(i+dir[k][0],j+dir[k][1],n,m,mx-1);
            ans%=mod;
        }
        return dp[i][j][mx]=ans%mod;
    }
    
    int findPaths(int m, int n, int mx, int sr, int sc) {
        memset(dp,-1,sizeof(dp));
        return solve(sr,sc,m,n,mx);  
    }
};
