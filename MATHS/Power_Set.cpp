#include <bits/stdc++.h>
using namespace std;
// O(N*(2^N)) , O(N)
vector<vector<int>> PowerSet(vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> ans;
    for (int i = 0; i < 1 << n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                temp.push_back(v[j]);
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    return ans;
}