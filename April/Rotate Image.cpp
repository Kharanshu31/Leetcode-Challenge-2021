class Solution {
public:
    void print(vector<vector<int>>& ar)
    {
        for(int i=0;i<ar.size();i++)
        {
            for(int j=0;j<ar.size();j++)
                cout<<ar[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int a=0;
        int b=n-1;
        while(a<b)
        {
            for(int i=0;i<b-a;i++)
            {
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            print(matrix);
            ++a;
            --b;
        }
    }
};
