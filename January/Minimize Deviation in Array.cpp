class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int>pq;
        int mn=1e9+1,res=1e9+1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
                pq.push(nums[i]),mn=min(mn,nums[i]);
            else
                pq.push(nums[i]*2),mn=min(mn,nums[i]*2);
        }
        
        while(pq.top()%2==0)
        {
            res=min(res,pq.top()-mn);
            mn=min(mn,pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        res=min(res,pq.top()-mn);
        return res;
    }
};
