class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.length();
        int i=1;
        while(i<n)
        {
            int st=i-1;
            bool flag=false;
            while(s[i]==s[i-1] && i<n)
            {
                if(i-st+1==k)
                {
                    flag=true;
                    s.erase(st,k);
                    i=1;
                    break;
                }
                i++;
            }
            if(!flag)
                i++;
        }
        return s;
    }
};
