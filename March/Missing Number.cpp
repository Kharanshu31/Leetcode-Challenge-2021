class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1)/2;
        int tot=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<=n;i++)
        {
            if(sum-i==tot)
                return i;
        }
        return -1;
    }
};
