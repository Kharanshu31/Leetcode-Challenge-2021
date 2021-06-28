class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            bool flag=true;
            while(!st.empty() && st.top()==s[i])
            {
                flag=false;
                st.pop();
            }
            
            if(flag)
                st.push(s[i]);
        }
        
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
