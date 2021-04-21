class Solution {
public:
    int dp[1002];
    int solve(vector<int>&ar,int target)
    {
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        if(dp[target]!=-1)
            return dp[target];
        int res=0;
        for(int i=0;i<ar.size();i++)
        {
            res+=solve(ar,target-ar[i]);
        }
        return dp[target]=res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(nums,target);
        return ans;
    }
};
