class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,ans=0;
        
        if(nums[n-1]-nums[0]==1)
            return n;
        for(int i=0;i<n;i++)
            cout<<nums[i]<<" ";
        while(i<n)
        {
            int j=i+1;
            while(j<n && nums[j]-nums[i]<=1)
                j++;
            cout<<" i : "<<i<<" j : "<<j<<"\n";
            if(nums[j-1]-nums[i]==1)
            {
                ans=max(ans,j-i);
            }
            i++;
        }
        
        return ans;
    }
};
