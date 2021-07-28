class Solution {
public:
    bool isIsomorphic(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n!=m)
            return false;
        unordered_map<char,char>a;
        unordered_map<char,char>b;
        for(int i=0;i<n;i++)
        {
            if(a.count(s1[i]))
            {
                if(a[s1[i]]!=s2[i])
                    return false;
            }
            else if(b.count(s2[i]))
            {
                return false;
            }
            else
            {
                a[s1[i]]=s2[i];
                b[s2[i]]=s1[i];
            }
        }
        
        return true;
    }
};
