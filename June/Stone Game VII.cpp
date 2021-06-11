class Solution {
public:
    
    int n;
    int dp[1001][1001][2];
    int solve(vector<int>& stones,vector<int>& pre,int i,int j,bool alice)
    {
        if(i>j || j<=0 || i>=n-1)
            return 0;
        
        if(dp[i][j][alice]!=-1)
            return dp[i][j][alice];
        
        int x=0;
        if(i)
            x=pre[i-1];
        int sum=pre[j-1]-x;
        if(alice)
        {
            return dp[i][j][alice]=max(sum+solve(stones,pre,i,j-1,!alice),pre[j]-pre[i]+solve(stones,pre,i+1,j,!alice));
        }
        else
        {
            return dp[i][j][alice]=min(-sum+solve(stones,pre,i,j-1,!alice),-pre[j]+pre[i]+solve(stones,pre,i+1,j,!alice));
        }
        
    }
    
    int stoneGameVII(vector<int>& stones) {
        n=stones.size();
        if(n==1)
            return stones[0];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<2;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        vector<int>pre(n,0);
        for(int i=0;i<n;i++)
        {
            if(i)
                pre[i]=pre[i-1];
            pre[i]+=stones[i];
        }
        int ans=solve(stones,pre,0,n-1,true);
        return ans;
    }
};
