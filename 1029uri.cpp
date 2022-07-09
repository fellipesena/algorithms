#include <bits/stdc++.h>

using namespace std;

int calls;

int fibonacci(int num)
{
    calls++;
    if (num == 0)
    {
        return 0;
    }
    if (num == 1)
    {
        return 1;
    }

    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main()
{
    int cases, num, res;
    cin >> cases;

    while (cases--)
    {
        calls = 0;

        cin >> num;

        res = fibonacci(num);

        cout << "fib(" << num << ") = " << calls - 1 << " calls = " << res << endl;
    }
}