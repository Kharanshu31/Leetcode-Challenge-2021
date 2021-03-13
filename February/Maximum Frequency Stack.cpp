class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>>pq;
    unordered_map<int,int>m;
    int pos=0;
    FreqStack() {
        
    }
    
    void push(int x) {
        m[x]++;
        pos++;
        pq.push({m[x],{pos,x}});
    }
    
    int pop() {
        pair<int,pair<int,int>>p=pq.top();
        pq.pop();
        int ans=p.second.second;
        m[ans]--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
