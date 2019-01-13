/*
  Problem: https://www.hackerrank.com/challenges/attribute-parser/problem

  Theory:
    In order to solve this problem we used several string operations.
    std::string::find -> http://www.cplusplus.com/reference/string/string/find/
    std::string::find_last_of -> http://www.cplusplus.com/reference/string/string/find_last_of/
    std::string::substr -> http://www.cplusplus.com/reference/string/string/substr/
    std::stringstream  -> http://www.cplusplus.com/reference/sstream/stringstream/
*/
    

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, q;
    cin >> n >> q;
    cin.ignore();

    map<string,string> database; // to store attribute-value pairs
    string inputstr, tag_preamble = "";

    // get each HRML line
    for (int i = 0; i < n; i++) {
        getline(cin, inputstr);

        // for each HRML line, break it up into token words
        stringstream ss(inputstr);
        string word, attribute, value;
        size_t pos;
        while (ss >> word) { // for each token word
            // Tag detected, either an opening or a closing
            if (word[0] == '<') {
                string tag;
                // If there is an '/' we have a tag closing
                if (word[1] == '/') {
                    tag = word.substr(2, word.length() - 2 - 1);   
                    //tag = tag.substr(0,tag.length() - 1); // rid of ">"
                    pos = tag_preamble.find("." + tag);
                    if (pos == string::npos) 
                        tag_preamble="";
                    else 
                        tag_preamble = tag_preamble.substr(0,pos);
                }
                else { // it's tag opening
                    tag = word.substr(1); 
                    if (tag.find(">") != string::npos) 
                        tag = tag.substr(0, tag.length() - 1); // rid of ">"
                    // Is it nested tag or not?
                    if (tag_preamble == "") 
                        tag_preamble = tag;
                    else 
                        tag_preamble = tag_preamble + "." + tag;
                }
            }
            // value detected
            else if (word[0] == '"') {
                pos = word.find_last_of('"');
                value = word.substr(1,pos-1);
                database[attribute] = value; // insert into DB
            }
            // attribute name detected
            else if (word[0]!='=') {
                attribute=tag_preamble + "~" + word;  
            }
        }
    }

    // now we process the queries
    for (int i=0;i<q;i++) {
        getline(cin,inputstr); 
        if (database.find(inputstr) == database.end())
            cout << "Not Found!" << endl;
        else
            cout << database[inputstr] << endl;
    }

    return 0;
}
