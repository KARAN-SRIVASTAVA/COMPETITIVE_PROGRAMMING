#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> findSequences(string sw, string tw, vector<string> &wl)
{
    unordered_map<string, bool> vis, present;
    for (int i = 0; i < wl.size(); i++)
        present[wl[i]] = 1;
    int anslen = 1e9;
    queue<vector<string>> q;
    q.push({sw});
    int level = 0;
    while (!q.empty())
    {
        vector<string> v = q.front();
        string s = v.back();
        int step = v.size();
        if (step >= anslen)
            break;
        q.pop();
        if (step > level)
        {
            level++;
            vis[s] = 1;
        }
        if (step == level)
        {
            vis[s] = 1;
        }
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            char oldchar = s[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                s[i] = ch;
                if (present[s] && !vis[s])
                {
                    v.push_back(s);
                    q.push(v);
                    v.pop_back();
                    if (s == tw)
                        anslen = step + 1;
                }
            }
            s[i] = oldchar;
        }
    }
    vector<vector<string>> ans;
    while (!q.empty())
    {
        vector<string> v = q.front();
        q.pop();
        if (v.back() == tw)
            ans.push_back(v);
    }
    return ans;
}