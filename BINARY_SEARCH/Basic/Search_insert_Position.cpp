#include <bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& a, int m)
{
	return lower_bound(a.begin(),a.end(),m)-a.begin();
}