class Solution {
public:
    int minOperations(int n) {
        if(n%2==0)
            return ((n-2)/2+1)*n/2;
        else
            return ((n-3)/2+1)*(n+1)/2;
    }
};
