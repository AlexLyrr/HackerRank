/*
  Problem: https://www.hackerrank.com/challenges/c-tutorial-class/problem
  
  Theory: 
    Classes in C++ are user defined types declared with keyword class that has data and functions. 
    Although classes and structures have the same type of functionality, there are some basic differences. 
    The data members of a class are private by default and the members of a structure are public by default.
    Along with storing multiple data in a common block, it also assigns some functions (known as methods) to 
    manipulate/access them. It serves as the building block of Object Oriented Programming.
    
    It also has access specifiers, which restrict the access of member elements. The primarily used ones are the following:
      - public: Public members (variables, methods) can be accessed from anywhere the code is visible.
      - private: Private members can be accessed only by other member functions, and it can not be accessed outside of class.
      
    Class can be represented in the form of:
      class ClassName {
        access_specifier1:
            type1 val1;
            type2 val2;
            ret_type1 method1(type_arg1 arg1, type_arg2 arg2,...)
            ...
        access_specifier2:
            type3 val3;
            type4 val4;
            ret_type2 method2(type_arg3 arg3, type_arg4 arg4,...)
            ...
      };
    It's a common practice to make all variables private, and set/get them using public methods. For example:
    
      class SampleClass {
        private:
            int val;
        public:
            void set(int a) {
                val = a;
            }
            int get() {
                return val;
        }
      };
*/    

#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student {
    private:
        int age, standard;
        string first_name, last_name;
        stringstream all;
    public:
        void set_age(int val) {
            age = val;
        }
        void set_standard(int val) {
            standard = val;
        }
        void set_first_name(string val) {
            first_name = val;
        }
        void set_last_name(string val) {
            last_name = val;
        }
        
        int get_age() {
            return age;
        }
        int get_standard() {
            return standard;
        }
        string get_first_name(){
            return first_name;
        }
        string get_last_name(){
            return last_name;
        }  
        string to_string(){
            stringstream ss;
            char c = ',';
            ss << age << c << first_name << c << last_name << c << standard;
            return ss.str();
        }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
