#include <bits/stdc++.h>
using namespace std;
// O(sqrt(n))
vector<int> Divisors(int n)
{
    vector<int> ds;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ds.push_back(i);
            if (i != (n / i))
                ds.push_back(n / i);
        }
    }
    return ds;
}