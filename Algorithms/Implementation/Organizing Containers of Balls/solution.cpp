// Problem: https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> containers) {


    long numContainers = containers.size(), numTypes = containers.size();
    bool possible = true;
    cout << "There are " << numContainers << " containers and " << numTypes << " types. \n";
    vector<long long> containersCapacity (numContainers, 0);
    vector<long long> typesTotalBalls (numTypes, 0);
    
    for (int i = 0; i < numContainers; i++){
        for (int j = 0; j < numContainers; j++) {
          containersCapacity[i] += containers[i][j];
          typesTotalBalls[i] += containers[j][i];
        }
    }
    std::sort(containersCapacity.begin(), containersCapacity.end());
    std::sort(typesTotalBalls.begin(), typesTotalBalls.end());
    for (int i = 0; i < numContainers; i++){
        if (containersCapacity[i] != typesTotalBalls[i]){
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

        cout << result << "\n";

        fout << result << "\n";

    }

    fout.close();

    return 0;
}
