#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& a, int n, int k)
{
    int s = 0,e = n-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(a[mid]==k) return mid;
        if(a[mid]>=a[s]){
            if(k<a[mid] && k>=a[s]) e = mid-1;
            else s = mid+1;
        }
        else{
            if(k>a[mid] && k<=a[e]) s = mid+1;
            else e = mid-1;
            
        }
    }
    return -1;
}