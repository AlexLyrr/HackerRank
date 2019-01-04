// Problem: https://www.hackerrank.com/challenges/almost-sorted/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int isReversible(vector<int> arr, vector<int> arrSorted, int begin, int end) {
    for(int i = begin, j = end; i <= end; i++, j--) {
        if(arr[i] != arrSorted[j])
            return 0;        
    }
    return 1;
}

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    
    vector<int> arrSorted{arr};
    std::sort(arrSorted.begin(), arrSorted.end());

    int diff = 0;
    int begin = -1, end = -1;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] != arrSorted[i]) {
            diff++;
            if(begin == -1) {
                begin = i;    
            } else
                end = i;
        } 
    }
    if(diff == 0) {
        cout << "yes";
    } else if(diff == 2) {
        cout << "yes\nswap " << begin+1 << " " << end+1;
    } else if(diff > 2) {
        if(isReversible(arr, arrSorted, begin, end)) {
            cout << "yes\nreverse " << begin+1 << " " << end+1;
        } else {
            cout << "no";
        }
    }

}

int main()
{
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

    almostSorted(arr);

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
