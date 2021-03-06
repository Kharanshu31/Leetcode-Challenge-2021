class Solution {
public:
    
    vector<int> t; // segment tree
	vector<int> a; // frequency array
    
    inline int left(int x){
        return (x<<1)+1;
    }
    
    inline int right(int x){
        return (x<<1)+2;
    }
    
    
    void update(int v, int b, int e, int x){
        if(b==e && b==x){
            t[v] = a[b];
            return;
        }
        int m = (b+e)/2;
        if(x<=m)
            update(left(v), b, m, x);
        else
            update(right(v), m+1, e, x); 
        t[v] = t[left(v)] + t[right(v)];
    }
    
    
    int query(int v, int b, int e, int x, int y){    
        if(y<b || x>e)
            return 0;
        if(x<=b && e<=y)
            return t[v];
        int m = (b+e)/2;
        return query(left(v), b, m, x, y) + query(right(v), 1+m, e, x, y);
    }
    
    int createSortedArray(vector<int>& instructions) {
        int N = 1e5+1;
        t.resize(4*N, 0);
        a.resize(N, 0);
        int cost = 0, M = 1e9+7;
        for(auto i: instructions){
			// find subarray sum from 0 to (i-1)
            int x = query(0, 0, N-1, 0, i-1);
			// find subarray sum from (i+1) to (N-1)
            int y = query(0, 0, N-1, i+1, N-1);
            int c = min(x, y);
            cost = (cost + c)%M;
			// update frequency array
            a[i]++;
			// update segment tree
            update(0, 0, N-1, i);
        }
        return cost;
    }
};
