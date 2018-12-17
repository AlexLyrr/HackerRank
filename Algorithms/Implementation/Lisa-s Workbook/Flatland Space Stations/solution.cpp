/*
  Problem: https://www.hackerrank.com/challenges/flatland-space-stations/problem
  Time Complexity: O(1)
  Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
    int maxDistance = 0;
    int index = 0;
    std::sort(c.begin(), c.end());

    // Calculate distance from cities in the middle of two space stations
    while (index < c.size() - 1){
        if (floor(abs(c[index] - c[index + 1]) / 2.0) > maxDistance) {
            maxDistance = floor(abs(c[index] - c[index + 1]) / 2.0);
        }
        index++;
    }
    // Calculate distance from the first city
    if (c[0] > maxDistance){
        maxDistance = c[0];
    }
    // Calculate distance from the last city
    if (n - c.back() - 1 > maxDistance){
      maxDistance = n - c.back() - 1;
    }

    return maxDistance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

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
