class MyHashSet {
public:
int N=1000001;
vector<bool>st;
    MyHashSet() {
        st.assign(N,0);
    }
    
    void add(int key) {
        st[key]=1;
    }
    
    void remove(int key) {
        st[key]=0;
    }
    
    bool contains(int key) {
        return st[key]==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */