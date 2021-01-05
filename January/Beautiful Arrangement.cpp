class Solution {
public:
    int ans=0;
    vector<int>path;
    void traverse(int n,vector<bool>&vis,int pos)
    {
        if(path.size()==n)
        {
            ans++;
            return;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
                continue;
            if(pos%i==0 || i%pos==0)
            {
                vis[i]=true;
                path.push_back(i);
                traverse(n,vis,pos+1);
                path.pop_back();
                vis[i]=false;
            }
        }
        
    }
    
    int countArrangement(int n) {
        vector<bool>vis(16,false);
        traverse(n,vis,1);
        return ans;
    }
};
