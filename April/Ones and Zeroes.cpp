class Solution {
public:
    int dp[601][101][101];
    int one(string s)
    {
        int ct=0;
        for(auto c:s)
            if(c=='1')
                ct++;
        return ct;
    }
    int solve(vector<string>& ar, int cur0, int cur1,int i)
    {
        if(i<0 || cur0<0 || cur1<0)
            return 0;
        //cout<<cur0<<"  "<<cur1<<"\n";
        if(dp[i][cur0][cur1]!=-1)
            return dp[i][cur0][cur1];
        
        int o=one(ar[i]);
        int z=ar[i].length()-o;
        cout<<" z : "<<z<<"  o : "<<o<<" i : "<<i<<"\n";
        if(cur0-z>=0 && cur1-o>=0)
        {
            return dp[i][cur0][cur1]=max(1+solve(ar,cur0-z,cur1-o,i-1),solve(ar,cur0,cur1,i-1));
        }
        else
        {
            return dp[i][cur0][cur1]=solve(ar,cur0,cur1,i-1);
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(strs,m,n,strs.size()-1);
        return ans;
    }
};
