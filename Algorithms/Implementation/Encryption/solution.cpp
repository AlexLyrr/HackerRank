/*
 Problem: https://www.hackerrank.com/challenges/encryption/problem
 Time Complexity:  O(n)
 Space Complexity: O(n) 
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    int L = s.length();
    int rows = floor(sqrt(L));
    int columns = ceil(sqrt(L));
    // Find the rows and columns based on the square of L
    if (rows * columns < L){
        if (rows < columns){
            rows++;
        }
        else{
            columns++;
        }
    }

    // Create the grid and leave extra space empty (some unecessary last row columns)
    vector< vector<string> > grid (rows, vector<string> (columns, "")); 
    string answer = "";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (i * rows + j > L)
                break;
            grid[i][j] = s[i * columns + j];
        }
    }

    for (int i = 0; i < columns; i++){
        for (int j = 0; j < rows; j++){
            if (j * columns + i >= L){
                break;
            }
            answer += grid[j][i];
        }
        answer += " ";
    }
    return answer;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    cout << result << "\n";
    fout << result << "\n";

    fout.close();

    return 0;
}
