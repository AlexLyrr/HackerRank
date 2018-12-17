/*
  Problem: https://www.hackerrank.com/challenges/fair-rations/problem
  
  - If the sum of distributed breads is odd, then the answer is "NO"
  - Else the minimum number of loaves is equal to the sum of distances between 
  people with odd number of loaves in their hands, multiplied by 2.
  
  Time Complexity: O(1)
  Space Complexity: O(1)
*/
  
  
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the fairRations function below.
int fairRations(vector<int> B) {
    int sum = std::accumulate(B.begin(), B.end(), 0);
    int transactions = 0;
    if (sum % 2 != 0){
        return -1;
    }
    else{
        int guyWithOddLeaves = 0;
        bool foundFirstOdd = false;
        for (int i = 0; i < B.size(); i++){
            if ((B[i] % 2 == 1) && !foundFirstOdd){
                guyWithOddLeaves = i;
                foundFirstOdd = true;
                continue;
            }
            if ((B[i] % 2 == 1) && foundFirstOdd){
                transactions += i - guyWithOddLeaves;
                foundFirstOdd = false;
                cout << "Found two guys with odd number of loaves, they are: " << i << " and " << guyWithOddLeaves << endl;
            }
            
        }
    }
    return transactions * 2;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string B_temp_temp;
    getline(cin, B_temp_temp);

    vector<string> B_temp = split_string(B_temp_temp);

    vector<int> B(N);

    for (int i = 0; i < N; i++) {
        int B_item = stoi(B_temp[i]);

        B[i] = B_item;
    }

    int result = fairRations(B);

    if (result == -1)
        fout << "NO" << "\n";
    else
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
