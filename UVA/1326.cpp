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



/*
n is 24 so I think it can be solved with brute force with o(2^n) but I solved it using meet in middle with implicit start and end with  o( 2 ^(n/2) * log(2 ^(n/2))).
so we split array into two parts in the first part , try every mask and store the x-or sum of every character of the token element 
as he said in the problem the number of edges to every characher must be even and the index of the taken element in the array 
and the number of taken element with negative signto sort the second part and with binary search get the first item with max size equal me .
in the second part do the samething .
then in any part if number if edges to the character is odd the the bit of that character will be 1 else it will 0 .
so if the number of edges of the character in the first part is odd we will need from the second part number of edges odd  
and if is even we will need even number to make over all sum is even wo we will need the same mask from the second part .
then sort the second part and  from every element of the first part sort and binary search to maximize answer as written above  .
*/



int main ()
{
    int n ;
    string a[100];
    vector < pair < pair < int, int >, vi > > vvv,  ddd ;
    vi data(27);
    while(cin >> n )
    {
        vvv.clear();
        ddd.clear();
        string s ;
        rep( i, n )
        cin >> a[i];

        int aa = (n+1) / 2 ;
        rep( mask, 1 << aa )
        {
            int v = 0 ;
            data.clear();
            rep( i, aa )
            if ( mask & (1 << i )) // try all masks of the first part 
            {
                rep(j, sz(a[i]))
                v^=(1<<(a[i][j]-'A'));
                data.pb(i+1);
            }
            vvv.pb({{v, -sz(data)}, data});

        }
        int r = aa;
        aa = n - aa;
        rep( mask, (1 << aa ))
        {
            int v = 0 ;
            data.clear();
            rep( i, aa )
            if ( mask & ( 1 << i ))
            {
                rep(j, sz(a[i+r]))
                v^=(1<<(a[i+r][j]-'A'));
                data.pb(i+r+1);
            }
            ddd.pb({{v, -sz(data)}, data});

        }

        int ans = 0, f1 = -1, f2 = -1 ;
        sort(all(ddd)); // sort to get the first element equal me with the largest vector  size 
        for (auto &i : ddd )
            i.first.second*=-1;
        int u = 0 ;
        for (auto &i : vvv )
        {
            i.first.second*=-1;
            int s = 0, e = sz(ddd);
            while (s < e)
            {
                int mid = (s + (e - s) / 2);
                if ( ddd[mid].first.first >= i.first.first )
                    e = mid;
                else
                    s = mid + 1;
            }

            if ( s < sz(ddd) && ddd[s].first.first == i.first.first )
            {
                if (i.first.second + ddd[s].first.second > ans )
                {
                    ans = i.first.second + ddd[s].first.second ;
                    f1 = u, f2 = s ;
                }
            }
            u++;
        }

        vi dd ;

        if (f1 != -1)
            for ( auto i : vvv[f1].second)
                dd.pb(i);

        if (f2!= -1  )
            for ( auto i : ddd[f2].second)
                dd.pb(i);
        sort(all(dd));
        cout << ans <<endl;
        if (ans )
        {
            int i ;
            for ( i = 0 ; i + 1 < sz(dd) ; i ++ )
                cout << dd[i] << " ";
            cout << dd[i] ;
        }
        puts("");

    }

}
