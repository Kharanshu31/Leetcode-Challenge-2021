class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        vector<bool>vis(n,false);
        
        vector<int>pos(1001,-1);
        for(int i=0;i<n;i++)
        {
            pos[pushed[i]]=i;
        }
        
        int prev=-1;
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            int x=popped[i];
            cout<<" x : "<<x<<" pos : "<<pos[x]<<"  prev : "<<prev<<"\n";
            if(pos[x]>prev)
            {
                for(int j=prev+1;j<pos[x];j++)
                {
                    cout<<" j : "<<j<<" pushed : "<<pushed[j]<<"  vis : "<<vis[j]<<"\n";
                    if(vis[j])
                    {
                        return false;
                    }
                    s.push(pushed[j]);
                }
                prev=pos[x];
                vis[prev]=true;
            }
            else
            {
                vis[pos[x]]=true;
                stack<int>temp=s;
                cout<<" Stack : ";
                while(!temp.empty())
                {
                    cout<<temp.top()<<"  ";
                    temp.pop();
                }
                cout<<"\n";
                if(s.empty() || s.top()!=x)
                {
                    return false;
                }
                s.pop();
                for(int j=prev;j>=pos[x];j--)
                {
                    cout<<" j : "<<j<<"  vis : "<<vis[j]<<"\n";
                    if(!vis[j])
                    {
                        return false;
                    }
                }

            }
        }
        
        return true;
    }
};
