class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        int ans=0;
        stack<int>open;
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(c=='(')
            {
                open.push(i);
            }
            else if(open.size())
            {
                s[i]='#';
                s[open.top()]='#';
                open.pop();
            }
        }
        cout<<s;
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='#')
                ct++;
            else
            {
                ans=max(ans,ct);
                ct=0;
            }
        }
        ans=max(ans,ct);
        return ans;
    }
};
