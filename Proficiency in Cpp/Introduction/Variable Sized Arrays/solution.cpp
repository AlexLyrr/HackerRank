#include <cmath>
/*
  Problem: https://www.hackerrank.com/challenges/variable-sized-arrays/problem
  
  We want to create multidimensional vectors of different sized. That is why we use
  the vector container in order to solve this problem.
*/

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream> 
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int NOarrays = 0, q, element;
    std::string line;
    
    // Read first line which contains number of arrays and queries
    cin >> NOarrays >> q;
    
    vector<vector<int>> arrays(NOarrays);
    std::getline(std::cin, line); // Ignore the first line
        
    // Create variable sized arrays
    for (int i = 0; i < NOarrays; i++){
        int arraySize;
        cin >> arraySize;
        for (int j = 0; j < arraySize; j++){
            cin >> element;
            arrays[i].push_back(element);
        }
    }

    // Perform the queries
    for (int i = 0; i < q; i++){
        int arrIndex, elemIndex;
        cin >> arrIndex >> elemIndex;
        cout << arrays[arrIndex][elemIndex] << std::endl;
    }

    return 0;
}

