
/*
 Problem: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
 Time Complexity:  O(n + m) - One scan required to get non-duplicate scores (n). m iterations required to decide
                        Alice's rank after each level.
 Space Complexity: O(n) - An additional array for entire input set is required to store non-duplicate scores.
        
*/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    
    // sort and erase double elements
    std::sort(scores.begin(), scores.end(), greater<int>());
    scores.erase( unique( scores.begin(),scores.end() ), scores.end() );
    std::vector<int> playersRanks(scores.size(), 0);
    std::vector<int> aliceRanks(alice.size(), 0);

    // rank the players
    int rank = 1;
    for (int i = 0; i < scores.size(); i++) {
        playersRanks[i] = rank++;
    }

    // rank alice scores
    int scoresIndex = 0;
    rank = 1;
    for (int j = alice.size() - 1; j >= 0; j--) {
            while(alice[j] < scores[scoresIndex]){
                if (scoresIndex < scores.size() - 1){
                    scoresIndex++;
                    if (scores[scoresIndex] != scores[scoresIndex - 1]){
                        rank++;
                    }
                }
                else {
                    break;
                }  
            }
            if (alice[j] < scores[scoresIndex]){
                aliceRanks[j] = rank + 1;
            }
            else{
                aliceRanks[j] = rank;
            }
            
    }       

    return aliceRanks;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int scores_count;
  cin >> scores_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string scores_temp_temp;
  getline(cin, scores_temp_temp);

  vector<string> scores_temp = split_string(scores_temp_temp);

  vector<int> scores(scores_count);

  for (int i = 0; i < scores_count; i++) {
    int scores_item = stoi(scores_temp[i]);

    scores[i] = scores_item;
  }

  int alice_count;
  cin >> alice_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string alice_temp_temp;
  getline(cin, alice_temp_temp);

  vector<string> alice_temp = split_string(alice_temp_temp);

  vector<int> alice(alice_count);

  for (int i = 0; i < alice_count; i++) {
    int alice_item = stoi(alice_temp[i]);

    alice[i] = alice_item;
  }

  vector<int> result = climbingLeaderboard(scores, alice);

  for (int i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

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

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
