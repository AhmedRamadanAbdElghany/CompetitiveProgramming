#include <bits/stdc++.h>
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


bool vis[30000];
class Quacking
{
public :
    int quack(string s)
    {
        string t = "quack";
        int cur = 0  ;
        int cnt = 0, f  ;
        vi v ;
        while(1)
        {
           v.clear();
            f = 0 ;
            rep( i, sz(s) )
            {
                if (s[i] == t[cur] && vis[i] == 0)
                    cur++, v.push_back(i) ;

                if (cur == sz(t))  f = 1,  cur = 0 ;
            }
            if (f && cur == 0)
            {
             for (auto i : v )
                   cout << i<<"  ", vis[i] = 1 ;
cout << endl;
                cnt++;
            }
            else
                break ;
        }

        rep(i, sz(s))
        if (!vis[i])
            return -1 ;
        return cnt ;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);

Quacking l ;
cout << l.quack("ackquackqu");
}
