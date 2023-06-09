#include<bits/stdc++.h>
using namespace std;
bool searchInARotatedSortedArrayII(vector<int>&a, int k) {
    int n = a.size();
    int s = 0,e = n-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(a[mid]==k) return 1;
        if(a[s]==a[mid] && a[mid]==a[e]){
            s++;
            e--;
            continue;
        }
        if(a[mid]>=a[s]){
            if(k<a[mid] && k>=a[s]) e = mid-1;
            else s = mid+1;

        }
        else{
            if(k>a[mid] && k<=a[e]) s = mid+1;
            else e = mid-1;
            
        }
    }
    return 0;
}
