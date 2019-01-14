/*
  Problem: https://www.hackerrank.com/challenges/cpp-sets/problem
  
  Theory:
    Sets are a part of the C++ STL. Sets are containers that store unique elements following a specific order. 
    Here are some of the frequently used member functions of sets:
      - Declaration:
        set<int>s; //Creates a set of integers.
      - Size:
        int length=s.size(); //Gives the size of the set.
      - Insert:
        s.insert(x); //Inserts an integer x into the set s.
      - Erasing an element:
        s.erase(val); //Erases an integer val from the set s.
      - Finding an element:
        set<int>::iterator itr=s.find(val); //Gives the iterator to the element val if it is found otherwise returns s.end() .
        Ex: set<int>::iterator itr=s.find(100); //If 100 is not present then it==s.end().
    
    More about sets: http://www.cplusplus.com/reference/set/set/
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int q, type, element;
    cin >> q;
    std::set<int> myset;
    std::set<int>::iterator it;
    std::pair<std::set<int>::iterator,bool> ret;
    while (cin >> type >> element){
        switch(type) {
        case 1: 
            myset.insert(element);
            break;
        case 2: 
            myset.erase(element);
            break;
        case 3: 
            it = myset.find(element);
            if (it == myset.end()){
                cout << "No" << endl;
            }
            else{
                cout << "Yes" << endl;
            }
            break;
        default:
            break;
        }
    }   
    
    return 0;
}



