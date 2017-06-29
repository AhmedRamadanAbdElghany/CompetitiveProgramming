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
/*
given n vertices each 2 has path with length L we have also k potions which decrease the length of the path between 2 nodes to half .
we need to go from node 0 to 1 with at most k-1 potions.

so we use dikestra with added parameter which specify number of potions used so far .
*/




db dist[51][51];
class ShortestPathWithMagic
{
public:
    double getTime(vector <string> d, int k)
    {
        int n = sz(d);
        rep( i, 51 )
        rep( j, 51 )
        dist[i][j] = 100000000;

        set < pair < db, pair < int, int > > > pq;
        pq.insert({0, {0,k}});
        dist[0][0] = 0 ;
        while (pq.size() != 0)
        {
            auto it = pq.begin();
            auto temp = *it ;
            pq.erase(it);
            int x = temp.second.first ;
            int r = temp.second.second ;
            db dd  = temp.first ;

            if (x == 1 )
                return  dd ;

            for (int y = 0; y < n; y++)
            {
                int dest = d[x][y] - '0' ;
              
                if (r > 0)
                {
                    if (dist[y][r-1] > dd + dest/2.0 )
                    {
                        dist[y][r-1] = dd + dest/2.0 ;
                        pq.insert( {dd + dest/2.0, {y, r - 1}} );
                    }
                }
                
                if (dist[y][r] > dd + dest )
                {
                    dist[y][r] = dd + dest ;
                    pq.insert( {dd + dest, {y, r }} );
                }
            }
        }
    }
};
/*
int main()
{
    ios_base::sync_with_stdio(false);
}
*/
