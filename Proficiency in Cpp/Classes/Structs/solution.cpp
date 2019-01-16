/*
  Problem: https://www.hackerrank.com/challenges/c-tutorial-struct/problem
    
  Theory:
    struct is a way to combine multiple fields to represent a composite data structure, which further lays
    the foundation for Object Oriented Programming. For example, we can store details related to a student
    in a struct consisting of his age (int), first_name (string), last_name (string) and standard (int). 
    
    struct can be represented as:
      struct NewType {
        type1 value1;
        type2 value2;
        .
        .
        .
        typeN valueN;
      };
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Student{
    int age, standard;
    string first_name, last_name;
} Student;

int main() {
    Student st;
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    
    return 0;
}



     
