/*
  Problem: https://www.hackerrank.com/contests/projecteuler/challenges/euler001/submissions/code/1312480856
  
  Time Complexity: O(1)
  Space Complexity: O(1)
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long multiplesOfThreeAndFive(int n) {
    long long sum = 0;
    long long multiplesOfThree = std::ceil(n / 3.0) - 1;
    long long multiplesOfFive = std::ceil(n / 5.0) - 1;
    long long multiplesOfFifteen = std::ceil(n / 15.0) - 1;
    // We need to make use of the fact that: 1+2+3+4+…+N = (N*(N+1)/2)
    return (3 * multiplesOfThree * (multiplesOfThree + 1)/2)
            + (5 * multiplesOfFive * (multiplesOfFive + 1)/2)
            - (15 * multiplesOfFifteen * (multiplesOfFifteen + 1)/2);
    
    return sum;    
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << multiplesOfThreeAndFive(n) << endl;
    }
    return 0;
}
