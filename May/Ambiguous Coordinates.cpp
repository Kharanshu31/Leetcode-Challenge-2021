class Solution {
public:
    bool check(string s,bool decimal)
    {
        int n=s.length();
        if(!decimal)
        {
            if(n>1 && s[0]=='0')
                return false;
        }
        else
        {
            if(n>=1 && s[n-1]=='0')
                return false;
        }
        return true;
    }
    vector<string> ambiguousCoordinates(string s) {
        int n=s.length()-2;
        s=s.substr(1,s.length()-2);
        vector<string>ans;
        for(int i=1;i<n;i++)
        {
            string s1=s.substr(0,i);
            string s2=s.substr(i);
            vector<string>v1,v2;
            if(check(s1,false))
                v1.push_back(s1);
            if(check(s2,false))
                v2.push_back(s2);
            for(int j=1;j<s1.length();j++)
            {
                string t=s1.substr(0,j);
                string k=s1.substr(j);
                if(check(t,false) && check(k,true))
                    v1.push_back(t+"."+k);
            }
            
            for(int j=1;j<s2.length();j++)
            {
                string t=s2.substr(0,j);
                string k=s2.substr(j);
                if(check(t,false) && check(k,true))
                    v2.push_back(t+"."+k);
            }
            
            for(auto it:v1)
            {
                for(auto it2:v2)
                {
                    ans.push_back("("+it+", "+it2+")");
                }
            }
        }
        return ans;
    }       
};
