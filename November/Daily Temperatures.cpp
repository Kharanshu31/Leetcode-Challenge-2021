class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        stack<pair<int,int> >s;
        vector<int>ans(n,0);
        s.push({temp[n-1],n-1});
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && s.top().first<=temp[i])
                s.pop();
            if(!s.empty())
                ans[i]=s.top().second-i;
            s.push({temp[i],i});
        }
        return ans;
    }
};
