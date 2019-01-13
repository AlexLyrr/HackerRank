/*
  Problem: https://www.hackerrank.com/challenges/vector-erase/problem
  
  Theory:
    erase(int position):
      Removes the element present at position.  
      Ex: v.erase(v.begin()+4); (erases the fifth element of the vector v)
    erase(int start,int end):
      Removes the elements in the range from start to end inclusive of the start and exclusive of the end.
      Ex:v.erase(v.begin()+2,v.begin()+5);(erases all the elements from the third element to the fifth element.)
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int vecSize, element, index, leftI, rightI;
    cin >> vecSize;
    vector<int> v;
    for (int i = 0; i < vecSize; i++){
        cin >> element;
        v.push_back(element);
    }
    cin >> index;
    v.erase(v.begin() + index - 1);
    cin >> leftI >> rightI;
    v.erase(v.begin() + leftI - 1, v.begin() + rightI - 1);
    cout << v.size() << endl;
    for (const int &x : v){
        cout << x << " ";
    }
    return 0;
}
