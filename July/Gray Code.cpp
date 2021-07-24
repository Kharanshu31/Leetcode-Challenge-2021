class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ans;
        int temp;
        for(int i=0;i<(1<<n);i++)
        { 
            temp=(i>>1);
            ans.push_back((i^temp));   
        }
        return ans;
    }
};
