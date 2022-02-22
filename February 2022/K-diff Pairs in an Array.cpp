class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        
        int ans=0;
        if(k==0)
        {
            
            for(auto it:m)
            {
                ans += (it.second > 1);
            }
            
            return ans;
        }
        
        for(auto it:m)
        {
            //cout<<" currently at : "<<it.first<<"\n";
            if(m.find(it.first+k)!=m.end())
                ans++;
        }
        
        return ans;
    }
};
