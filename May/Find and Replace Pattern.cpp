class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        int n=pattern.length();
        for(auto s:words)
        {
            cout<<" s : "<<s<<"\n";
            string temp=s;
            vector<char>h(26,'#');
            vector<bool>vis(26,false);
            bool flag=true;
            for(int i=0;i<n;i++)
            {
                if(temp[i]==pattern[i])
                {
                    h[temp[i]-'a']=pattern[i];
                    vis[pattern[i]-'a']=true;
                }
                else
                {
                    if(h[temp[i]-'a']!='#')
                    {
                        temp[i]=h[temp[i]-'a'];
                    }
                    else
                    {
                        if(vis[pattern[i]-'a'])
                        {
                            flag=false;
                            break;
                        }
                        else
                        {
                            vis[pattern[i]-'a']=true;
                            h[temp[i]-'a']=pattern[i];
                            temp[i]=pattern[i];
                        }
                    }
                }
            }
            if(flag && temp==pattern)
                ans.push_back(s);
            //cout<<" temp : "<<temp<<"\n";
        }
        
        return ans;
    }
};
