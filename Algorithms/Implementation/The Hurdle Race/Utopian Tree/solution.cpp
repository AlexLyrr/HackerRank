/*
  https://www.hackerrank.com/challenges/utopian-tree/problem
  Time Complexity:  O(n)
  Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the utopianTree function below.
int utopianTree(int n) {
    bool reverse = 0;
    int height = 0;
    while (n-- >= 0){
        if (!reverse){
            height += 1;
            reverse = !reverse;
        }
        else{
            height *= 2;
            reverse = !reverse;
        }
    }
    return height;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = utopianTree(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
