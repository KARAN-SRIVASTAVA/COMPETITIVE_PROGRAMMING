#include <bits/stdc++.h>
using namespace std;
int count(vector<int>& a, int n, int k) {
	bool b = binary_search(a.begin(),a.end(),k);
    if(!b) return 0;
    int lb = lower_bound(a.begin(),a.end(),k)-a.begin();
    int ub = upper_bound(a.begin(),a.end(),k)-a.begin() - 1;
    return ub-lb+1;
}