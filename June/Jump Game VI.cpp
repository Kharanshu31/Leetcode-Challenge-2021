class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,-1e9);
        multiset<int>s;
        dp[0]=nums[0];
        s.insert(nums[0]);
        for(int i=1;i<n;i++)
        {
            int x=*s.rbegin();
            dp[i]=nums[i]+x;
            s.insert(dp[i]);
            if(i>=k)
            {
                int er=dp[i-k];
                auto it=s.find(er);
                s.erase(it);
            }
        }
        return dp[n-1];
    }
};
