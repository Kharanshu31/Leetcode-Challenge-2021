class Solution {
public:
    int minSetSize(vector<int>& ar) {
        int n=ar.size();
        unordered_map<int,int>m;
        for(auto it:ar)
            m[it]++;
        priority_queue<int>pq;
        for(auto it:m)
            pq.push(it.second);
        int sum=0;
        int ans=0;
        while(!pq.empty() && sum<n/2)
        {
            ++ans;
            sum+=pq.top();
            pq.pop();
        }
        return ans;
        
    }
};
