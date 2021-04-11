class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        int a=0,b=0;
        for(int i=0;i<n/2;i++)
        {
            s[i]=tolower(s[i]);
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                a++;
        }
        for(int i=n/2;i<n;i++)
        {
            s[i]=tolower(s[i]);
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                b++;
        }
        return a==b;
    }
};
