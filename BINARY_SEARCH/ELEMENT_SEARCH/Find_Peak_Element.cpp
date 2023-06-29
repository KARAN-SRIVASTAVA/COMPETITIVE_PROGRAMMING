#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> &a)
{
    int n = a.size();
    if (n == 1)
        return 0;
    if (a[0] > a[1])
        return 0;
    if (a[n - 1] > a[n - 2])
        return n - 1;
    int s = 0, e = n - 1;
    while (e - s > 1)
    {
        int mid = s + (e - s) / 2;
        if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
            return mid;
        if (a[mid] > a[mid - 1] && a[mid] < a[mid + 1])
            s = mid;
        else
            e = mid;
    }
    return -1;
}
