/*
  Problem: https://www.hackerrank.com/challenges/classes-objects/problem
  
  Theory:
    A class defines a blueprint for an object. We use the same syntax to declare objects of a class 
    as we use to declare variables of other basic types. For example:
      Box box1; // Declares variable box1 of type Box
      Box box2; // Declare variable box2 of type Box
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#include <numeric>

// Write your Student class here
class Student {
    private:
        vector<int> scores;
    public:
        Student(): scores(5, 0) {}
        void input(){
            int val;
            for (int i = 0; i < 5; ++i){
                cin >> val;
                scores[i] = val;
            }
        }
        int calculateTotalScore(){
            return std::accumulate(scores.begin(), scores.end(), 0);
        } 
};


int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
