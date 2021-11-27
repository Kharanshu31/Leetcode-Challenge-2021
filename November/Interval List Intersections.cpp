class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        int n=first.size();
        int m=second.size();
        int i=0,j=0;
        vector<vector<int>>ans;
        while(i<n && j<m)
        {
            
            if(first[i][0]>second[j][1])
            {
                j++;
                continue;
            }
            
            if(second[j][0]>first[i][1])
            {
                i++;
                continue;
            }
            
            if(first[i][0]>second[j][0])
            {
                if(first[i][1]>second[j][1])
                {
                    ans.push_back({first[i][0],second[j][1]});
                    j++;
                }
                else
                {
                    ans.push_back(first[i]);
                    i++;
                }
            }
            else
            {
                if(second[j][1]>first[i][1])
                {
                    ans.push_back({second[j][0],first[i][1]});
                    i++;
                }
                else
                {
                    ans.push_back(second[j]);
                    j++;
                }
            }
        }
        
        return ans;
    }
};
