#include <bits/stdc++.h>
using namespace std;

int Counter = 0;
// Recursive Function for Fibonacci Series
int recUtilityFunction(int n)
{
    if (n <= 1)
    {
        return n;
    }
    Counter++;
    return recUtilityFunction(n - 1) + recUtilityFunction(n - 2);
}

void recursiveFibonacci(int n)
{
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++)
    {
        cout << recUtilityFunction(i) << " ";
    }
    cout << endl;
    cout << "Step Count: " << Counter << endl;
    Counter = 0;
}

// Iterative Function for Fibonacci Series
void iterativeFibonacci(int n)
{
    int F1 = 1, F2 = 0, nextTerm = 0;
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++)
    {
        cout << nextTerm << " ";
        Counter++;
        nextTerm = F1 + F2;
        F1 = F2;
        F2 = nextTerm;
    }
    cout << endl;
    cout << "Step Count: " << Counter << endl;
    Counter = 0;
}

/*
Recursive fibbonacci:
Time Complexity: O(n*2n) //O(1.618^N)
Auxiliary Space: O(n), For recursion call stack.

Iterative fibbonacci:
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

int main()
{
    int n;
    cout << "Enter the length of series: ";
    cin >> n;
    int choice = 1;
    do
    {
        cout << "***Enter your choice***" << endl;
        cout << "[1] Recursive" << endl;
        cout << "[2] Iterative" << endl;
        cout << "[3] ESC" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            recursiveFibonacci(n);
            break;
        }
        case 2:
        {
            iterativeFibonacci(n);
            break;
        }
        default:
        {
            break;
        }
        }
    } while (choice != 3);
    return 0;
}