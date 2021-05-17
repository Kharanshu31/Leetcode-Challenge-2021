static bool cmp(string &a, string &b){
        if(a.size() < b.size()){
            return true;
        }
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        vector<vector<int> >h(26,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                ++h[words[i][j]-'a'][i];
            }
        }
        
        vector<int>dp(n,1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=0;
                for(int k=0;k<26;k++)
                {
                    diff+=abs(h[k][i]-h[k][j]);
                }
                
                if(diff==1)
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
