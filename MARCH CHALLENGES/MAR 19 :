https://leetcode.com/problems/maximum-frequency-stack/discuss/1861911/C%2B%2B-or-Easy-solution-with-explanation-or-Simple-solution

class FreqStack {
public:
    //This will store the count of each element
    unordered_map<int,int> frequency;
    //This maps the elements which have same count
    //But the element that come last will come first of same count
    unordered_map<int,stack<int>> group_stack;
    //Maximum frequency possible
    int max_frequency=0;
    FreqStack() {
        
    }
    //Push elements in the stack
    void push(int val) {
        //Increment the count
        frequency[val]++;
        //Check is this element occurs maximum time
        max_frequency=max(max_frequency,frequency[val]);
        //Map the element with its count
        group_stack[frequency[val]].push(val);
    }
    
    int pop() {
        //Find the max occurence element
        int top_max_frequency=group_stack[max_frequency].top();
        //Remove it from stack
        group_stack[max_frequency].pop();
        //Decrement its count
        frequency[top_max_frequency]--;
        //If there is no element of maximum frquency the decrement max_frequency
        if(group_stack[max_frequency].size()==0)
            max_frequency--;
        return top_max_frequency;
    }
};
