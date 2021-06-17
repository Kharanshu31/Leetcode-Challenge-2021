class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size();
        vector<int>dp(n,0);
        int ans=0;
        int prev=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<left)
            {
                if(i)
                    dp[i]=dp[i-1];
            }
            else if(nums[i]>=left && nums[i]<=right)
            {
                //cout<<" prev : "<<prev<<"\n";
                dp[i]=i-prev;
            }
            else
            {
                prev=i;
            }
            //cout<<dp[i]<<"  ";
            ans+=dp[i];
        }
        return ans;
    }
};
