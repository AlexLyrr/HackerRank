/*
  Problem: https://www.hackerrank.com/challenges/deque-stl/problem
  
  Idea: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/#disqus_thread
  Time Complexity: O(n) // It seems more than O(n) at first look. If we take a closer look, we can observe
                          that every element of array is added and removed at most once. So there are total 2n operations.
  Auxiliary Space: O(k)
  
  
  Theory:
    Double ended queue or Deque(part of C++ STL) are sequence containers with dynamic sizes that can be 
    expanded or contracted on both ends (either its front or its back). The member functions of deque that 
    are mainly used are:
    
      - Deque Template:
        std::deque<value_type>
      - Declaration:
        deque<int> mydeque; //Creates a double ended queue of deque of int type
      - Size:
        int length = mydeque.size(); //Gives the size of the deque
      - Push:
        mydeque.push_back(1); //Pushes element at the end
        mydeque.push_front(2); //Pushes element at the beginning
      - Pop:
        mydeque.pop_back(); //Pops element from the end
        mydeque.pop_front(); //Pops element from the beginning
      - Empty:
        mydeque.empty() //Returns a boolean value which tells whether the deque is empty or not
        
      More about deque: http://www.cplusplus.com/reference/deque/deque/
*/

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	// Create a Double Ended Queue, Qi that will store indexes of array elements 
    // The queue will store indexes of useful elements in every window and it will 
    // maintain decreasing order of values from front to rear in Qi, i.e.,  
    // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order 
    
    deque<int> dq;
    
    for (int i=0; i<n; i++){
        
        // base case for first element
        if (dq.empty()){
            dq.push_back(i);
        }
        
        // remove elements outside the current window
        if (dq.front() <= (i - k)){
            dq.pop_front();
        }
        
        // move max element to the front
        while (!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // print out only when the first window is completed
        if (i >= (k - 1)){
            cout << arr[dq.front()] << " ";
        }    
    }
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
