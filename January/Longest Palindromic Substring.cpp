class Solution {
public:
    string longestPalindrome(string s) {
        int left=0;
        int mx=0;
        int i=0;
        int n=s.length();
        while(i<n)
        {
            int l=i;
            int r=i;
            while(r<n-1 && s[r]==s[r+1])
            {
                r++;
            }
            i=r+1;
            while(r<n && l>0 && s[r+1]==s[l-1])
            {
                r++;
                l--;
            }
            if(r-l+1>mx)
            {
                mx=r-l+1;
                left=l;
            }
        }
        
        return s.substr(left,mx);
    }
};
