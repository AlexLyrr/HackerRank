/*
  Problem: https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
  
  This problem has nothing to do with polymorphism as the main() function does not use the abstract class at all.
  A pointer to the base class should be used that points to a LRUCache object. That way we would have to override
  the pure virtual functions defined in the abstract class.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
    public:
    LRUCache() = default;
    LRUCache(int capacity) {cp = capacity;}
    
    void set(int k, int v) override
    {
        Node *N;        
        if(mp.empty()) //No nodes 
        {
            N = new Node(k,v);
            tail = head = N;
            mp[k] = N;
        }
        else{
            auto it = mp.find(k);
                
            if(it != mp.end()) // If found then: 
            {
                it->second->value = v; // Set new value
                
                if(head != it->second) // If NOT head:
                {
                    it->second->prev->next = it->second->next;    
                    if(tail == it->second) // If it is tail move tail
                        tail = tail->prev;
                    else                  
                        it->second->next->prev = it->second->prev;
                    
                    it->second->next = head;
                    it->second->prev = NULL;
                    head->prev = it->second;
                    head = it->second;
                }
            }
            else // Insert the new node in the list
            {
                N = new Node(NULL, head, k, v); // Node is inserted in the front
                head->prev = N; // Update the head ptr 
                head = N;
                mp[k] = N;
                
                if(mp.size() > cp) // If capacity is exceeded delete the current tail
                {
                    tail = tail->prev;
                    mp.erase(tail->next->key);  // Delete it from the hash table
                    delete tail->next; // Delete the Node object pointed by tail
                    tail->next = NULL;
                }
                
            }
        }
    }

    int get(int k) override
    {
        auto it = mp.find(k);
        if(it != mp.end())
            return it->second->value;
        else
            return -1;
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
