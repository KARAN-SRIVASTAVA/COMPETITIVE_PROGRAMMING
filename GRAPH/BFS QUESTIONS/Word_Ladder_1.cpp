#include <bits/stdc++.h>
using namespace std;
int wordLadderLength(string sw, string tw, vector<string> &wl)
{

    if (sw == tw)
        return 0;

    queue<pair<string, int>> q;
    unordered_map<string, bool> vis;
    unordered_map<string, bool> present;

    for (int i = 0; i < wl.size(); i++)
        present[wl[i]] = 1;

    q.push({sw, 1});
    vis[sw] = 1;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        string s = it.first;
        int opcount = it.second;
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            char oldchar = s[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                s[i] = ch;
                if (present[s] && !vis[s])
                {
                    vis[s] = 1;
                    q.push({s, opcount + 1});
                    if (s == tw)
                        return opcount + 1;
                }
            }
            s[i] = oldchar;
        }
    }

    return 0;
}