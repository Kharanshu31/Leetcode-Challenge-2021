class Solution {
public:
    const int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& ar) {
        int n=ar.size();
        sort(ar.begin(),ar.end());
        map<int,int>m;
        for(int i=0;i<n;i++)
            m[ar[i]]=i;
        vector<int>dp(n,1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(m.count(ar[i]*ar[j]))
                {
                    int pos=m[ar[i]*ar[j]];
                    if(ar[i]!=ar[j])
                    {
                        dp[pos]=dp[i]*dp[j]+2;
                        dp[pos]%=mod;
                    }
                    else
                    {
                        dp[pos]=dp[i]*dp[j]+1;
                        dp[pos]%=mod;
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            cout<<dp[i]<<"\n";
            ans+=dp[i];
            ans%=mod;
        }
        
        return ans;
    }
};
