class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
       unordered_map<int,int>m;
        for(auto &a:A)
        {
            for(auto &b:B)
            {
                m[a+b]++;
            }
        }
        int ans=0;
        for(auto &c:C)
        {
            for(auto &d:D)
            {
                if(m.find(-c-d)!=m.end())
                    ans+=m[-c-d];
            }
        }
        
        return ans; 
    }
};
