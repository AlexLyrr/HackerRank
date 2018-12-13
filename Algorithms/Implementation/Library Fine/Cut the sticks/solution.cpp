/*
    Problem: https://www.hackerrank.com/challenges/cut-the-sticks/problem
    Time Complexity:  O(n ^ 2) worst case is if sticks have length 1, 2, 3, 4, ..., n-1, n
    Space Complexity: O(1) // No dynamic memory allocation
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int findNonZeroMinimum(vector<int> arr){
    int min = INT_MAX;
    bool allZeros = 1;
    for (auto &x : arr){
        if (x > 0 && x < min){
            min = x;
            allZeros = 0;
        }
    }
    if (allZeros){
        min = 0;
    }
    return min;
}

// Complete the cutTheSticks function below.
vector<int> cutTheSticks(vector<int> arr) {

    vector<int> sticksLeft;
    int remainingSticks = arr.size();
    while(remainingSticks != 0){
        // append the number of remaining sticks
        sticksLeft.push_back(remainingSticks);
        remainingSticks = 0;
        // find > 0 minimum length
        int minLength = findNonZeroMinimum(arr);
        if (minLength == 0){
            break;
        }
        // cut the sticks
        for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++){
            if (*it > 0) {
              *it -= minLength;
              if (*it > 0){
                remainingSticks++;
              }
            }
        }
    }
    return sticksLeft;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = cutTheSticks(arr);

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
