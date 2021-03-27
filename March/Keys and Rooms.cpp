class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms,vector<bool>&vis,int u)
    {
        vis[u]=true;
        for(auto it:rooms[u])
            if(!vis[it])
                dfs(rooms,vis,it);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        dfs(rooms,vis,0);
        for(int i=0;i<n;i++)
            if(!vis[i])
                return false;
        return true;
    }
};
