/*Problem :
Design a HashMap without using any built-in hash table libraries.
*/

/* Approach 1:
To solve this issue "easily," just make an array that is big enough to hold all possible combinations of keys.
Since the allowable key range is non-negative and limited to 106, which is manageable,
this appears to be the original solution that was intended.
*/

class MyHashMap
{
public:
   //defining the vector
    vector<int>v;
    MyHashMap()
    {
	// as max we can have the value of key up to 10^6
        v=vector<int>(1000001,-1);
    }
    //O(1)
    void put(int key, int value)
    {
	//replacing key with -1 to its new value
        v[key]=value;
    }
    //O(1)
    int get(int key)
    {
	// returning the value stored at key'th index.
	// the vector is initialized with -1 there is no need to check for values
        return v[key];
    }
    //O(1)
    void remove(int key)
    {
	// removing the value and putting -1
	//-1 indicate no value at that index or key
        v[key]=-1;
    }
};



/* Approach 2:
A hash map can be designed and implemented in a variety of ways, ranging from simple to complicated.
Because it is simple to create and comprehend, we will use a fundamental hash function and a different chaining mechanism in this solution to handle collisions.
The load factor of the hash map, which is equal to the number of values in the hash map divided by the size of the hash map, should be 0.75,
so in this solution, we will use 10^4 / 0.75 = 13333.
*/

class MyHashMap
{
private:
    int maxn = 13333;
    struct Node
    {
        int key;
        int val;
        Node* prev;
        Node* next;
    };
    Node* hash_map[13333];
public:
    //Initializing the data structure here.
    MyHashMap()
    {
        for (int i=0;i<maxn;++i)
            hash_map[i] = NULL;
    }
    //value will always be non-negative.
    void put(int key, int value)
    {
        int hash_code = key % maxn;
        Node* curr = hash_map[hash_code];
        if (curr==NULL)
            {
            hash_map[hash_code] = new Node;
        	hash_map[hash_code]->key = key;
            hash_map[hash_code]->val = value;
            hash_map[hash_code]->next = NULL;
            hash_map[hash_code]->prev = NULL;
        }
        else
        {
            Node* prev = NULL;
            while (curr!=NULL)
            {
                if (curr->key == key) break;
                prev = curr;
                curr = curr->next;
            }
            if (curr!=NULL) curr->val = value;
            else
            {
                curr = new Node;
                curr->key = key;
                curr->val = value;
                curr->next = NULL;
                curr->prev = prev;
                prev->next = curr;
            }
        }
    }
    //Returning the value to which the specified key is mapped,
    //or -1 if this map contains no mapping for the key
    int get(int key)
    {
        int hash_code = key % maxn;
        Node* curr = hash_map[hash_code];
        while (curr!=NULL)
            {
            if (curr->key == key) return curr->val;
            curr = curr->next;
        }
        return -1;
    }
    //Removing the mapping of the specified value key if this map contains a mapping for the key
    void remove(int key)
    {
        int hash_code = key % maxn;
        Node* curr = hash_map[hash_code];

        while (curr!=NULL)
            {
            if (curr->key==key)
            {
                if (curr->prev==NULL && curr->next==NULL)
                {
                    delete curr;
                    hash_map[hash_code] = NULL;
                }
                else if (curr->prev==NULL)
                {
                	hash_map[hash_code] = curr->next;
                	hash_map[hash_code]->prev = NULL;
                	delete curr;
                }
                else if (curr->next==NULL)
                {
                	curr->prev->next = NULL;
                	delete curr;
                }
                else
                    {
                	curr->prev->next = curr->next;
                	curr->next->prev = curr->prev;
                    delete curr;
                }
                break;
            }
            curr = curr->next;
        }
    }
};

/*
Time : put() - O(1), remove() - O(1), get() - O(1)
Space : O(n)
*/
