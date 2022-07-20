class MyHashSet {
public:
           vector<int> m;
           int size;
    MyHashSet() 
    {   
        size = 1e6+1;
        m.resize(size);
    }
    
    void add(int key) 
    {
        m[key]=1;
    }
    
    void remove(int key) 
    {
        m[key]=0;
    }
    
    bool contains(int key) 
    {
        return m[key];
    }
