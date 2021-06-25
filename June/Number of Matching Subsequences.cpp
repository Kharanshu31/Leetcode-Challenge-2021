class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>h(26);
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            h[s[i]-'a'].push_back(i);
        }
        
        int ans=0;
        for(auto it:words)
        {
            string t=it;
            int m=t.length();
            bool flag=true;
            int init=0;
            //cout<<" t : "<<t<<"\n";
            for(int i=0;i<m;i++)
            {
                char c=t[i];
                if(h[c-'a'].empty())
                {
                    flag=false;
                    break;
                }
                else
                {
                    int pos=lower_bound(h[c-'a'].begin(),h[c-'a'].end(),init)-h[c-'a'].begin();
                    //cout<<" pos : "<<pos<<" init : "<<init<<"\n";
                    if(pos==h[c-'a'].size())
                    {
                        flag=false;
                        break;
                    }
                    else
                    {
                        init=h[c-'a'][pos]+1;
                    }
                }
            }
            
            if(flag)
            {
                ans++;
            }
        }
        
        return ans;
    }
};
