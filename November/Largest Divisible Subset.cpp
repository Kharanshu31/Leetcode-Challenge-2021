class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>pos(n,-1);
        vector<int>dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    pos[i]=j;
                }
            }
        }
        
        int mx=0;
        int id=-1;
        for(int i=0;i<n;i++)
        {
            if(mx<dp[i])
            {
                mx=dp[i];
                id=i;
            }
        }
        
        vector<int>ans;
        while(id!=-1)
        {
            ans.push_back(nums[id]);
            id=pos[id];
        }
        return ans;
        
    }
};
