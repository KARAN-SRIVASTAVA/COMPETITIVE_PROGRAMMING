#include <bits/stdc++.h>
using namespace std;
long long int houseRobber(vector<int> &h)
{
    int n = h.size();
    if (n == 1)
        return h[0];
    if (n == 2)
        return max(h[0], h[1]);
    long long int ans = 0, prev2 = h[0], prev1 = max(h[0], h[1]);
    for (int i = 2; i < n - 1; i++)
    {
        long long int ans = max(prev1, prev2 + h[i]);
        prev2 = prev1;
        prev1 = ans;
    }
    ans = prev1;
    prev2 = h[1], prev1 = max(h[1], h[2]);
    for (int i = 3; i < n; i++)
    {
        long long int ans = max(prev1, prev2 + h[i]);
        prev2 = prev1;
        prev1 = ans;
    }
    ans = max(ans, prev1);
    return ans;
}