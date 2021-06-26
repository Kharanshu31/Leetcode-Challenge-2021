class Solution {
public:
    
    int find(int parent[],int x)
    {
        while(x!=parent[x])
            x=parent[x];
        return x;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        int parent[n+1];
        for(int i=1;i<=n;i++)
            parent[i]=i;
        
        vector<int>ans;
        for(auto e:edges)
        {
            int f1=find(parent,e[0]);
            int f2=find(parent,e[1]);
            if(f1==f2)
            {
                ans=e;
            }
            else
            {
                parent[f2]=f1;
            }
        }
        
        return ans;
    }
};
