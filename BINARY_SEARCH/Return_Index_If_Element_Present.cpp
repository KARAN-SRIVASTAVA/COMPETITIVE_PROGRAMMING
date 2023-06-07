#include <bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
    bool b = binary_search(nums.begin(),nums.end(),target);
    if(!b) return -1;
    int it = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    return it;
}