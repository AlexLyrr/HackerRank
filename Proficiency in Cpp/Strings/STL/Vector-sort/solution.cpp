/*
  Problem: https://www.hackerrank.com/challenges/vector-sort/problem
  
  Theory:
    Declaration:
      vector<int>v; (creates an empty vector of integers)
    Size:
      int size=v.size();
    Pushing an integer into a vector:
      v.push_back(x);(where x is an integer.The size increases by 1 after this.)
    Popping the last element from the vector:
      v.pop_back(); (After this the size decreases by 1)
    Sorting a vector:
      sort(v.begin(),v.end()); (Will sort all the elements in the vector)
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, element;
    cin >> N;
    vector<int> v;
    // Build the vector
    while (cin >> element){
        v.push_back(element);
    }
    sort(v.begin(), v.end());
    for (const int &x : v){
        cout << x << " ";
    }
    return 0;
}
