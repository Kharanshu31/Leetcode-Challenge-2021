class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        map<int,int>m;
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        
        auto it=m.begin();
        int prev=it->first-1;
        int ct=0;
        int ans=0;
        for(auto ptr:m)
        {
            if(ptr.first-prev==1)
            {
                ct++;
            }
            else
            {
                ans=max(ans,ct);
                ct=1;
            }
            prev=ptr.first;
        }
        ans=max(ans,ct);
        return ans;
    }
};
