class Solution {
public:
    bool isIdealPermutation(vector<int>& ar) {
        int n=ar.size();
        if(n<=2)
            return true;
        int mn=ar[n-1];
        for(int i=n-3;i>=0;i--)
        {
            if(ar[i]>mn)
                return false;
            mn=min(mn,ar[i+1]);
        }
        return true;
    }
};
