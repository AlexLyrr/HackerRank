/*
  Problem: https://www.hackerrank.com/challenges/exceptional-server/problem
  
  Theory:
    An exception is a problem that arises during the execution of a program. A C++ exception is a response 
    to an exceptional circumstance that arises while a program is running, such as an attempt to divide by zero.

    Exceptions provide a way to transfer control from one part of a program to another. C++ exception handling is 
    built upon three keywords: try, catch, and throw.
    
      throw − A program throws an exception when a problem shows up. This is done using a throw keyword.
      catch − A program catches an exception with an exception handler at the place in a program where 
              you want to handle the problem. The catch keyword indicates the catching of an exception.
      try − A try block identifies a block of code for which particular exceptions will be activated. It's
            followed by one or more catch blocks.
      
    Assuming a block will raise an exception, a method catches an exception using a combination of the try 
    and catch keywords. A try/catch block is placed around the code that might generate an exception. Code 
    within a try/catch block is referred to as protected code, and the syntax for using try/catch as follows −
    
    try {
       // protected code
    } catch( ExceptionName e1 ) {
       // catch block
    } catch( ExceptionName e2 ) {
       // catch block
    } catch( ExceptionName eN ) {
       // catch block
    }
    
    You can list down multiple catch statements to catch different type of exceptions in case your try block raises more
    than one exception in different situations.
    
    Exceptions can be thrown anywhere within a code block using throw statement. The operand of the throw statement determines
    a type for the exception and can be any expression and the type of the result of the expression determines the type of
    exception thrown.
    
    The catch block following the try block catches any exception. You can specify what type of exception you want to catch
    and this is determined by the exception declaration that appears in parentheses following the keyword catch.
    
    try {
       // protected code
    } catch( ExceptionName e ) {
      // code to handle ExceptionName exception
    }
    
    Above code will catch an exception of ExceptionName type. If you want to specify that a catch block should handle any type
    of exception that is thrown in a try block, you must put an ellipsis, ..., between the parentheses enclosing the exception 
    declaration as follows −

    try {
       // protected code
    } catch(...) {
      // code to handle any exception
    }
    
    See more about exceptions: https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
*/

#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;

		/* Enter your code here. */
        try {
            cout << Server::compute(A,B) << endl;
        } 
        catch (bad_alloc& error) {
            cout << "Not enough memory" << endl;
        }
        catch (exception& error) {
            cout << "Exception: " << error.what() << endl;
        }
        catch (...) {
            cout << "Other Exception" << endl;
        }

	}
	cout << Server::getLoad() << endl;
	return 0;
}


