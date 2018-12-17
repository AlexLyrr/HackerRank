/*
  Problem: https://www.hackerrank.com/challenges/cavity-map/problem
  Time Complexity: O(n ^ 2)
  Space Complexity: O(1) // no additional space for our function
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> grid) {
    for (int rows = 1; rows < grid.size() - 1; rows++){
        for (int columns = 1; columns < grid.size() - 1; columns++){
          if ((grid[rows][columns] > grid[rows][columns - 1]) &&
              (grid[rows][columns] > grid[rows][columns + 1]) &&
              (grid[rows][columns] > grid[rows - 1][columns]) &&
              (grid[rows][columns] > grid[rows + 1][columns])){
                  grid[rows].replace(columns,1,"X");
              }
        }
    }

    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
