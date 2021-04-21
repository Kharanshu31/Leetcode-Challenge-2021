class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>&ar, int target) {
        int n=ar.size(),m=ar[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            vector<int>rows(n,0);
            for(int j=i;j<m;j++)
            {
                for(int k=0;k<n;k++)
                    rows[k]+=ar[k][j];
                unordered_map<int,int>mp;
                mp[0]=1;
                int sum=0;
                for(int k=0;k<n;k++)
                {
                    sum+=rows[k];
                    if(mp.count(sum-target))
                        ans+=mp[sum-target];      
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};
