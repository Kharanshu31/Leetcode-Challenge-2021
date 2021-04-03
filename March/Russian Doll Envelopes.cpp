class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int,int>>p;
        int n=envelopes.size();
        for(auto e:envelopes)
            p.push_back({e[0],e[1]});
        sort(p.begin(),p.end());
        int ans=0;
        vector<int>dp(n+1,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(p[i].first>p[j].first && p[i].second>p[j].second)
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        
        for(auto i:dp)
        {
            cout<<i<<" ";
            ans=max(ans,i);
        }
        return ans;
    }
};
