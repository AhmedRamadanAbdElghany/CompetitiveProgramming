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

/*
given n balls and some ranges you can color the range with black or white .
you need to count number of  different colorings  after the last range .
number of ranges is maximum 10 .
and you have 2 choices to color [0,1] so you have (2^10)  and at every range you can 
paint n ball maximum n is 100 so the overall is (2^m)*n where m<=10 , n <= 100 .
so brute force is enough 
*/



set<string > V;
vi l , r ;
int fun(int idx, string s )
{
    if (idx == sz(l))
        if (V.find(s) == V.end()){
            V.insert(s);
            return 1;

        }
        else return 0 ;
    string ch1, ch2 ;
    int ret = 0 ;
    ch1 = ch2 = s ;
    REP(i, l[idx] - 1, r[idx] )
    ch1[i] = 0 ;
    ret = fun(idx + 1, ch1  );
    REP(i, l[idx] - 1, r[idx] )
    ch2[i] = 1 ;
    ret += fun(idx + 1, ch2  );

    return ret ;
}


class Dubs
{

public :
    int getNumber(int M, vector <int> L, vector <int> R)
    {
l = L;
r = R;
    string s ="";
    rep( i , M )
    s.pb('0');
return fun(0 ,s );
    }


};

int main(void)
{
    int n ;
    cin >> n ;
  }

