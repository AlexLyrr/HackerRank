 /*
  Problem: https://www.hackerrank.com/challenges/bigger-is-greater/problem
  Time Complexity: O(n) // where n is the length of the string
  Space Complexity: O(1) // no extra memory needed
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    string answer(w);
    int indexChange = 0;
    bool changed = false;

    // Go through the string from the end to the beginning
    for (int i = w.size() - 1; i >= 1; i--){
        /* 
        If element i is greater than element i-1 then
        swap element s[i-1] with the smallest element found in the
        range [i, string.end] which is bigger than s[i-1]
        After that sort the characters in range [i, s.end]
        and break the loop. Algorithm finished.
        */ 
        if (w[i] > w[i - 1]){
            int minElementIndex = 0;
            int minValue = 10000;
            for (int j = i; j < w.size(); j++){
                if (w[j] > w[i - 1] && w[j] < minValue){
                    minValue = w[j];
                    minElementIndex = j;
                }
            }
            std::swap(w[i - 1], w[minElementIndex]);
            sort(w.begin() + i, w.end());
            changed = true;
            break;
        }
    }
    if (!changed)
        return "no answer";
    else
        return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        cout << result << "\n";
        fout << result << "\n";
    }

    fout.close();

    return 0;
}
