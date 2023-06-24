#include <bits/stdc++.h>
using namespace std;
// O(N),O(1);
void sortSetBitsCount(vector<int> &a, int n)
{
    vector<int> bits[33];
    for (int i = 0; i < n; i++)
    {
        int sb = __builtin_popcountll(a[i]);
        bits[sb].push_back(a[i]);
    }

    int k = 0;
    for (int i = 32; i >= 1; i--)
        if (bits[i].size() > 0)
            for (auto it : bits[i])
                a[k++] = it;
}