class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn=0;
        int cur=0;
        for(auto n:nums)
        {
            cur+=n;
            mn=min(mn,cur);
        }
        return abs(mn)+1;
    }
};
