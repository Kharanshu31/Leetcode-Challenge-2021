class Solution {
public:
    int brokenCalc(int x, int y) {
        if(x>y)
            return x-y;
        int ans=0;
        
        while(y>x)
        {
            ans++;
            if(y%2)
                y=(y+1);
            else
                y/=2;
        }
        cout<<" y : "<<y<<"\n";
        
        return ans-y+x;
    }
};
