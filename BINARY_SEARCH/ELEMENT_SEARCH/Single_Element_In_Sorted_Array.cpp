#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> &a)
{
    int n = a.size();
    if (n == 1)
        return a[0];
    if (a[0] != a[1])
        return a[0];
    if (a[n - 1] != a[n - 2])
        return a[n - 1];
    int s = 0, e = n - 1;
    int ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (mid & 1)
        {
            if (a[mid] == a[mid - 1])
                s = mid + 1;
            else
                ans = mid, e = mid - 1;
        }
        else
        {
            if (a[mid] == a[mid + 1])
                s = mid + 1;
            else
                ans = mid, e = mid - 1;
        }
    }
    return a[ans];
}