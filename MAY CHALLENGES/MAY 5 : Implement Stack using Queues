class MyStack {
public:
    queue<int> q;
    queue<int> p;
    
    MyStack() {
       
    }
    
    void push(int x)
    {
      q.push(x);    
    }
    
    int pop() 
    {
        
        while(q.size()!=1)
        {     // push all other elements in the other queue except the last one
            p.push(q.front());
            q.pop();
        }
        
        int y = q.front();
        q.pop();                  // pop the last element but dont put it in other queue
        
        while(p.size()!=0)
        {
            q.push(p.front());     //  put all other elements back in first queue
            p.pop();
        }
        
        return y;
        
    }
    
    int top() 
    {
        
        int k = pop();         
        // top can be seen as just a pop function followed by a push 
    // pop gives last element and remove it from queue so if we put it back , we can get the functionality
        q.push(k);
        
        return k;
        
    }
    
    bool empty() {
        
        return q.size()==0;
    }
};
