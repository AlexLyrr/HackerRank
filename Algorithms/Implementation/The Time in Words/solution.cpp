/*
  Problem: https://www.hackerrank.com/challenges/the-time-in-words/problem
  Time Complexity: O(1)
  Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;

std::string const hours[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven" };
std::string const minutes[] = {
    "one",        "two",          "three",        "four",        "five",
    "six",        "seven",        "eight",        "nine",        "ten",
    "eleven",     "twelve",       "thirteen",     "fourteen",    "fifteen",
    "sixteen",    "seventeen",    "eighteen",     "nineteen",    "twenty",
    "twenty one", "twenty two",   "twenty three", "twenty four", "twenty five",
    "twenty six", "twenty seven", "twenty eight", "twenty nine"};

// Complete the timeInWords function below.
string timeInWords(int h, int m) {

    if (m == 0){
        return hours[h - 1] + " o' clock";
    }
    if (m == 1){
      return minutes[m - 1] + " minute past " + hours[h - 1];
    }
    if ((m > 1 && m <= 14) || (m > 15 && m <= 29)) {
      return minutes[m - 1] + " minutes past " + hours[h - 1];
    }
    if (m == 15) {
      return (string) "quarter" + " past " + hours[h - 1];
    }
    if (m == 30) {
      return (string) "half" + " past " + hours[h - 1];
    }
    if ((m >= 31 && m <= 44) || (m >= 46 && m < 59)) {
      return minutes[60 - m - 1] + " minutes to " + hours[h];
    }
    if (m == 59) {
      return minutes[60 - m - 1] + " minute to " + hours[h];
    }
    if (m == 45) {
      return (string) "quarter" + " to " + hours[h];
    }
    return "";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
