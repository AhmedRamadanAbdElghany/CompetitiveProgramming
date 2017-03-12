// this code get TLE 


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
//int BIT[100009];


/*
n is very large 1e9 and we need the relation between the number not the number itself during quering .
so make coordinate compression and use segment tree to get median element .

*/




int interval[6000999];
int cnt = 0;

// log n
/*void add(int idx,int val)
{
    while (idx < MAXVAL )
        BIT[idx] += val, idx += (idx & -idx);
}

int getAccum(int idx)
{
    int sum = 0;
    while (idx > 0)
        sum += BIT[idx], idx -= (idx & -idx);
    return sum;
}
// log log n
int query(int num )
{
    int s = 1, e =MAXVAL ;

    while (s < e)
    {
        int mid = (s + (e - s) / 2);
        if (getAccum(mid) >= num )
            e = mid;
        else
            s = mid + 1;
    }
    if (getAccum(s) >= num )
        return s ;
    return -1;
}

*/

void insert(int s,int e, int p, int val, int v )
{
    interval[p]+= v ;
    if (s == e ) return ;
    int mid = (s + e ) / 2 ;
    if (mid >= val )
        insert(s, mid, p * 2, val,v );
    else
        insert(mid +1, e, p *2 + 1, val,v );
}
int query(int s, int e, int p, int kth )
{
    if(s == e)
    {
        if (interval [p] >= kth )
            return s;
    }
    if ( interval[2*p] >= kth )
        return query(s, (s + e )/2, 2*p, kth);
    return query( (s + e ) / 2  + 1, e, 2 * p + 1, kth -interval[2*p] );
}



map<int , int> M;
int MM[3000009] ;

int main ()
{
    int n, arr[200009];
    set<int> v;
    int tc ;

    scanf("%d", &tc);
    while(tc--)
    {
        int i = 0 ;
        cnt = 0 ;
        v.clear();
        M.clear();
        //mem(BIT, 0 );
        //mem(MM,0);
        mem(interval, 0 );
        while( 1 )
        {
            scanf("%d", &n );
            if (!n)break;
            arr[i++] = n ;
            if ( n != -1 )
                v.insert(n);
        }

        for (auto i : v )
        {
            M[i]= ++cnt;
            MM[cnt] = i ;
        }
        int num = 0 ;
        rep( j, i )
        if ( arr[j] != -1 )
            insert( 1 , cnt, 1, M[arr[j]], 1 ), num++;
        else
        {
            if(num > 0)
            {
                int temp = query(1, cnt, 1, (num+1)/2);
                printf("%d\n", MM[temp]);
                insert( 1, cnt, 1, temp, -1 );
                num--;
            }
        }
    }
}
