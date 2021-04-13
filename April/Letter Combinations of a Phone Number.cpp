class Solution {
public:
    vector<string>mappings={"#","#","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    void solve(string d,int i,int n,string ssf)
    {
        if(i>n)
            return;
        if(i==n)
        {
            ans.push_back(ssf);
            return;
        }
        for(int j=0;j<mappings[d[i]-'0'].length();j++)
        {
            solve(d,i+1,n,ssf+mappings[d[i]-'0'][j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return ans;
        solve(digits,0,digits.length(),"");
        return ans;
    }
};
