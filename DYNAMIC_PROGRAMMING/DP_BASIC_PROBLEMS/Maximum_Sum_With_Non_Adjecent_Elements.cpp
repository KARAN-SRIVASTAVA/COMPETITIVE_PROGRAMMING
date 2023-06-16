#include <bits/stdc++.h>
using namespace std;
int Rec(int n, vector<int> &nums, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];
    if (dp[n] != -1)
        return dp[n];
    int incl = nums[n] + Rec(n - 2, nums, dp);
    int excl = Rec(n - 1, nums, dp);
    return dp[n] = max(incl, excl);
}
int tab(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    return dp[n - 1];
}
int SO(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        int ans = max(prev2 + nums[i], prev1);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // recursion + Memoization
    // int n = nums.size();
    // vector<int> dp(n,-1);
    // return Rec(n-1,nums,dp);

    // tabulation
    // return tab(nums);

    // space optimization
    return SO(nums);
}