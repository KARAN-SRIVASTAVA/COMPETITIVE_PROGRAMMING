#include <bits/stdc++.h>
using namespace std;
int missingK(vector<int> a, int n, int k)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (a[m] - (m + 1) < k)
            s = m + 1;
        else
            e = m - 1;
    }
    return e + k + 1;
}
