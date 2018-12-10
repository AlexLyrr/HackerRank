/*
        Problem: https://www.hackerrank.com/challenges/day-of-the-programmer/problem
        Time Complexity:  O(1) //There are no loops.
        Space Complexity: O(1) //number of dynamically allocated variables remain constant for any input.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


bool IsJulianLeapYear(int year) {
  if (year % 4 == 0)
    return true;

  return false;
}

bool IsGregorianLeapYear(int year) {
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    return true;

  return false;
}

string GetProgrammerDateForCalendarSwitchYear1918(int year) {
  // 1918 was a gregorian calendar after 1918 (it wasn't a leap year)
  int daysTillAug = 230; //  31 + 15 + 31 + 30 + 31 + 30 + 31 + 31
  int programmerDateInSeptember = 0;
  programmerDateInSeptember = 256 - daysTillAug;
  string dateWithFormat = std::to_string(programmerDateInSeptember) + ".09." + std::to_string(year);
  return dateWithFormat;
}

string GetProgrammerDateForJulianCalendar(int year) {
  int daysTillAugInLeapYear = 244;    // 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31
  int daysTillAugInNonLeapYear = 243; // 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31
  int programmerDateInSeptember = 0;
  programmerDateInSeptember = IsJulianLeapYear(year)
                                ? 256 - daysTillAugInLeapYear
                                : 256 - daysTillAugInNonLeapYear;
  string dateWithFormat = std::to_string(programmerDateInSeptember) + ".09." +                  std::to_string(year);
  return dateWithFormat;
}



string GetProgrammerDateForGregorianCalendar(int year) {
  int daysTillAugInLeapYear = 244;    // 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31
  int daysTillAugInNonLeapYear = 243; // 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31
  int programmerDateInSeptember = 0;

  programmerDateInSeptember = (IsGregorianLeapYear(year))
                                  ? 256 - daysTillAugInLeapYear
                                  : 256 - daysTillAugInNonLeapYear;
  string dateWithFormat = std::to_string(programmerDateInSeptember) + ".09." + to_string(year);
  return dateWithFormat;
}

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
  std::string programmerDate("");
  if (year >= 1919)
    programmerDate = GetProgrammerDateForGregorianCalendar(year);
  else if (year <= 1917) {
    programmerDate = GetProgrammerDateForJulianCalendar(year);
  } else {
    // gregorian switch year
    programmerDate = "26.09.1918";
  }
  return programmerDate;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
