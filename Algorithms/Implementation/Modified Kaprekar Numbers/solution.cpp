/*
 Problem: https://www.hackerrank.com/challenges/kaprekar-numbers/problem
 Time Complexity:  O(n)
 Space Complexity: O(1) 
*/ 
 

#include <bits/stdc++.h>
#include <string> // std::string, std::stoi

using namespace std;

bool isKaprekar(int n){
    string s = to_string(n);
    long digits = s.length();
    long n2 = pow(n, 2);
    string s2 = to_string(n2);
    string right = s2.substr(s2.length() - digits);
    string left = s2.substr(0, s2.length() - digits);

    std::string::size_type sz; // alias of size_t
    long part1 = 0, part2 = 0;
    if (right != "")
        part1 = stoi(right, &sz);
    if (left != "")
        part2 = stoi(left, &sz);
    else
        part2 = 0;


    if (part1 + part2 == n)
        return true;
    else
        return false; 

}

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    bool foundAtLeastOne = false;
    for (int i = p; i <= q; i++){
        if (isKaprekar(i)){
            cout << i << " ";
            foundAtLeastOne = true;
        }
    }
    if (!foundAtLeastOne){
      cout << "INVALID RANGE";
    }

}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
