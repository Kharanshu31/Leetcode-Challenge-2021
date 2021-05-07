class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,INT_MAX-1);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            int x=i+nums[i];
            if(x>=n)
                x=n-1;
            for(int j=i+1;j<=x;j++)
            {
                dp[j]=min(dp[j],dp[i]+1);
            }
        }
        
        for(int i=0;i<n;i++)
            cout<<dp[i]<<" ";
        return dp[n-1];
    }
};
