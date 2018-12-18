/*
  Problem: https://www.hackerrank.com/challenges/happy-ladybugs/problem
  Time Complexity: O(n)
  Space Complexity: O(n)
  
  First check if all the lady bugs are happy. If not, then 
  find if there is any space available. Also check the
  frequency of the elements.

  - If the lady bugs are happy return "YES"
  - Else if any of the frequencies is equal to 1, then return "NO"
  - Else if there is no space, then return "NO"
  - Else if there is space, then return "YES"
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    std::map <int, int> frequencies;
    bool spaceFree = false;
    bool sequenceGood = true;
    for (int i = 0; i < b.length(); i++){
        if (b[i] == '_'){
            spaceFree = true;
        }
        if (i == 0){
            if (b[i] != b[i+1]){
                sequenceGood = false;
            }
        }
        else if (i == b.length() - 1){
            if (b[i-1] != b[i]){
                sequenceGood = false;
            }
        }
        else{
          if ((b[i] != b[i - 1]) && (b[i] != b[i + 1])){
              sequenceGood = false;
          }
        }
        if (b[i] != '_')
            ++frequencies[b[i]];
    }
    bool evenPairs = true;
    for (auto const &p : frequencies) {
        if (p.second == 1)
            evenPairs = false; 
    }
    if (sequenceGood){
        return "YES";
    }
    else if (!evenPairs){
        return "NO";
    }
    else if (spaceFree){
        return "YES";
    }
    else{
        return "NO";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
