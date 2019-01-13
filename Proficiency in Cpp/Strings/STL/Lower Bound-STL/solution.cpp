/*
  Problem: https://www.hackerrank.com/challenges/cpp-lower-bound/problem
  
  Theory: 
    std::lower_bound -> http://www.cplusplus.com/reference/algorithm/lower_bound/
    std::distance -> http://www.cplusplus.com/reference/iterator/distance/
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int vecSize, element, val;
    vector<int> v;
    cin >> vecSize;
    for (int i = 0; i < vecSize; i++){
        cin >> element;
        v.push_back(element);
    }
    std::vector<int>::iterator low;
    
    // Drop the number of queries..
    cin >> val;
    // Start the queries
    while (cin >> val){
        low = std::lower_bound (v.begin(), v.end(), val); // 
        if (val == *low){
            cout << "Yes " << std::distance(v.begin(), low) + 1 << endl;
        } 
        else{
            cout << "No " << std::distance(v.begin(), low) + 1 << endl;
        }
    }
    return 0;
}
