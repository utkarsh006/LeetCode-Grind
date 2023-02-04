Problem link : https://leetcode.com/problems/design-circular-queue/submissions/

What is a circular Queue?
A Circular Queue is a special version of queue where the last element of the queue is connected to the first element of the queue forming a circle.
The operations are performed based on FIFO (First In First Out) principle. It is also called ‘Ring Buffer’. 

Time Complexity = O(1) for each of the method
Space Completely = O(k) where k is the capacity of the queue

Solution: 
class MyCircularQueue {
public:
    /*
        1. Initialize the queue array and capacity with k.
        2. Initialize the front and rear as -1 since queue is empty currently.
    */
       int front=-1;
            int rear=-1;
            vector<int> arr;
    MyCircularQueue(int k) {
         arr.resize(k,0);
           
    }
  
    /*  1. First, check if the queue is full. If it's full then return false as we cannot insert more elements.
        2. If the queue is not full, then check if it's empty.
        3. If the queue is empty then set front and rear both to 0.
        4. If the rear is pointing at the last index the take rear to the 0th index and insert value there.
        5. If the queue is neither full nor empty ,then simply iterate the rear by one index and insert element.
        6. queue[rear] = value and return true.
    */
    bool enQueue(int value) {
       int k=arr.size();
            cout<<k;
            if(isFull())
                return false;
         if(rear==k-1 )
         {
                 rear=0;
                 arr[rear]=value;
         }
            else
            {++rear;
            arr[rear]=value;
            
            if(front==-1)
                    front++;}
            return true;
    }
    /*  1. First, check if the queue is empty. If it's empty then return false as we cannot delete any element.
        2. If it's not empty, then we will just increase the front and that's it.
        3. But, before increasing the front we have to make sure two things:
            a. If we have only one element, then after it's deletion, the queue will become empty.
                So, after deleting the only element, we will set front and rear to -1.
        4. Return true.
    */
    bool deQueue() {
             int k=arr.size();
            if(front==rear && rear==-1) return false;
        if(front==rear)
        {
               front=-1;
                rear=-1;
                return true;
        }
           else if(front==k-1)
                    front=0;
            else
                    front++;
            return true;
    }
      /*  1. First, check if the queue is empty. If it's empty then return -1.
          2. Else, return the value present at front.
    */
    int Front() {
            return front==-1?-1:arr[front];
    }
     /*  1. First, check if the queue is empty. If it's empty then return -1.
        2. Else, return the value present at rear.
    */
    int Rear() {
        return rear==-1?-1:arr[rear];
    }
     /*  
        1. Just check if the value of front or rear is -1.
        2. If the value is -1 then return true else, return false.
    */
    bool isEmpty() {
            if(rear==-1 || front==-1)
                    return true;
        return false;
    }
     
    /*  1. To check if the queue is full, we will refer to value of front and rear.
        2. If the front points to the 0th index and rear points to last index at any time then, it means the queue is full.
        3. We will just check if front is present just after the rear since the queue is circular.
        4. To do so, we can compare the value of (rear + 1) and front. If they are same, it means the queue is full.
    */
    bool isFull() {
             int k=arr.size();
        if(front==0 && rear==k-1) return true;
            if(rear+1==front) return true;
            return false;
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
