class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>mp;
        if(k>=s.length())
            return false;
        for(int i=0;i<=(s.length()-k);i++)
            mp.insert(s.substr(i, k));
        return mp.size()==pow(2, k);
    }
};
