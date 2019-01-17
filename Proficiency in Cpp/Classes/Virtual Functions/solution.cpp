/*
  Problem: https://www.hackerrank.com/challenges/virtual-functions/problem
  
  Theory:
    A virtual function a member function which is declared within base class and is re-defined (Overriden) by derived class.
    When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function 
    for that object and execute the derived class’s version of the function.
    
    - Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for function call.
    - They are mainly used to achieve Runtime polymorphism
    - Functions are declared with a virtual keyword in base class.
    - The resolving of function call is done at Run-time.
    
  Rules for Virtual Functions:

    1) They Must be declared in public section of class.
    2) Virtual functions cannot be static and also cannot be a friend function of another class.
    3) Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism.
    4) The prototype of virtual functions should be same in base as well as derived class.
    5) They are always defined in base class and overridden in derived class. It is not mandatory for derived class to override
    (or re-define the virtual function), in that case base class version of function is used.
    6) A class may have virtual destructor but it cannot have a virtual constructor.
  
  For virtual functions see also: https://www.geeksforgeeks.org/virtual-function-cpp/
  
  Static member:
    We can define class members static using static keyword. When we declare a member of a class as static it
    means no matter how many objects of the class are created, there is only one copy of the static member.
    A static member is shared by all objects of the class. All static data is initialized to zero when the first 
    object is created, if no other initialization is present. We can't put it in the class definition but it can be
    initialized outside the class as done in the following example by redeclaring the static variable, using the scope
    resolution operator :: to identify which class it belongs to. By declaring a function member as static, you make it
    independent of any particular object of the class. A static member function can be called even if no objects of the 
    class exist and the static functions are accessed using only the class name and the scope resolution operator ::.
    A static member function can only access static data member, other static member functions and any other functions from
    outside the class. Static member functions have a class scope and they do not have access to the this pointer of the class.
    You could use a static member function to determine whether some objects of the class have been created or not.
  
  For static members see also: https://www.tutorialspoint.com/cplusplus/cpp_static_members.htm
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
    private:
        string name;
        int age;
    public:
      virtual void getdata() { cin >> name >> age; }
      virtual void putdata() { cout << name << " " << age << endl; }
};

class Professor : public Person {
    private:
        string name;
        int age, publications, cur_id;
        static int id;
      public:
        Professor() { cur_id = ++id; }
        void getdata() { cin >> name >> age >> publications; }
        void putdata() {
          cout << name << " " 
                << age << " " 
                << publications 
                << " " << cur_id 
                << endl;
        }
};
int Professor::id = 0;

class Student : public Person {
    private:
        string name;
        int age, cur_id;
        int marks[6];
        static int id;
    public:
        Student() { cur_id = ++id; }
        void getdata() {
            cin >> name >> age;
            for (int i = 0; i < 6; i++) {
                cin >> marks[i];
            }
        }
        void putdata() {
            int marksSum = 0;
            for (int i = 0; i< 6; i++) {
                marksSum += marks[i];
            }
            cout << name << " "
                << age << " "
                << marksSum << " "
                << cur_id << endl;
        }
};
int Student::id = 0;




int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
