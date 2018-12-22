/*
  Problem: https://www.hackerrank.com/challenges/bomber-man/problem
  Time Complexity: O(1) // it is the same no matter the input
  Space Complexity: O(n)
*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void detonate2(vector<string> &grid, vector<string> &previous_grid) {
  size_t r{grid.size()};
  size_t c{grid[0].size()};

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      if (previous_grid[i][j] == 'O') {
        grid[i][j] = '.';

        if (i + 1 < r)
          grid[i + 1][j] = '.';

        if (i - 1 >= 0)
          grid[i - 1][j] = '.';

        if (j + 1 < c)
          grid[i][j + 1] = '.';

        if (j - 1 >= 0)
          grid[i][j - 1] = '.';
      }
    }
}

void detonate(vector<string> &nextGrid, vector<string> &previousGrid) {
  
  for (int i = 0; i < previousGrid.size(); i++) {
    for (int j = 0; j < previousGrid[0].size(); j++) {
      if (previousGrid[i][j] == 'O') {
        cout << "grid[" << i << "," << j << "] is a bomb\n";
        if (i > 0)
          nextGrid[i - 1][j] = '.';
        if (i < nextGrid.size() - 1)
          nextGrid[i + 1][j] = '.';
        if (j > 0)
          nextGrid[i][j - 1] = '.';
        if (j < nextGrid[0].size() - 1)
          nextGrid[i][j + 1] = '.';
        nextGrid[i][j] = '.';
      }
    }
  }
}

// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) {
    

    vector<string> initialGrid{grid};
    vector<string> fullGrid(grid.size(), string(grid[0].size(), 'O'));
    vector<string> patternAGrid{fullGrid}, patternBGrid{fullGrid};

    detonate(patternAGrid, initialGrid);
    detonate(patternBGrid, patternAGrid);

    int k{n % 4};

    if (n == 1)
      return initialGrid;

    if (k == 0 || k == 2)
      return fullGrid;
    else if (k == 3)
      return patternAGrid;
    else
      return patternBGrid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

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
