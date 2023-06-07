#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> a, int n, int x) {
	int s = 0;
	int e = n;
	int ans = n;
	while(s<=e){
		int mid = s+(e-s)/2;
		if(a[mid]>=x){
			ans = mid;
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}
	return ans;
}
