class NestedIterator {
    vector<int> v;
    int pos=0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        flatten(nestedList);
    }
    
    void flatten(vector<NestedInteger> &nestedList)
    {
        for(auto x : nestedList)
        {
            if(x.isInteger())
                v.push_back(x.getInteger());
            else
                flatten(x.getList());
        }
    }
    
    int next()
    {
        return v[pos++];
    }
    
    bool hasNext()
    {
        return pos < v.size();
    }
};
