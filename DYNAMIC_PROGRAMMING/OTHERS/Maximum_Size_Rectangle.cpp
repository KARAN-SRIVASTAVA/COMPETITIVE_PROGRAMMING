#include <bits/stdc++.h>
using namespace std;
vector<int> solver(int n, vector<int> h)
{
    vector<int> a(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && h[i] <= h[s.top()])
        {
            a[i] = a[s.top()];
            s.pop();
        }
        if (a[i] == -1)
            a[i] = i;
        s.push(i);
    }
    return a;
}
vector<int> solvel(int n, vector<int> h)
{
    vector<int> a(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && h[i] <= h[s.top()])
        {
            a[i] = a[s.top()];
            s.pop();
        }
        if (a[i] == -1)
            a[i] = i;
        s.push(i);
    }
    return a;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    if (n == 1)
        return heights[0];
    vector<int> right = solver(n, heights);
    vector<int> left = solvel(n, heights);
    int maxarea = 0;
    for (int i = 0; i < n; i++)
    {
        int width = right[i] - left[i] + 1;
        int area = heights[i] * width;
        maxarea = max(maxarea, area);
    }
    return maxarea;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m)
{
    int mx = 0;
    vector<int> temp = mat[0];
    mx = max(largestRectangleArea(temp), mx);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j])
                temp[j] += 1;
            else
                temp[j] = 0;
        }
        mx = max(largestRectangleArea(temp), mx);
    }
    return mx;
}