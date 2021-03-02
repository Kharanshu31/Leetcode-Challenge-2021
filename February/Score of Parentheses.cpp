class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int>s;
        int ans=0;
        for(auto c:S)
        {
            if(c=='(')
            {
                s.push(ans);
                ans=0;
            }
            else
            {
                ans+=s.top()+max(ans,1);
                s.pop();
            }
        }
        return ans;
    }
};
