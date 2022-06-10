#include <iostream>
using namespace std;

int a[5];
int array_size = sizeof(a) / sizeof(a[0]);

void display()
{
    for (const auto &i : a)
        cout << i << " ";

    cout << endl
         << endl;
}

int factorial(int n)
{               // In recursion terminology, the case in which our function will not recurse is known as the base case. So, 1 is the base case for our factorial() function.
    if (n == 1) // Base case where factorial 1 returns 1
        return 1;

    return n * factorial(n - 1);
    // e.g. factorial(3)
    // { 3 * factorial(2) }
    // { 2 * factorial(1) }
    // { 1 }
    // { 2 * 1 }
    // { 3 * 2 * 1 }
    // factorial(3) == 6
}

void doubledArray(int arr[], int index = 0) // int index = 0 is the default parameter
{
    if (index > array_size) // Base case
    {
        cout << "(Doubled Array)\n";
        display();
        return;
    }

    arr[index] *= 2;
    doubledArray(arr, ++index);
}

int arraySum(int *arr, int *end = nullptr)
{
    // cout << "Recursion\n";
    end = &arr[array_size - 1];

    if (*arr == *end) // base case
        return arr[0];

    return arr[0] + arraySum(arr + 1, end); // arraySum(arr+1, end) is the subproblem
    // during each iteration in the subproblem, arr[0] is the arr+1, which is the next element, we keep adding the elements together until we arr[0] is the last element.
}

// Alternative arraySum()
/* int arraySum(int *arr)
{
    if (*arr == arr[array_size-1])
        return 0;

    return *arr + arraySum(arr+1);
} */

// fibonacci of the n'th element, fibonacci starts with the element 0, e.g. 0,1,1,2,3,5,...
// fibonacci using normal recursion
/* int fib(int n)
{
cout << "Recursionn\n";

if (n == 0 || n == 1)
    return n;

return fib(n-2) + fib(n-1);
} */

// fibonacci using memoization
// O(N)
/* int fib(int n, unordered_map<int,int> memo = {})
{
cout << "Recursion\n";

if (n == 0 || n == 1)
    return n;

if (!memo[n]) // see page 209
    return memo[n] = fib(n-2, memo) + fib(n-1, memo);

return memo[n];
} */

// fibonacci using the bottom-up approach
// O(N)
int fib(int n)
{

    int a = 0;
    int b = 1;
    int temp;

    for (int i = 1; i < n; i++)
    {
        temp = a;
        a = b;
        b = temp + a;
    }

    return b;
}

int main()
{

    //  int m = 5; cout << "Factorial " << m << " = " << factorial(n);
    //  doubledArray(a);
    //  cout << "Array sum = " << arraySum(a) << endl;
    //  int x = 10; cout << "Fibonacci of the " << x << "th element = " << fib(x);

    return 0;
}