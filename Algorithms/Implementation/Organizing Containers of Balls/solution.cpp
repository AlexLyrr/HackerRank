// Problem: https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> containers) {

    int numContainers = containers.size(), numTypes = containers.size();
    bool possible = true;
    for (int i = 0; i < numContainers; i++){
        int totalBalls = std::accumulate(containers[i].begin(), containers[i].end(), 0);
        int numberOfSwaps = totalBalls - containers[i][i];
        int ballsMiss = 0;
        for (int j = 0; j < numTypes; j++) {
                if (i != j){
                    ballsMiss += containers[j][i];
                }
        }
        if (ballsMiss != numberOfSwaps){
            possible = false;
            break;
        }
    }

    if (possible){
        return "Possible";
    }
    else{
        return "Impossible";
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
