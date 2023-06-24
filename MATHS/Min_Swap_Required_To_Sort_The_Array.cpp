#include <bits/stdc++.h>
using namespace std;
// O(N(longN)) | O(N)
int minSwaps(vector<int> &arr)
{
    int count = 0;
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
        map[arr[i]] = i;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != temp[i])
        {
            count++;
            int init = arr[i];
            swap(arr[i], arr[map[temp[i]]]);
            map[init] = map[temp[i]];
            map[temp[i]] = i;
        }
    }
    return count;
}