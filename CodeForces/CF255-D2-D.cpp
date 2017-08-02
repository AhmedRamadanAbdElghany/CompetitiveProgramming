
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define rep(i,m)        for(int i=0;i<m;i++)
#define REP(i,k,m)      for(int i=k;i<m;i++)
#define repd(i,m)        for(int i=m;i>=0;i--)
#define P(x)                cout<<#x<<" = { "<<x<<" }\n"
#define mem(a,b)        memset(a,b,sizeof(a))
#define mp              make_pair
#define pb              push_back
#define OO ((ll)1e12)
#define ooo -100000000
#define small  INT_MIN;
#define big  INT_MAX;
using namespace std;
typedef long long ll;
typedef double db;
typedef long double       ld;
typedef vector<int>       vi;
typedef vector<bool>       vb;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef bitset<20> MASK;
#define INF 10000
#define sz(v)          ((int)((v).size()))
const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;

/*
it is clear that it is binary search problem but how to construct valid function .
we can see that at every level has odd number of blocks less that the level Under it with 2 blocks .
so first find number of blocks with mid that can be built Without consideration the border of the square .
then at each direction subtract blocks that skip borders and add blocks that can be added in each quarter 
be tracing find that blocks added in each squre are j + (j-1)+ ... 1 .where j is (mid - x - y) . 

*/




ll n, c, x, y;
ll sub(ll val )
{
    if(val <= 0 )
        return 0;
    return val * val;
}
ll add(ll val )
{
    if(val <= 0)
        return 0;
    return val * (val + 1)/2;
}
bool valid (ll mid)
{
    ll ret = (mid + 1) * (mid + 1) * 2 - (mid + 1) * 2 + 1;
    ret -=sub(mid - x + 1); // up
    ret -=sub(mid - (n - x)); // down
    ret -=sub(mid - y + 1); // left
    ret -=sub(mid - (n - y)); // right
// if two directions are not at the border .
    ret += add(mid - x - y + 1);
    ret += add(mid - x - ( n - y));
    ret += add(mid - (n - x) - y );
    ret += add(mid - (n - x) - (n - y) - 1);
    return ret >= c;
}
int main()
{
    cin >> n >> x >> y >> c;

    ll l = 0, h = 1e9;
    while(l < h)
    {
        ll mid = l + (h - l) / 2;
        if(valid(mid))
            h = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;
// valid(5);
    return 0;
}
