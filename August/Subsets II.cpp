class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<(1<<n);i++)
        {
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j))>0)
                    temp.push_back(nums[j]);
            }
            s.insert(temp);
        }
        
        vector<vector<int>>ans;
        for(auto it:s)
            ans.push_back(it);
        return ans;
    }
};
