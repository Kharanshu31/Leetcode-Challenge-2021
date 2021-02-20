class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>h1(256,0);
        vector<int>h2(256,0);
        for(auto c:s)
            h1[c]++;
        for(auto c:t)
            h2[c]++;
        return h1==h2;
    }
};
