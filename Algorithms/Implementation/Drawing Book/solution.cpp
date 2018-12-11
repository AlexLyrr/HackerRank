
/*
   Problem: https://www.hackerrank.com/challenges/drawing-book/problem
   Time Complexity:  O(n)
   Space Complexity: O(1)
*/


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    int minTurns = 0, turns = 0, currentP = 0;
    if (p == 1 || p == n || (n % 2 != 0 && p == n - 1)){
        minTurns = 0;
    }
    else if (p <= n/2){
        currentP = 1;
        while (currentP < p) {
            turns++;
            currentP += 2;
        }
    }
    else if (p > n/2){
        currentP = n - 1;
        while (currentP > p) {
            turns++;
            currentP -= 2;
        }
    }
    return turns;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
