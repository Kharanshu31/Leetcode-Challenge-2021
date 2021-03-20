class Solution {
public:
    int removePalindromeSub(string s) {
        if(s=="")
            return 0;
        int i=0,j=s.length()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
                break;
            i++;
            j--;
        }
        cout<<" i : "<<i<<" j : "<<j;
        if(i>j)
            return 1;
        else
            return 2;
    }
};
