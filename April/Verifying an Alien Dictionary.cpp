class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();
        vector<int>h(27,0);
        for(int i=0;i<26;i++)
            h[order[i]-'a']=i;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
               words[i][j]=h[words[i][j]-'a'];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};
