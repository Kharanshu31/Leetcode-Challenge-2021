class Solution {
public:
    int r,c;
    bool pacific[151][151];
    bool atlantic[151][151];
    void dfs(vector<vector<int>>& ar,int i,int j,vector<vector<bool>>&vis,int curi,int curj)
    {
        if(i<0 || j<0 || j>=c || i>=r)
            return;
        vis[i][j]=true;
        if(i==0 || j==0)
        {
            pacific[curi][curj]=true;
            return;
        }
        
        if(i==r-1 || j==c-1)
        {
            atlantic[curi][curj]=true;
            return;
        }
        
        if(i<r-1)
        {
            if(ar[i][j]>=ar[i+1][j])
                dfs(ar,i+1,j,vis,curi,curj);
        }
        
        if(i>0)
        {
            if(ar[i][j]>=ar[i-1][j])
                dfs(ar,i-1,j,vis,curi,curj);
        }
        
        if(j<c-1)
        {
            if(ar[i][j]>=ar[i][j+1])
                dfs(ar,i,j+1,vis,curi,curj);
        }
        
        if(j>0)
        {
            if(ar[i][j]>=ar[i][j-1])
                dfs(ar,i,j-1,vis,curi,curj);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        r=n;
        c=m;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    dfs(matrix,i,j,vis,i,j);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(atlantic[i][j] && pacific[i][j])
                {
                    vector<int>temp={i,j};
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
