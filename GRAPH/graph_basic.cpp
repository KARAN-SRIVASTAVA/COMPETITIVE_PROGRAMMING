                                         // SHREE GANESHAY NAMAH 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define  F              first
#define  S              second
#define  si             set<int>
#define  pb             push_back
#define  ll             long long 
#define  int            long long 
#define  MOD            1000000007
#define  vi             vector<int>
#define  om             map<int,int>
#define  SORT(v)        sort(all(v))
#define  REVERSE(v)     reverse(all(v))
#define  pt(x)           cout<<(x)<<endl
#define  setpri         setprecision(12)
#define  no             cout<<"no"<<endl
#define  No             cout<<"No"<<endl
#define  NO             cout<<"NO"<<endl
#define  yes            cout<<"yes"<<endl
#define  YES            cout<<"YES"<<endl
#define  Yes            cout<<"Yes"<<endl
#define  m1             cout << -1 << endl
#define  all(v)         v.begin(), v.end()
#define  us             unordered_set<int>
#define  vvi            vector<vector<int>>
#define  fo(i,n)        for(ll i=0;i<n;i++)
#define  Fo(i,n)        for(ll i=1;i<=n;i++)
#define  rep(i,a,b)     for(ll i=a;i<=b;i++)
#define  per(i,b,a)     for(ll i=b;i>=a;i--)
#define  vpi            vector<pair<int,int>>
#define  ump            unordered_map<int,int>
#define  MAXI(arr,n)    *max_element(arr,arr+n)
#define  MINI(arr,n)    *min_element(arr,arr+n)
#define  input(arr,n)   for(int i=0;i<n;i++)cin>>arr[i];
#define  PI             3.1415926535897932384626433832795
#define  check          cout<<"AA RHA HAI YHA TK CODE"<<endl;
#define  to_upper(s)    transform(all(s),s.begin(),::toupper);
#define  to_lower(s)    transform(all(s),s.begin(),::tolower);
#define  print(a)       for(auto i:a) cout<<i<<" "; cout<<endl;
#define  printm(m)      for(auto i:m) cout<<i.first<<" "<<i.second<<endl;
#define  FAST           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int maxfq(int *arr,int n){int maxi=INT_MIN;unordered_map<int,int>m;for (int i = 0; i < n; i++){m[arr[i]]++;maxi = max(maxi,m[arr[i]]);}return maxi;}
// Mathematical functions 
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
//Check
int modInverse(int A,int M){int m0=M;int y=0,x=1;if (M==1)return 0;while(A>1){int q=A/M;int t=M;M=A%M,A=t;t=y;y=x-q*y;x=t;}if (x < 0)x+=m0;return x;}
bool isprime(int n){if(n<=1) return false;if(n<=3) return true;if(n%2==0||n%3==0) return false;for (int i = 5;i*i <= n; i=i+6) {if((n%i==0) || (n%(i+2)==0)) return false;}return true;} 
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrtl(x);return (sr * sr == x);}return false;}
                  // WRITE NEW FUNCTION FROM HERE
                  // WRITE NEW FUNCTION FROM HERE
void solve()
{
    
}
    signed main()
{
FAST;
int t;
cin>>t;
while(t--)
solve();
    return 0;
}