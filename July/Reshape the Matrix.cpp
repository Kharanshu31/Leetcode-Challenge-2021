class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        if(n*m!=r*c)
            return mat;
        vector<vector<int>>ans(r,vector<int>(c,0));
        int x=0;
        int y=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(y==m)
                {
                    x++;
                    y=0;
                }
                ans[i][j]=mat[x][y];
                y++;
            }
        }
        
        return ans;
    }
};
