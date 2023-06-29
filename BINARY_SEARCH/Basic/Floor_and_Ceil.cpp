#include <bits/stdc++.h>
using namespace std;
pair<int, int> getFloorAndCeil(int a[], int n, int x) {
	int floor = -1;
	int ceil = INT_MAX;
	for(int i=0;i<n;i++){
		if(a[i]>=x)
			ceil = min(ceil,a[i]);
		if(a[i]<=x)
			floor = max(floor,a[i]);
	}
	if(ceil==INT_MAX) ceil = -1;
	return {floor,ceil}; 
}