class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(m>n)
            return "";
        
        vector<int>h(256,0);
        for(char c:t)
            h[c]++;
        vector<int>vis(256,0);
        int i=0,j=0;
        int start=0;
        int len=n+1;
        int ct=0;
        while(i<n)
        {
            if(vis[s[i]]<h[s[i]])
                ct++;
            vis[s[i]]++;   
            if(ct>=m)
            {
                while(j<n && vis[s[j]]>h[s[j]])
                {
                    vis[s[j]]--;
                    j++;
                }
                
                if(len>i-j+1)
                {
                    len=i-j+1;
                    start=j;
                }
            }
            i++;
        }
        
        if(len==n+1)
            return "";
        return s.substr(start,len);
    }
};
