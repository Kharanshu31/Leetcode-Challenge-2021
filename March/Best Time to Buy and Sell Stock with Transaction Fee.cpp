class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        dp[0][0]=-prices[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i]); //buy
            dp[i][1]=max(dp[i-1][1],dp[i][0]+prices[i]-fee); //sell
            cout<<" buy : "<<dp[i][0]<<" sell : "<<dp[i][1]<<"\n";
        }
        
        return dp[n-1][1];
    }
};
