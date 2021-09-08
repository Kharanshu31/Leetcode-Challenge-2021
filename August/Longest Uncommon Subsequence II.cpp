class Solution {
public:
    
    bool sub(string s,string t)
    {
        int n=s.length();
        int m=t.length();
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        return (j==m);
    }
    
    int findLUSlength(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        for(int i=0;i<n;i++)
        {
            bool flag=true;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                if(sub(strs[j],strs[i]))
                {
                    //cout<<" i : "<<i<<" j : "<<j<<"\n";
                    flag=false;
                    break;
                }
            }
            if(flag && ans.length()<strs[i].length())
                ans=strs[i];
        }
        
        return ans=="" ? -1 : ans.length();
    }
};
