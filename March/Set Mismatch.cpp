class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>h(n+1,0);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(h[nums[i]]>0)
                ans.push_back(nums[i]);
            h[nums[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(h[i]==0)
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
