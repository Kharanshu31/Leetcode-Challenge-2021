class NumMatrix {
public:
    vector<vector<int>>ar;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        ar=matrix;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                ar[i][j]+=ar[i][j-1];
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ar[i][j]+=ar[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=ar[row2][col2];
        if(row1>0)
        {
            ans-=ar[row1-1][col2];
        }
        
        if(col1>0)
        {
            ans-=ar[row2][col1-1];
        }
        
        if(row1>0 && col1>0)
        {
            ans+=ar[row1-1][col1-1];
        }
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
