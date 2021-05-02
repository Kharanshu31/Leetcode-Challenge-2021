class WordFilter {
public:
    unordered_map<string,int>m;
    WordFilter(vector<string>& words) {
        for(int a=0;a<words.size();a++)
        {
            string s=words[a];
            int n=s.length();
            for(int i=1;i<=n;i++)
            {
                string t=s.substr(0,i);
                for(int j=0;j<n;j++)
                {
                    string k=s.substr(j,n);
                    m[t+"#"+k]=a;
                }
            }
        }
        
    }
    
    int f(string prefix, string suffix) {
        string s=prefix+"#"+suffix;
        return m[s];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
