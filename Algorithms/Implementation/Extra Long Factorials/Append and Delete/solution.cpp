/*
  Problem: https://www.hackerrank.com/challenges/append-and-delete
  Time Complexity: O(n)
*/

#include <bits/stdc++.h>

using namespace std;

int DiffersAtIndex(string s1, string s2) {

  int index = 0;
  while (index < s1.length() && s1[index] == s2[index])
    index++;

  return index;
}

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    
    long index = DiffersAtIndex(s, t);
    
    int remUnmatchedS = s.length() - index;
    int remUnmatchedT = t.length() - index;
    if (
        (remUnmatchedS + remUnmatchedT == k) ||
        (remUnmatchedS + remUnmatchedT < k && (remUnmatchedS + remUnmatchedT - k) % 2 ==                                                                0) ||
        (s.length() + t.length() <= k)
        )
         
        {
            return "Yes";
        }
        else{
            return "No";
        }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
