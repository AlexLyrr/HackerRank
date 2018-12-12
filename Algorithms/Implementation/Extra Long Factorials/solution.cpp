/*
  Problem: https://www.hackerrank.com/challenges/extra-long-factorials/problem  
*/

/*
 The main code was found in: 
https://stackoverflow.com/questions/1966077/calculate-the-factorial-of-an-arbitrarily-large-number-showing-all-the-digits
 */
#include <bits/stdc++.h>

using namespace std;

int maxNumber = 5000;

void display(int arr[]) {
    int ctr = 0;
    for (int i = 0; i < maxNumber; i++) {
      if (!ctr && arr[i])
        ctr = 1;
        if (ctr)
        std::cout << arr[i];
    }
}

void factorial(int arr[], int n) {
    if (!n)
        return;
    int carry = 0;
    for (int i = maxNumber - 1; i >= 0; --i) {
        arr[i] = (arr[i] * n) + carry;
        carry = arr[i] / 10;
        arr[i] %= 10;
    }
    factorial(arr, n - 1);
}

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    int *arr = new int[maxNumber];
    std::memset(arr, 0, maxNumber * sizeof(int));
    arr[maxNumber - 1] = 1;
    factorial(arr, n);
    display(arr);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
