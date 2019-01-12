/*
  Problem: https://www.hackerrank.com/challenges/c-tutorial-functions/problem
  
  Theory:
    Functions are a bunch of statements glued together. A function is provided with
    zero or more arguments, and it executes the statements on it. Based on the return 
    type, it either returns nothing (void) or something.
    
    A sample syntax for a function is:
       return_type function_name(arg_type_1 arg_1, arg_type_2 arg_2, ...) {
        ...
        ...
        ...
        [if return_type is non void]
            return something of type `return_type`;
      }
*/

#include <iostream>
#include <cstdio>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

int max_of_four(const int &a, const int &b, const int &c, const int &d){
    return max(max(max(a, b), c), d);
}


int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
