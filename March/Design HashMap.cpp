class MyHashMap {
public:
    /** Initialize your data structure here. */
    int h[1000001];
    MyHashMap() {
        memset(h,-1,sizeof(h));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        h[key]=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return h[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        h[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
