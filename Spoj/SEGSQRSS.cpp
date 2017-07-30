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

- it is direct segment tree with lazy propagation problem but how to make updates and merge results 
- first type of update : add delta to range 
  if I have square sum of range a ^ 2 + b ^ 2 + c ^ 2 +.. 
  and I need to get square sum after add delta so after add x square sum will be (a+delta)^2 + (b+delta)^2 + (c + delta )^2 +..
  Subtract second square sum from first 
  you will get 2 * delta * sum of numbers + (end - start+1) * delta * delta .
  so you should add this value to the square sum to get the new one .
  so you should have another parameter : sum of numbers .

- second type of update : set range to x 
  you just set node to (end - start + 1 ) * x * x to get square sum .
  and (end - start + 1 ) * x to get sum .

*/



pair < int, int >  seg[1000000]; // first is sum of range .
                                 // second is square sum of range .

pair < int, int > lazy[1000000]; // first is add x to range .
                                 // second is set range to x .
int arr[100009];
void build (int s , int e , int p )
{
    if (s == e )
    {
        seg[p].first = arr[s];
        seg[p].second = arr[s]*arr[s];
        lazy[p].first=lazy[p].second = 0 ; // initialization 
        return ;
    }
    build(s, (s + e ) / 2, 2 * p );
    build((s + e ) / 2 + 1, e, 2 * p + 1  );
    lazy[p].first=lazy[p].second = 0 ; // initialization
    seg[p].first =seg[2*p].first + seg[2*p+1].first ;
    seg[p].second =seg[2*p].second + seg[2*p+1].second ;
}

int type ;
void  update1(int startRange, int endRange,int delta, int low, int high, int pos)
{

    if (lazy[pos].first != 0 ) // first type  add x ;
    {
        seg[pos].second += lazy[pos].first * 2 * seg[pos].first + (endRange - startRange + 1 ) * lazy[pos].first *lazy[pos].first ;
        seg[pos].first += (endRange - startRange + 1 ) * lazy[pos].first ;
        if ( startRange != endRange )
        {
            lazy[pos*2].first   += lazy[pos].first;
            lazy[pos*2+1].first += lazy[pos].first;
        }
        lazy[pos].first=0;
    }

    else if (lazy[pos].second != 0 ) // change all to x
    {
        seg[pos].first=(endRange-startRange+1)*(lazy[pos].second);
        seg[pos].second=(endRange-startRange+1)*(lazy[pos].second * lazy[pos].second);
        if(startRange!=endRange)
        {
            lazy[pos*2].second = lazy[pos*2+1].second = lazy[pos].second;
        }
        lazy[pos].second = 0;
    }

    if(startRange > high || endRange < low)
    {
        return;
    }

    //total overlap condition
    if(startRange <= low && endRange >= high)
    {
        if (type == 0 ) // first type
        {
            seg[pos].second +=  delta * 2 * seg[pos].first + (endRange - startRange + 1 ) *  delta * delta ;
            seg[pos].first += (endRange - startRange + 1 ) * delta ;
            if(startRange != endRange)
            {
                lazy[2*pos + 1].first += delta;
                lazy[2*pos + 2].first += delta;
            }
        }
        else   // second type
        {
            seg[pos].first=(endRange-startRange+1)*(delta);
            seg[pos].second=(endRange-startRange+1)*(delta*delta);

            if(startRange!=endRange)
            {
                lazy[pos*2].second=lazy[pos*2+1].second=delta;
            }
        }
        return ;
    }


    int mid = (low + high)/2;
    update1( startRange, endRange,
             delta, low, mid, 2*pos);
    update1(startRange, endRange,
            delta, mid+1, high, 2*pos+1);
    seg[pos].first = seg[2*pos ].first + seg[2*pos + 1].first ;
    seg[pos].second = seg[2*pos ].second + seg[2*pos + 1].second ;

}


int query(int startRange, int endRange, int  pos,int le, int ri )
{

    if (lazy[pos].first != 0 ) // first type  add x ;
    {
        seg[pos].second += lazy[pos].first * 2 * seg[pos].first + (endRange - startRange + 1 ) * lazy[pos].first *lazy[pos].first ;
        seg[pos].first += (endRange - startRange + 1 ) * lazy[pos].first ;
        if ( startRange != endRange )
        {
            lazy[pos*2].first   += lazy[pos].first;
            lazy[pos*2+1].first += lazy[pos].first;
        }
        lazy[pos].first = 0;
    }

    else if (lazy[pos].second != 0 ) // change all to x
    {
        seg[pos].first=(endRange-startRange+1)*(lazy[pos].second);
        seg[pos].second=(endRange-startRange+1)*(lazy[pos].second * lazy[pos].second);
        if(startRange!=endRange)
        {
            lazy[pos*2].second = lazy[pos*2+1].second = lazy[pos].second;
        }
        lazy[pos].second = 0;
    }

    if(startRange> ri || endRange < le )
        return 0;

    if(startRange >= le && endRange <= ri )
        return seg[pos].second;

    ll mid=(startRange+endRange)/2;
    return query(startRange,mid,pos*2,le,ri)
           +query(mid+1,endRange,pos*2+1,le,ri);


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc ;
    cin >> tc ;
    rep(t, tc )
    {
        cout << "Case "<<t+1<<":" << endl;
        int n, m, a, b, c, d   ;
        cin >> n >> m ;
        rep( i, n )
        cin >> arr[i];
        build(0, n - 1, 1 );
        rep( i, m )
        {
            cin >> c >> a >> b  ;
            a--;
            b--;
            if (c == 2 )
            {
                cout << query(0, n -1, 1, a, b ) << endl;
            }
            else if (c == 1 )
            {
                cin >> d ;
                type = 0 ;
                update1(a, b,d,0,n-1,1);

            }
            else
            {
                cin >> d ;
                type = 1 ;
                update1(a, b,d,0,n-1,1);
            }
        }
    }
}
