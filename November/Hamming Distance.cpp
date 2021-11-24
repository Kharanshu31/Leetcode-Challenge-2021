class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int mask = 1;
        while(x || y)
        {
            if((x& mask) ^ (y&mask))
                count++;
            x = x>>1;
            y = y>>1;
        }
    
        return count;
    }
};
