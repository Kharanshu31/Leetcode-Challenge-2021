class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int>left;
        int sum=0;
        left[0]=0;
        for(int i=0;i<n;i++)
        {
            if(sum>x)
                break;
            left[sum]=i;
            sum+=nums[i];
        }
        
        int ans=INT_MAX;
        if(left.find(x)!=left.end())
            ans=left[x]+1;
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            auto it=left.find(x-sum);
            if(it!=left.end()&& i>=it->second-1)
            {
                ans=min(ans,(n-i-1)+it->second);
            }
            sum+=nums[i];
        }
        
        return ans==INT_MAX ? -1 : ans;
    }
};
