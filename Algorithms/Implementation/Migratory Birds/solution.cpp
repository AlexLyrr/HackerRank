/*
    Problem: https://www.hackerrank.com/challenges/migratory-birds/problem
    Time Complexity:  O(n) There are two for loops but second for loop runs a constant (=5) number of times. 
                        Hence second loop can be ignored.
    Space Complexity: O(1) //We are allocating an additional array which is of constant length (=5). So it will not vary with the
                            number of migratory birds. Other dynamically allocated variables remain constant for any input.              
*/


#include <algorithm> // std::count
#include <bits/stdc++.h>
#include <iostream> // std::cout
#include <vector>   // std::vector
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr) {
int selectedType = arr[0];
int maxOccur = 1;
vector<int> birdTypeCounter (10, 0);

for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++){
    birdTypeCounter[*it - 1]++;
}

for (int i = 0; i < 10; i++) {
    if (birdTypeCounter[i] > maxOccur){
        maxOccur = birdTypeCounter[i];
        selectedType = i + 1;
    }
    else if (birdTypeCounter[i] == maxOccur){
        if (i < selectedType){
          selectedType = i + 1;
        }
    }
}

return selectedType;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
