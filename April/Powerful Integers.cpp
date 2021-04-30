class Solution {
public:
    
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int>s;
        if(x!=1 && y!=1)
        {
            int a=1,b=1;
            while(b<bound)
            {
                a=1;
                while(a<=bound)
                {
                    s.insert(a+b);
                    a*=x;
                }
                b*=y;
            }
            a=1,b=1;
            while(a<bound)
            {
                b=1;
                while(b<=bound)
                {
                    s.insert(a+b);
                    b*=y;
                }
                a*=x;
            }
        }
        else if(x==1 && y==1)
        {
            if(bound>=2)
                return {2};
            else
                return {};
        }
        else
        {
            if(x==1)
            {
                int b=1;
                while(b<=bound)
                {
                    s.insert(b+1);
                    b*=y;
                }
            }
            else
            {
                int b=1;
                while(b<=bound)
                {
                    s.insert(b+1);
                    b*=x;
                }
            }
        }
        
        vector<int>ans;
        for(int i=1;i<=bound;i++)
        {
            if(s.find(i)!=s.end())
                ans.push_back(i);
        }
        return ans;
    }
};
