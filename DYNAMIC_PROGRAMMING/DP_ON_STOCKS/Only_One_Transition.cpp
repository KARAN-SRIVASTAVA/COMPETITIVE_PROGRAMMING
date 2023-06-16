#include <bits/stdc++.h>
using namespace std;
int maximumProfit(vector<int> &prices)
{
   int mn = INT_MAX;
   int ans = 0;
   for (int i = 0; i < prices.size(); i++)
   {
      mn = min(mn, prices[i]);
      ans = max(ans, prices[i] - mn);
   }
   return ans;
}