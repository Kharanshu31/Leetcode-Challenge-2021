class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>h1(26,0);
        vector<int>h2(26,0);
        for(auto c:word1)
            h1[c-'a']++;
        bool flag=true;
        for(auto c:word2)
        {
            if(h1[c-'a']==0)
                flag=false;
            h2[c-'a']++;
        }
        sort(h1.begin(),h1.end());
        sort(h2.begin(),h2.end());
        if(h1!=h2)
            flag=false;
        return flag;
    }
};
