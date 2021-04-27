class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        map<int,int>mp;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            int m=wall[i].size();
            int sum=0;
            for(int j=0;j<m;j++)
            {
                sum+=wall[i][j];
                mp[sum]++;
                mx=max(mx,sum);
            }
        }
        int ans=n;
        for(auto it:mp)
        {
            if(it.first==mx)
                continue;
            cout<<it.first<<"  "<<it.second<<"\n";
            ans=min(ans,n-it.second);
        }
        return ans;
    }
};
