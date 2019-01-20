/*
  Problem: https://www.hackerrank.com/domains/cpp?filters%5Bsubdomains%5D%5B%5D=cpp-strings&badge_type=cpp
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    // Print length of strings
    cout << a.length() << " " << b.length() << endl;
    
    // Print concatenation of strings
    cout << a + b << endl;
    
    // Swap first character and print the strings
    swap( a[0], b[0] );
    cout << a << ' ' <<  b << endl;
    
    return 0;
}
