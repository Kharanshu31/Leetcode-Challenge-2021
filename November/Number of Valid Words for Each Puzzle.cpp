class Solution {
public:
    
    int getmask(string s)
    {
        int mask=0;
        for(auto c:s)
            mask|=(1<<(c-'a'));
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        map<int,int>m;
        for(auto s:words)
            m[getmask(s)]++;
        
        int n=puzzles.size();
        vector<int>ans(n,0);
        int k=0;
        for(auto p:puzzles)
        {
            int mask=getmask(p);
            int submask=mask;
            while(submask)
            {
                if((submask&(1<<(p[0]-'a')))!=0 && m.count(submask))
                      ans[k]+=m[submask];
                submask=(submask-1)&mask;
            }
            k++;
        }
        return ans;
    }
};
