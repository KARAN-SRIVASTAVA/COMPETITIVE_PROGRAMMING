#include <bits/stdc++.h>
using namespace std;
pair<int, int> firstAndLastPosition(vector<int>& a, int n, int k)
{
    bool b = binary_search(a.begin(),a.end(),k);
    if(!b) return {-1,-1};
    int lb = lower_bound(a.begin(),a.end(),k)-a.begin();
    int ub = upper_bound(a.begin(),a.end(),k)-a.begin() - 1;
    return {lb,ub};
}