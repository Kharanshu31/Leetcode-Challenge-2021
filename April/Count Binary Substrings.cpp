class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length();
        int ans=0;
        int o=0,z=0;
        int i=0;
        while(i<n)
        {
            o=0;
            while(i<n && s[i]=='1')
            {
                o++;
                i++;
            }
            ans+=min(z,o);
            z=0;
            while(i<n && s[i]=='0')
            {
                i++;
                z++;
            }
            ans+=min(o,z);
        }
        return ans;
    }
};
