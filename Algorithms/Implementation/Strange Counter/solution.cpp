/*
  Problem: https://www.hackerrank.com/challenges/strange-code/problem
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    
    long currentColumnStrangeStartTime = 3;
    long addedColumnsTimes = 1;
    while (addedColumnsTimes + currentColumnStrangeStartTime <= t){
        addedColumnsTimes += currentColumnStrangeStartTime;
        currentColumnStrangeStartTime *= 2;
    }
    
    return currentColumnStrangeStartTime - (t - addedColumnsTimes);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
