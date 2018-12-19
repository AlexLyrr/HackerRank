/*
  Problem: https://www.hackerrank.com/challenges/3d-surface-area/problem
  Time Complexity: O(nX, nY) // where nX and nY are the number of cells in the X and Y axis respectively
  Space Complexity: O(1) // we don't need any extra space except the one reserved already by the main
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) {

    int top = 0, bottom = 0, front = 0, back = 0, left = 0, right = 0;
    int totalSurface = 0, currentCubeSurface = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            currentCubeSurface = 0;
            top = 1;
            bottom = 1;
            // First we'll check for the front
            if (j > 0 && A[i][j-1] < A[i][j]){
                front = A[i][j] - A[i][j-1];
            }    
            else if (j == 0){
                front = A[i][j];
            }
            else{
                front = 0;
            }
            // Then we check the back
            if (j < A[0].size() - 1 && A[i][j+1] < A[i][j]){
                back = A[i][j] - A[i][j+1];
            }    
            else if (j == A[0].size() - 1){
                back = A[i][j];
            }
            else{
                back = 0;
            }
            // Then we check the left
            if (i > 0 && A[i-1][j] < A[i][j]){
                left = A[i][j] - A[i-1][j];
            }    
            else if (i == 0){
                left = A[i][j];
            }
            else{
                left = 0;
            }
            // Then we check the right
            if (i < A.size() - 1  && A[i+1][j] < A[i][j]){
                right = A[i][j] - A[i+1][j];
            }    
            else if (i == A.size() - 1){
                right = A[i][j];
            }
            else{
                right = 0;
            }   
            currentCubeSurface = top + bottom + left + right + front + back;
            totalSurface += currentCubeSurface;
        }
    }

    return totalSurface;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
