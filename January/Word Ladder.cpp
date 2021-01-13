class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s;
        for(auto c:wordList)
            s.insert(c);
        
        if(s.find(endWord)==s.end())
            return 0;
        
        queue<string>q;
        q.push(beginWord);
        
        int ans=0;
        while(!q.empty())
        {
            ans++;
            int n=q.size();
            while(n--)
            {
                string t=q.front();
                //cout<<" t : "<<t<<"\n";
                q.pop();
                for(int i=0;i<t.length();i++)
                {
                    string temp=t;
                    for(char c='a';c<='z';c++)
                    {
                        temp[i]=c;
                        
                        if(temp==t)
                            continue;
                        
                        if(temp==endWord)
                            return ans+1;
                        
                        if(s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        
        return 0;
        
    }
};
