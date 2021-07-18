// https://practice.geeksforgeeks.org/problems/lru-cache/1#

// https://www.geeksforgeeks.org/static-keyword-cpp/

// Using DLL and hashing.



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way



/*
Static member functions are allowed to access only the static data members or 
other static member functions, they can not access the non-static data 
members or member functions of the class.

This is because intially memeber argument was defined as static which
caused error so I changed it;
*/
class LRUCache
{
    private:

    public:
    class Node
    {
        // A DLL node
        public:
        int key;
        int value;
        Node* next = NULL;
        Node* prev = NULL;
        Node(int ke,int val)
        {
            // constructor
            key = ke;
            value = val;
        }
        
    };
    int capacity;
    Node* head;
    Node* tail;
    map<int,Node*> mp;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* temp)
    {
        // add new node at the head
        Node* dumy = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = dumy;
        dumy->prev = temp;
    }
    
    
    void deleteNode(Node* temp)
    {
        Node* delprev = temp->prev;
        Node* delnext = temp->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        int res;
        if(mp.find(key) != mp.end())
        {
            Node* found = mp[key];
            mp.erase(key);
            res = found->value;
            deleteNode(found);
            addNode(found);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(mp.find(key) != mp.end())
        {
            Node* replace = mp[key];
            mp.erase(key);
            deleteNode(replace);
        }
        
        if(mp.size() == capacity)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key] = head->next;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
