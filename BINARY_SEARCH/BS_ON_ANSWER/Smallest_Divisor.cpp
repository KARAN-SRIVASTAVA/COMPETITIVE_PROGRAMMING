#include <bits/stdc++.h>
using namespace std;
int smallestDivisor(vector<int> &a, int limit)
{
    int n = a.size();
    int s = 1, e = INT_MAX;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int val = 0;
        for (int i = 0; i < n; i++)
        {
            val += a[i] / mid;
            if (a[i] % mid)
                val++;
        }
        if (val > limit)
        {
            s = mid + 1;
        }
        else
        {
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}