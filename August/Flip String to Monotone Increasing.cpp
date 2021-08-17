class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.length();
        int tot_one=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                tot_one++; 
        }
        int ans=n;
        int cur_zero=0;
        int cur_one=0;
        for(int i=0;i<=n;i++)
        {
            int z=cur_zero;
            int o=tot_one-cur_one;
            //cout<<" z : "<<z<<" o : "<<o<<" changes : "<<n-o-z<<" i : "<<i<<"\n";
            ans=min(ans,n-i-o+i-z);
            if(i<n)
            {
                if(s[i]=='0')
                    cur_zero++;
                else
                    cur_one++;
            }
        }
        return ans;
        
    }
};
