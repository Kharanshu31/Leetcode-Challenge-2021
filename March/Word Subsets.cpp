class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int>h(26,0);
        for(auto c:B)
        {
            vector<int>temp(26,0);
            for(char b:c)
                temp[b-'a']++;
            for(int i=0;i<26;i++)
                h[i]=max(h[i],temp[i]);
        }
        vector<string>ans;
        for(auto c:A)
        {
            vector<int>f(26,0);
            for(auto it:c)
                f[it-'a']++;
            
            for(int i=0;i<26;i++)
                f[i]-=h[i];
            bool flag=true;
            for(int i=0;i<26;i++)
            {
                if(f[i]<0)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans.push_back(c);
        }
        
        return ans;
    }
};
