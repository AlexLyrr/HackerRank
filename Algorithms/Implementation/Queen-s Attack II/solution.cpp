/*
  Problem: https://www.hackerrank.com/challenges/queens-attack-2/problem
  Time Complexity: O(k) // We go through every obstacle, this cannot be avoided
  Space Complexity: O(1) // no additional allocation
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);



// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int left = c_q - 1, right = n - c_q, up = n - r_q, down = r_q - 1;
    int leftUp = min(up, left), leftDown = min(down, left), rightUp = min(up, right),
        rightDown = min(down, right);

    cout << "Our chess board is " << n << " X " << n << " size. \n";
    cout << "Queen is at position (" << r_q << "," << c_q << ") \n";
    cout << "Queen can move " << up << ", " << down << ", " << left << ", "
         << right << ", " << leftUp << ", " << leftDown << ", " << rightUp << ", " <<           rightDown << " up, down, left, right, leftUp, leftDown, rightUp, rightDown              respectively. \n";

    int gap = 0;
    for (auto &obstacle : obstacles){
        // Left and right
        if (obstacle[0] == r_q){
            if (obstacle[1] < c_q){
                gap = (c_q - (obstacle[1] + 1));
                if (gap < left){
                    left = gap;
                }
            }
            if (obstacle[1] > c_q) {
                gap = (obstacle[1] - (c_q + 1));
                if (gap < right) {
                    right = gap;
                }
            }
        }
        // Down and Up
        if (obstacle[1] == c_q) {
          if (obstacle[0] < r_q) {
            gap = (r_q - (obstacle[0] + 1));
            if (gap < down) {
              down = gap;
            }
          }
          if (obstacle[0] > r_q) {
            gap = (obstacle[0] - (r_q + 1));
            if (gap < up) {
              up = gap;
            }
          }
        }
        // Diagonials
        if (abs(obstacle[0] - r_q) == abs(obstacle[1] - c_q)) {
          if (obstacle[0] < r_q && (obstacle[1] < c_q)) {
            gap = (r_q - (obstacle[0] + 1));
            if (gap < leftDown) {
              leftDown = gap;
            }
          }
          if (obstacle[0] > r_q && (obstacle[1] < c_q)) {
            gap = (obstacle[0] - (r_q + 1));
            if (gap < leftUp) {
              leftUp = gap;
            }
          }
          if (obstacle[0] < r_q && (obstacle[1] > c_q)) {
            gap = (r_q - (obstacle[0] + 1));
            if (gap < rightDown) {
              rightDown = gap;
            }
          }
          if (obstacle[0] > r_q && (obstacle[1] > c_q)) {
            gap = (obstacle[1] - (c_q + 1));
            if (gap < rightUp) {
              rightUp = gap;
            }
          }
        }
    }

    return up + down + left + right + leftUp + leftDown + rightUp + rightDown; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
