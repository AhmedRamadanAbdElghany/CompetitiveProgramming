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
/*
we have number x and we want y numbers such that product of yi equal x .
so we can factorize x into c1*a * c2*b where ci is the count of the prime number .
we can choose c1 from y which is Combinations with repetition  >>>>> nck(y + ci -1 , ci ).
we can factorize every number in O(log n) storing in every number largest prime .
in y positions we can choose any number of even positions and put it with negative sign so choosing even positions is 2 (y-1).
*/

int lastP [3000000];
void sieve(){
  for(int i = 2; i <= 1000000; i++)
    if(!lastP[i])
    for(int j = i; j <= 1000000; j += i)
      if(!lastP[j])
      lastP[j] = i;
}

vi facto(int x){
 vi ret;
  while( x != 1){
    ret.pb(lastP[x]);
    x /= lastP[x];
  }
  return ret;
}


ll mod = ll (1e9) +  7;

ll fastpow(ll a, ll b)
{
    if(b==0) return 1;

    if(b%2==0)
    {
        ll x=fastpow(a,b/2 );
        return (x*x)% mod ;
    }
    else return (a%mod * fastpow(a,b-1))%mod ;
}

ll fact[2000009], factmodinverse[2000009];
ll nck(int a, int b )
{
    return (((fact[a] * factmodinverse[b])%mod)*factmodinverse[a-b]%mod);
}



int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, x,y ;
    sieve();

     fact[0] = factmodinverse[0] = 1;
     REP(i, 1, 2000001) {
        fact[i] = (fact[i-1]*i)%mod;
        factmodinverse[i] = fastpow(fact[i], mod-2);
    }

    cin >> n ;
    while(n--){
        ll ans = 1 ;
        cin >> x >> y ;
        vi ret = facto(x);
        map < int , int > M ;
        for (auto i : ret )
            M[i]++;
        for (auto i : M ){
        ans *= nck(y + i.second-1 , i.second );
        ans %= mod ;
        }
        
    ll r = fastpow(2,y-1);
    ans = ans * r ;
    ans%= mod;
    cout << ans << endl;

    }

}



