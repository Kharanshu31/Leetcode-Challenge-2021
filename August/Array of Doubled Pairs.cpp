class Solution {
public:
    bool canReorderDoubled(vector<int>& ar) {
        int n=ar.size();
        sort(ar.begin(),ar.end());
        multiset<int>s;
        for(int i=0;i<n;i++)
        {
            if(s.find(ar[i]*2)!=s.end())
            {
                s.erase(s.find(ar[i]*2));
            }
            else if(ar[i]%2==0 && s.find(ar[i]/2)!=s.end())
            {
                s.erase(s.find(ar[i]/2));
            }
            else
            {
                s.insert(ar[i]);
            }
        }
        
        return s.empty();
        
        
    }
};
