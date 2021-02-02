class Solution {
public:
    string getSmallestString(int n, int k) {
        int a=0,z=0;
        while(n>1 && k-1<(n-1)*26)
        {
            a++;
            n--;
            k--;
        }
        
        while(n>1 && k-26>=(n-1))
        {
            z++;
            n--;
            k-=26;
        }
        string ans="";
        while(a>0)
        {
            ans+='a';
            a--;
        }
        
        if(k>0)
        {
            ans+='a'+k-1;
        }
        
        while(z>0)
        {
            ans+='z';
            z--;
        }
        
        return ans;
        
    }
};
