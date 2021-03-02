class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<vector<int>>ar(26);
        for(int i=0;i<s.length();i++)
        {
            ar[s[i]-'a'].push_back(i);
        }
        
        string ans="";
        for(int i=0;i<d.size();i++)
        {
            string t=d[i];
            if(t.length()<ans.length())
                continue;
            int n=t.length();
            bool flag=true;
            int prev=-1;
            //vector<vector<bool>>vis(26,vector<bool>(n,false));
            vector<vector<int>>temp=ar;
            for(int j=0;j<n;j++)
            {
                if(ar[t[j]-'a'].empty())
                {
                    cout<<" char : "<<t[j]<<"\n";
                    flag=false;
                    break;
                }
                bool found=false;
                int ct=0;
                for(auto it:ar[t[j]-'a'])
                {
                    if(it>prev)
                    {
                        found=true;
                        prev=it;
                        ar[t[j]-'a'].erase(ar[t[j]-'a'].begin()+ct);
                        break;
                    }
                    ct++;
                }
                if(!found)
                {
                    flag=false;
                    break;
                }
            }
            ar=temp;
            if(flag)
            {
                cout<<" t : "<<t<<"\n";
                if(t.length()>ans.length())
                    ans=t;
                else if(std::string(t) < std::string(ans))
                    ans=t;
            }
        }
        return ans;
    }
};
