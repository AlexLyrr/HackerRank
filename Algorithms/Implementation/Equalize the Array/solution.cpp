// Problem: https://www.hackerrank.com/challenges/equality-in-a-array/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the equalizeArray function below.
int equalizeArray(vector<int> arr) {

    // Efficient way to find frequencies of each unique value in the std::vector
    std::map<int, int> freq_map;
    // Create a map with the frequencies of all elements
    for (auto const &x : arr)
        ++freq_map[x];
    
    // Find tha maximum frequency
    auto x = std::max_element(freq_map.begin(), freq_map.end(),
    [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; });

    // Return (number of elements) - (highest frequency)
    return arr.size() - (*x).second;
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

    int result = equalizeArray(arr);

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
