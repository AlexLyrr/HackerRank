/*
  Problem: https://www.hackerrank.com/challenges/repeated-string/problem
  Time Complexity: O(1)
  Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long sumOfAlpha;
    if (s.size() >= n){
        sumOfAlpha = count(s.begin(), s.begin() + n, 'a');
    } else {
      int remainChars = n % s.size();
      sumOfAlpha = floor(n / s.size()) * count(s.begin(), s.end(), 'a') +
                   count(s.begin(), s.begin() + remainChars, 'a');
    }
    return sumOfAlpha;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
