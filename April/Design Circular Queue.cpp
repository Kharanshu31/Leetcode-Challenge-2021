class MyCircularQueue {
    private:
        int n;
        vector<int> v;   
        int beg=0;
        int end=0;
        int sz=0;
public: 
    MyCircularQueue(int k) {
        n=k;
        v=vector<int>(k,0);
    }
    
    bool enQueue(int value) {
        if(sz==n)
            return false;
        v[end]=value;
        end=(end+1)%n;
        sz++;
        return true;
    }
    
    bool deQueue() {
        if(sz==0)
            return false;
        beg=(beg+1)%n;
        sz--;
        return true;
    }
    
    int Front() {
        if(sz==0)
            return -1;
        return v[beg];
    }
    
    int Rear() {
        if(sz==0)
            return -1;
        return v[(end-1+n)%n];
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        return sz==n;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
