class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        vector<int>pre={1};
        ans.push_back(pre);
        for(int i=1;i<n;i++)
        {
            vector<int>temp={1};
            for(int i=0;i<pre.size()-1;i++)
            {
                temp.push_back(pre[i]+pre[i+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            pre=temp;
        }
        return ans;
    }
};
