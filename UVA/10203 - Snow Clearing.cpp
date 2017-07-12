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
//#define MAX 5000000

int x[8] = {-1,1,-2,2,-2,2,-1,1};
int y[8] = {-2,-2,-1,-1,1,1,2,2};
int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

/*
you must go in every path twice .
*/


int main()
{
    double x;
    int a, b, c, d, tc;
    cin >> tc ;
    db v = 20000.0 / 60.0;

    while (tc--)
    {
        x = 0.0;
       cin >> a >> b;

        string s;
        cin.ignore();
        while (getline(cin, s) )
        {
        istringstream iss(s) ;
        if (iss >> a >> b >> c >> d )
            x += sqrt( (a-c)*(a-c) + (b-d)*(b-d) );
            else break;
        }

        int t = roundf(2 * x / v);
        printf("%d:%0.2d\n", t/60, t%60);
        if (tc)
            puts("");
    }
    return 0;
}
