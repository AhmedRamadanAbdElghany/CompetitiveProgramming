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

#define black 0
#define white 1
#define gray 2
//OLLEHELLO
// OLLELLO
/*
build the needed pattern .
use dp with parameter ( i , j , ch ) where i , j are the index in the pattern and ch is the index of char in the given string .
to make use information that every char used only once use (ch) to avoid be in a cycle .

*/
int n ;
ll dp[100][100][100];
vector < string > v ;
string cur = "H";
ll fun(int a, int b, int ch  )
{
    if (ch == n ) return 1 ; // end of string
    if ( dp[a][b][ch] != -1 )
        return dp[a][b][ch];

   ll ans = 0 ;
    rep(j, 4 )
    {
        int x = dx[j] + a ;
        int y = dy[j] + b ;
        if (x >= 0 && x < sz(v) && y >= 0 && y < sz(v[0]) && v[x][y] != '!') // valid position
        {
            int dist = abs((sz(cur) - 1) - x ) + abs((sz(cur) - 1) - y ) ;
            if ( dist == ch && v[x][y] == cur[ch] ) // not go to in a cycle .
                ans += fun( x, y, ch + 1 ) ;
        }
    }
    return dp[a][b][ch] = ans ;
}

ll init()
{
    mem(dp, -1 );
    n = sz(cur);
    int idx = 0 ;
    string st="";
    rep( i, n )
    {
        string e = cur.substr(idx);
        string f = e.substr(1);
        reverse(all(f));
        v.pb(st+f + e+st);
        idx++;
        st.pb('!');
    }
    reverse(all(v));

    n = sz(v);
    for (int i = n - 2 ; i >=0 ; i -- )
        v.pb(v[i]);
    return fun(sz(cur) -1, sz(cur) - 1, 1 ) ;
}
class WordPattern
{
public :
    long long countWords(string word)
    {
        cur = word;
        return init();
    }
};
/*
int main(void)
{
    WordPattern r ;
    cout << r.countWords("ABCD");

}
*/
