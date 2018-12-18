/*
  Problem: https://www.hackerrank.com/challenges/the-grid-search/problem
*/

#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<string> split_string(string);

// Complete the gridSearch function below.
string gridSearch(vector<string> G, vector<string> P) {

  // First check for the first row of the pattern
  std::string patternRow1 = P[0];
  for (int i = 0; i < G.size(); i++) {
    std::size_t foundFirst = 0;
    foundFirst = G[i].find(patternRow1, foundFirst);
    /*
        If the first row is found, then check for the 
        next rows of the pattern. If there is a 
        mismatch continue by searching again for
        the first row of the pattern in the rest
        of the current grid row. If this is not found,
        then move on with the next line of the grid.
    */
    while (foundFirst != std::string::npos) {
      cout << "Found the first row at position i = " << i << " and index is "
           << foundFirst << endl;
      if (P.size() == 1) {
        return "YES";
      } else {
        if (G.size() - i - 1 < P.size() - 1) {
          return "NO";
        }
        for (int j = 1; j < P.size(); j++) {
          string strGridRaw = G[i + j].substr(foundFirst, P[0].size());
          cout << strGridRaw << endl;
          std::size_t foundNext = strGridRaw.find(P[j]);
          if (foundNext == std::string::npos) {
            break;
          }
          if (j == P.size() - 1) {
            return "YES";
          }
        }
      }
      foundFirst = G[i].find(patternRow1, foundFirst + 1);
    }
  }
  return "NO";
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string RC_temp;
    getline(cin, RC_temp);

    vector<string> RC = split_string(RC_temp);

    int R = stoi(RC[0]);

    int C = stoi(RC[1]);

    vector<string> G(R);

    for (int i = 0; i < R; i++) {
      string G_item;
      getline(cin, G_item);

      G[i] = G_item;
    }

    string rc_temp;
    getline(cin, rc_temp);

    vector<string> rc = split_string(rc_temp);

    int r = stoi(rc[0]);

    int c = stoi(rc[1]);

    vector<string> P(r);

    for (int i = 0; i < r; i++) {
      string P_item;
      getline(cin, P_item);

      P[i] = P_item;
    }

    string result = gridSearch(G, P);

    fout << result << "\n";
  }

  fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

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

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
