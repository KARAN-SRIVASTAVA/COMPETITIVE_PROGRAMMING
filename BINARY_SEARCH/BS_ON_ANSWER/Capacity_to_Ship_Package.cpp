#include <bits/stdc++.h>
using namespace std;
bool is_Poss(int m, vector<int> &a, int d)
{
    int n = a.size();
    int day = 1;
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > m)
            return 0;
        if (a[i] + val <= m)
        {
            val += a[i];
        }
        else
        {
            day++;
            val = a[i];
        }
    }
    if (day <= d)
        return 1;
    return 0;
}
int leastWeightCapacity(vector<int> &a, int d)
{
    int n = a.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    int s = 1, e = sum;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (is_Poss(mid, a, d))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}