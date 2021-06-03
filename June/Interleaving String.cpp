class Solution {
public:
    int n,m,t;
    int dp[101][101];
    bool solve(string s1, string s2, string s3,int i,int j,int k)
    {
        //cout<<" i : "<<i<<" j : "<<j<<" k : "<<k<<"\n";
        if(k==t && i==n && j==m)
        {
            return true;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        bool ans=false;
        if(i<n && k<t && s1[i]==s3[k])
        {
            ans=ans|solve(s1,s2,s3,i+1,j,k+1);
        }
        
        if(j<m && k<t && s2[j]==s3[k])
        {
            ans=ans|solve(s1,s2,s3,i,j+1,k+1);
        }
        
        return dp[i][j]=ans;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        n=s1.length();
        m=s2.length();
        t=s3.length();
        
        return solve(s1,s2,s3,0,0,0);
    }
};
