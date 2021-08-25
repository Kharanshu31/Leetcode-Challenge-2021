class NumArray {
public:
    vector<int>pre;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        pre.resize(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return pre[right]-(left>0 ? pre[left-1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
