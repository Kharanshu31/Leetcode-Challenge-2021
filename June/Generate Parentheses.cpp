class Solution {
public:
    
    bool valid(string s)
    {
        stack<int>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                if(st.empty())
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
    
    vector<string>ans;
    
    void solve(string s,int ct,int n)
    {
        if(ct==2*n)
        {
            if(valid(s))
                ans.push_back(s);
            return;
        }
        
        solve(s+'(',ct+1,n);
        solve(s+')',ct+1,n);
    }
        
    
    vector<string> generateParenthesis(int n) {
        solve("",0,n);
        return ans;
    }
};
