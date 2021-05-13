class Solution {
public:
    int maxScore(vector<int>& ar, int k) {
        int n=ar.size();
        int cur=0;
        int tot=0;
        int mn=1e9;
        k=n-k;
        for(int i=0;i<n;i++)
        {
            tot+=ar[i];
            if(i>=k)
            {
                cout<<" cur : "<<cur<<"\n";
                mn=min(mn,cur);
                cur-=ar[i-k];
            }
            cur+=ar[i];
        }
        cout<<" cur : "<<cur<<"\n";
        mn=min(mn,cur);
        return tot-mn;
    }
};
