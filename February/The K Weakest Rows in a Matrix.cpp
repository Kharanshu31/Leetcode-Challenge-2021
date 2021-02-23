class Solution {
public:
    static bool cmp(const pair<int,int>a,const pair<int,int>b)
    {
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>p;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            int ct=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    ++ct;
                else
                    break;
            }
            p.push_back({ct,i});
        }
        
        sort(p.begin(),p.end(),cmp);
        vector<int>ans;
        for(int i=0;i<k;i++)
            ans.push_back(p[i].second);
        return ans;
    }
};
