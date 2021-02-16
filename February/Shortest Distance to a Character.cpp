class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>ar;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==c)
            {
                ar.push_back(i);
            }
        }
        vector<int>ans;
        int n=ar.size();
        for(int i=0;i<=ar[0];i++)
        {
            ans.push_back(ar[0]-i);
        }
        
        // if(n==1)
        // {
        //     for(int i=ar[n-1]+1;i<s.length();i++)
        //     {
        //         ans.push_back(i-ar[n-1]);
        //     }
        //     return ans;
        // }
        
        int prev=1;
        int cur=ar[0]+1;
        while(cur<s.length() && prev<=n-1)
        {
            if(cur==ar[prev])
            {
                ans.push_back(0);
                prev++;
            }
            else
            {
                ans.push_back(min(cur-ar[prev-1],ar[prev]-cur));
            }
            cur++;
        }
        for(int i=ar[n-1]+1;i<s.length();i++)
        {
            ans.push_back(i-ar[n-1]);
        }
        return ans;
    }
};
