class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string>ans;
        ans.push_back(S);
        for(int i=0;i<S.length();i++)
        {
            char c=S[i];
            if(c>='a'&& c<='z')
            {
                int t=ans.size();
                for(int j=0;j<t;j++)
                {
                    string x=ans[j];
                    x[i]=c-32;
                    ans.push_back(x);
                }
            }
            else if(c>='A'&& c<='Z')
            {
                int t=ans.size();
                for(int j=0;j<t;j++)
                {
                    string x=ans[j];
                    x[i]=c+32;
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};
