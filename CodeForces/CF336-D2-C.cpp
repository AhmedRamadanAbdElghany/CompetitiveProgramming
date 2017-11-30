//#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>
#include <string.h>
#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define rep(i,m)        for(int i=0;i<m;i++)
#define REP(i,k,m)      for(int i=k;i<m;i++)
#define repd(i,m)        for(int i=m;i>=0;i--)
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
#define mem(a,b)        memset(a,b,sizeof(a))
#define mp              make_pair
#define pb              push_back
#define SORT(ptr , k )  sort ( ptr , ptr + k );
#define small  INT_MIN;
#define big  INT_MAX;
// #undef to remove macro
#include <cmath>
#include <complex>

using namespace std;
typedef long long ll;
typedef double db;
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<bool>       vb;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef bitset<20> MASK;
//typedef  pair < int, string > point ;
#define mo 1000000007
#define INF 10000
#define sz(v)          ((int)((v).size()))
//std::ios_base::sync_with_stdio(false); means  i will not deal with c lang that will speed
const int oo = (int) 1e9;
const double eps = 1e-7;
#define md 1000000007
#define black 0;
#define white 1;
const int MAXN=1e5+10;
int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

string tobinary(int a )
{
    string ret ="";
    while(a > 0 )
    {
        char temp =(a%2)+'0' ;
        ret = temp + ret ;
        a /= 2;
    }
    return ret ;
}

string andd(string a , string b ){
string ret ="";
rep( i , sz(a))
ret+=(((a[i]-'0') & (b[i]-'0'))+'0');
return ret ;
}



string binar[1000001];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, a[100005],mx = 0 ;
    cin >> n ;
    rep( i, n )
    {
        cin >> a[i];
        binar[i] = tobinary(a[i]);
        mx = max(mx, sz(binar[i]));
    }
    
    rep(i, n ){
        int temp = sz(binar[i]);
    rep(j, mx - temp)
    binar[i] = '0' + binar[i];
    }


    vi v ;
    vi tempp ;
    int ans = -1 ;
    for (int i = mx -1 ; i >= 0 ; i -- )
    {
        string last = tobinary((1LL << mx) -1);
        rep( j, n )
        if (binar[j][i]== '1'){
            last = andd(binar[j] , last);
            tempp.pb(a[j]);
        }

    int cnt = 0 ;
    for (int j = mx -1 ; j > i  ; j -- )
        cnt += (last[j]=='1');
        if (cnt == 0 )
        {
            ans = mx - (i + 1 );
            v = tempp ;
        }
        
        tempp.clear();
    }

if (ans == -1 ){
    cout << ans << endl;
    return 0 ;
}
    cout << sz(v) << endl;
    for (auto i : v )
        cout << i  << " ";
}







