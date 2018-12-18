/*
  Problem: https://www.hackerrank.com/challenges/manasa-and-stones/problem
  Time Complexity: O(n)
  Space Complexity: O(n)
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the stones function below.
set<int> stones(int n, int a, int b) {
    
    set<int> result;

    if (a == b){
        result.insert((n - 1) * a);
        return result;
    }

    if (b < a)
    {
        int temp = b;
        b = a;
        a = temp;
    }

    for (int i = 0; i < n; i++)
        result.insert(i * b + (n - 1 - i) * a);

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int a;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int b;
        cin >> b;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        set<int> result = stones(n, a, b);

        for (std::set<int>::iterator it = result.begin(); it != result.end();                      it++) {
                fout << *it;

                if (it != (result.end())) {
                    fout << " ";
                }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
