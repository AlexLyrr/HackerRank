/*
  Problem: https://www.hackerrank.com/challenges/arrays-introduction/problem
  
  Theory:
    An array is a series of elements of the same type placed in contiguous memory 
    locations that can be individually referenced by adding an index to a unique identifier.
    
    Declaration:
      int arr[10]; //Declares an array named arr of size 10, i.e; you can store 10 integers.
    
    Accessing elements of an array:
      Indexing in arrays starts from 0.So the first element is stored at arr[0],the second element at arr[1]...arr[9]
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int arr_size;
    cin >> arr_size;

    int arr[arr_size];
    for (int i = 0; i < arr_size; i++){
        cin >> arr[i];
    }
    for (int i = arr_size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    return 0;
}

