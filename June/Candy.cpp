class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({ratings[i],i});
        }
        
        sort(v.begin(),v.end());
        vector<int>ans(n,1);
        for(int i=0;i<n;i++)
        {
            int ind=v[i].second;
            //cout<<" ind : "<<ind<<" v : "<<v[i].first<<"\n";
            if(ind>0 && ratings[ind-1]<v[i].first)
            {
                ans[ind]=max(ans[ind],ans[ind-1]+1);
            }
            if(ind<n-1 && ratings[ind+1]<v[i].first)
            {
                ans[ind]=max(ans[ind],ans[ind+1]+1);
            }
        }
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            //cout<<ans[i]<<" ";
            res+=ans[i];
        }
        return res;
    }
};
