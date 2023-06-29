#include <bits/stdc++.h>
using namespace std;
int upperBound(vector<int> &a, int x, int n){
	int ans = n;
	int s = 0,e = n-1;
	while(s<=e){
		int mid = s+(e-s)/2;
        if(a[mid]>x){
			ans = mid;
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}	
	return ans;
}