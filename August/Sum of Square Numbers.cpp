class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0;i*i<=c;i++)
        {
            long long j=c-i*i;
            long long x=sqrt(j);
            if(x*x==j)
                return true;
        }
        return false;
    }
};
