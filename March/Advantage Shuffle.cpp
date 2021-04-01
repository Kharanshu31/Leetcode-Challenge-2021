class Solution {
public:
    vector<int> advantageCount(vector<int>& ar, vector<int>& br) {
        int n=ar.size();
        sort(ar.begin(),ar.end());
        vector<int>ans(n,-1);
        int i=0;
        for(auto it:br)
        {
            auto pos=lower_bound(ar.begin(),ar.end(),it+1);
            if(pos==ar.end())
            {
                cout<<" Not found for : "<<it<<"\n";
            }
            else
            {
                cout<<" br : "<<it<<" ar : "<<*pos<<" i : "<<i<<"\n";
                ans[i]=*pos;;
                ar.erase(pos);
            }
            ++i;
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]==-1 && !ar.empty())
            {
                ans[i]=ar.back();
                ar.pop_back();
            }
        }
        return ans;
    }
};
