class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        int i=1;
        int ans=0;
        while(i<=n)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                ans=max(ans,dp[i][j]);
            }
            i++;
        }
        
        return ans;
    }
};
