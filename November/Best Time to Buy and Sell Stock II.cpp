class Solution {
public:
    
    int n;
    static const int nmax=3e4+1;
    int dp[nmax][2];
    int solve(vector<int>& prices,bool own,int i)
    {
        if(i==n)
            return 0;
        if(dp[i][own]!=-1)
            return dp[i][own];
        if(own)
        {
            int option1=prices[i]+solve(prices,!own,i+1);
            int option2=solve(prices,own,i+1);
            return dp[i][own]=max(option1,option2);
        }
        else
        {
            int option1=-prices[i]+solve(prices,!own,i+1);
            int option2=solve(prices,own,i+1);
            return dp[i][own]=max(option1,option2);
        }
        
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        n=prices.size();
        return solve(prices,false,0);
    }
};
