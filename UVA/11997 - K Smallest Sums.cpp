

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
#define OO ((ll)1e7)
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
//std::ios_base::sync_with_stdio(false); means  i will not deal with c lang that will speed
const double EPS = 1e-9;
typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;
#define pi 1000000007
#define black 0;
#define white 1;
const int MAXN=1e5+10;
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0,-1,  1, -1, 1, -1};
/*
I have k array and each array of k element we want k smallest sums, out of all sums taking 1 element from every array so to get all sums 
but we didn't need all sums we need only first k so think in 1 diminsion and merge every two rows in one row with k minimum sum ,
but merging every two row with one smalest k sums will take O ( k ^ 2 * log(k) ) that trying every pairs but we can optimize it to (k * log(k) ) .
so first take all the first row with the smallest element of the second column then pop the smallest sum and then but the next item
of the second item with the first item of the first row and so on unless you find the k elements then this will be the next row to deal with .
*/


int main()
{
    int k ;
    vector < vi > a ;

    while (cin >> k )
    {
        a.clear();
        a.resize (k+1, vi (k));
        rep( i, k)
        rep( j, k )
        cin >> a [i][j] ;

        rep( i, k )
        sort(all(a[i]));

        rep( i, k -1)
        {
            priority_queue < pair < int, int >,vector < pair < int, int > >,greater < pair < int, int > > >pq ;
            rep(j, k )
            pq.push({a[i][j] + a[i+1][0], 0 });

            int cnt = 0 ;
            while(cnt < k )
            {
                pair < int, int > cur = pq.top();
                pq.pop();

                pq.push({(cur.first - a[i+1][-cur.second]) + a[i+1][-(cur.second-1)], cur.second - 1 });
                a[i][cnt] = cur.first ;

                cnt++;
            }
            rep( j, k )
            a[i+1][j] = a[i][j];
            // cout << endl;
            // break;
        }

        rep( i, k -1 )
        cout <<a[k-1][i] << " ";
        cout << a[k-1][k-1] << endl;
    }

}


/*
6
1 2 3 4 10 14
8 9 10 12 14 19
12 13 14 14 17 15
96 45 65 98 74 44
22 11 33 22 55 77
99 63 25 14 28 23
*/
