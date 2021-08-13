class Solution {
public:
    
    int n;
    int vis[2001];
    int solve(vector<vector<bool> >&dp,int i)
    {
        //cout<<" i : "<<i<<"\n";
        if(i>=n)
            return 0;
        
        if(vis[i]!=-1)
            return vis[i];
        int ans=1e6;
        for(int j=i;j<n;j++)
        {
            if(dp[i][j])
            {
               // cout<<" i : "<<i<<" j : "<<j<<"\n";
                ans=min(ans,solve(dp,j+1)+1);
            }
        }
        return vis[i]=ans;
    }
    
    int minCut(string s) {
        n=s.length();
        memset(vis,-1,sizeof(vis));
        vector<vector<bool> >dp(n+1,vector<bool>(n+1,false));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
                dp[i][i+1]=true;
        }
        
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<n-i+1;j++)
            {
                if(s[j]==s[i+j-1])
                {
                    //cout<<" j : "<<j<<" end : "<<i+j-1<<"\n";
                    dp[j][i+j-1]=dp[j+1][i+j-2];
                }
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        int ans=solve(dp,0);
        return ans-1;
    }
};
