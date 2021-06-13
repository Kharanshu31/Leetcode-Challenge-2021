class Solution {
public:
    int minRefuelStops(int target, int start, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int cur=start;
        int ans=0;
        int n=stations.size();
        int i=0;
        while(cur<target)
        {
            while(i<n && stations[i][0]<=cur)
            {
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty())
                return -1;
            cur+=pq.top();
            pq.pop();
            ans++;
        }
        
        return ans;
        
    }
};
