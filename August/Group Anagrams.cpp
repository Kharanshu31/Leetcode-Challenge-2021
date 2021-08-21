class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string> >m;
        for(auto s:strs)
        {
            vector<int>h(26,0);
            for(int i=0;i<s.length();i++)
                ++h[s[i]-'a'];
            m[h].push_back(s);
        }
        
        vector<vector<string>>ans;
        for(auto it:m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
