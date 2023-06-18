#include <bits/stdc++.h>
using namespace std;
/*
 * MultiSource Shortest Path Algorithm
 * Help To Detect Negative Cycle
 * Go Via Every Node
 * Convert UG->DG for Applying it
 * Node to Node distance < 0 => Negative Cycle Exist
 * a[i][j] Represent shortest path Btw i->j
*/
vector<vector<int>> shortest_distance(vector<vector<int>> &a)
{

    int n = a.size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == -1)
                a[i][j] = 1e9;

    for (int via = 0; via < n; via++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][via] + a[via][j] < a[i][j])
                    a[i][j] = a[i][via] + a[via][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 1e9)
                a[i][j] = -1;

    return a;
}