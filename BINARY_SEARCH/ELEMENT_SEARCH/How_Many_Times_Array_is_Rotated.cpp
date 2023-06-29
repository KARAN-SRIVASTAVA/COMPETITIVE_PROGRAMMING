#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int> &a)
{
    long long n = a.size();
    long long s = 0, e = n - 1;
    while (e - s > 1)
    {
        long long mid = s + (e - s) / 2;
        if (a[mid] < a[mid - 1] && a[mid] < a[mid + 1])
            return mid;
        if (a[mid] > a[0])
            s = mid;
        else
            e = mid;
    }
    return n - 1;
}
int findKRotation(vector<int> &arr)
{
    int ind = findMin(arr);
    int n = arr.size();
    if (arr[n - 1] > arr[0])
        return 0;
    return ind;
}