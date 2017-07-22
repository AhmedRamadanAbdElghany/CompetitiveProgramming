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
use binary search tree to get p element in the sorted list .
so first we have initial element more than any number in the list and cosider it the last minimum element you have got 
put it in the bst then if you add a value less than the last minimum element move left to get smaller element .
at after get the p minimum move to right to find p + 1 minimum .
the impleentation of bst in c++ is set .

*/




int main()
{
    int a[60000],
        u[60000];
    int n, m ;
    int t ;
    cin >> t ;
    multiset < int > MM;

    while(t--)
    {

        MM.clear();
        cin >> n >> m ;
        rep( i, n )
        cin >> a[i];
        int mx = -2000000002;

        rep( i, n )
        mx = max (mx, a[i]);
        mx ++;

        rep( i, m )
        cin >> u[i];

        MM.insert(mx);

        auto it = MM.begin();
        int s = 0 ;
        int l = 0 ;

        rep(l, m)
        {
            while( s < u[l] )
            {
                MM.insert(a[s]);
                if (*it > a[s++])
                    it--;
            }
            cout << *it << endl;
            it++;
        }
        if (t)
            cout << endl;
    }
}
