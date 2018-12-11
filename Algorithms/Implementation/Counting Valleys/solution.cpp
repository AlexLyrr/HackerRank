
/*
    Problem: https://www.hackerrank.com/challenges/counting-valleys
    Time Complexity:  O(n)
    Space Complexity: O(1)
*/


#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int altitude = 0, counter = 0, altitudePrev = 0;
    for (const char &c : s) {
        if (c == 'U'){
            altitudePrev = altitude;
            altitude++;
        }
        else if (c == 'D'){
          altitudePrev = altitude;
          altitude--;
        }
        if (altitude == 0 && altitudePrev == -1){
            counter++;
        }
    }
    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
