#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool ispos(ll m, vector<int> v, ll h)
{
    ll n = v.size();
    ll time = 0;
    for (ll i = 0; i < n; i++)
    {
        time += v[i] / m;
        if (v[i] % m)
            time++;
    }
    if (time <= h)
        return 1;
    return 0;
}
ll minimumRateToEatBananas(vector<int> v, ll h)
{
    ll sum = 0;
    for (ll i = 0; i < v.size(); i++)
        sum += v[i];
    ll s = 1, e = sum;
    ll ans = -1;
    while (s <= e)
    {
        ll mid = s + (e - s) / 2;
        if (ispos(mid, v, h))
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