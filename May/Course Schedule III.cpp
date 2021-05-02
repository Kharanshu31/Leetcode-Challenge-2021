class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<pair<int,int>>v;
        for(auto c:courses)
            v.push_back({c[1],c[0]});
        
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        int cur=0;
        for(auto it:v)
        {
            cout<<it.second<<"  "<<it.first<<"\n";  
            pq.push(it.second);
            cur+=it.second;
            if(cur>it.first)
            {
                cur-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
