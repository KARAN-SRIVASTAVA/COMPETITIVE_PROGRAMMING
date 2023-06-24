#include <bits/stdc++.h>
using namespace std;
// O(LogN),O(1)
bool isNumPalindrome(long long N)
{
    int l = log2(N), r = 0;
    while (l > r)
        if (((N >> l--) & 1) != ((N >> r++) & 1))
            return 0;
    return 1;
}