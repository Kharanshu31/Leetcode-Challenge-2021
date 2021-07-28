class Solution {
public:
    
    int count(vector<vector<int>>& mat,int n,int mid)
    {
        int ct=0;
        for(int i=0;i<n;i++)
        {
            int pos=lower_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
            ct+=pos;
        }
        return ct;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();                             
        int l=mat[0][0];
        int r=mat[n-1][n-1]+1;
        //if(k==n*n)
        //    return r-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int x=count(mat,n,mid);
            //cout<<" mid : "<<mid<<" count : "<<x<<"\n";
            if(x<k)
                l=mid+1;
            else
                r=mid-1;
        }
        
        return l-1;
    }
};
