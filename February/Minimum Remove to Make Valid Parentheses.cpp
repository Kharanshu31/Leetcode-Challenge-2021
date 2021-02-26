class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        stack<char>open;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            if(c=='(')
            {
                ans+=c;
                open.push(c);
            }
            else if(c==')')
            {
                cout<<" open : "<<open.size()<<"\n";
                if(!open.empty())
                {
                    ans+=c;
                    open.pop();
                }
            }
            else
            {
                ans+=c;
            }
        }
        cout<<" ans : "<<ans<<"\n";
        string res="";
        stack<char>close;
        for(int i=ans.length()-1;i>=0;i--)
        {
            char c=ans[i];
            if(c==')')
            {
                res+=c;
                close.push(c);
            }
            else if(c=='(')
            {
                cout<<" close : "<<close.size()<<"\n";
                if(!close.empty())
                {
                    res+=c;
                    close.pop();
                }
            }
            else
            {
                res+=c;
            }
        }
        cout<<" res : "<<res<<"\n";
        reverse(res.begin(),res.end());
        return res;
    }
};
