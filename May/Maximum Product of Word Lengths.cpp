class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int>h(n,0);
        for(int i=0;i<n;i++)
        {
            string s=words[i];
            for(int j=0;j<s.length();j++)
            {
                int x=s[j]-'a'+1;
                h[i]|=(1<<x);
            }
        }
        
        for(int i=0;i<n;i++)
            cout<<h[i]<<" ";
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if( (h[i]&h[j])==0)
                {
                    if(ans<words[i].length()*words[j].length())
                        ans=words[i].length()*words[j].length();
                }
            }
        }
        
        return ans;
    }
};
