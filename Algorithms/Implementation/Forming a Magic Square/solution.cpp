/*
  Problem: https://www.hackerrank.com/challenges/magic-square-forming
  Time Complexity: O(1) //There are only 9 combos to check no matter the arrangement
  Space Complexity: O(1) //No dynamically allocated space
*/


#include <bits/stdc++.h>

using namespace std;

const int possiblePermutations[][3][3] = {
    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}}, // 1

    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}}, // 2

    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}}, // 3

    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, // 4

    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}}, // 5

    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, // 6

    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, // 7

    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}, // 8
};

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {

    int minCost = INT_MAX;
    for (int permutation = 0; permutation < 8; permutation++) {
        int permutationCost = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++)
                permutationCost +=
                    abs(s[i][j] - possiblePermutations[permutation][i][j]);
            }
        minCost = min(minCost, permutationCost);
    }
    
    return minCost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    cout << result << "\n";
    fout << result << "\n";

    fout.close();

    return 0;
}
