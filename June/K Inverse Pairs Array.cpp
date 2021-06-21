typedef long long ll;
class Solution {
public:
    const ll mod=1e9+7;
    int kInversePairs(int n, int k) {
        if(k>(n*(n-1))/2)
            return 0;
        vector<vector<ll>>dp(n+1,vector<ll>(k+1,0));
        dp[1][0]=1;
        for(ll i=2;i<=n;i++)
        {
            ll limit=(i*(i-1))/2;
            limit=min(limit,(ll)k);
            dp[i][0]=1;
            for(ll j=1;j<=limit;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                if(j>=i)
                    dp[i][j]-=dp[i-1][j-i];
                dp[i][j]=(dp[i][j]+mod)%mod;
            }
        }
        return dp[n][k];
    }
};
