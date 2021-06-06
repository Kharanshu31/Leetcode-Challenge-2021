typedef long long ll;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(efficiency[i],speed[i]));
        }
        
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        ll ans=0;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=v[i].second;
            pq.push(v[i].second);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            ans=max(ans,sum*(ll)(v[i].first));
        }
        
        return ans%1000000007;
    }
};
