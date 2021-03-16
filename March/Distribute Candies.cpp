class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int,int>m;
        const int f=100000;
        int ans=0;
        for(int i=0;i<candyType.size();i++)
        {
            if(m.count(f+candyType[i]))
                continue;
            ans++;
            m[f+candyType[i]]++;
        }
        if(ans>candyType.size()/2)
            return candyType.size()/2;
        return ans;
    }
};
