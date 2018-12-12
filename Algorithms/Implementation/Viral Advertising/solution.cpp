/*
  Problem: https://www.hackerrank.com/challenges/strange-advertising/problem
  Time Complexity: O(n)
  Space Complexity: O(1)
  */
  
#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int recipients = 5;
    int likes = 0;
    while (n-- > 0){
        likes += floor(recipients / 2);
        recipients = floor(recipients / 2) * 3; 
    }
    return likes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
