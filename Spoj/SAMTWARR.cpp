// WA
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
//std::ios_base::sync_with_stdio(false); means  i will not deal with c lang that will speed
const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;
#define pi 1000000007
#define black 0;
#define white 1;
const int MAXN=1e5+10;
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
const double EPS = 1e-9;



int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};


int  seg[400000];
int  seg1[400000];
int  lazy[400000];

int type, a,x, y ;

void insert(int s, int e, int p, int idx,int val )
{

//    cout << s << "  " << e << endl;
    if (lazy[p] != 0 )
    {
  //      cout << "lazzzzz " << p<< endl;
        swap(seg1[p], seg[p]);
        lazy[p] = 0 ;
        if (s != e )
        {
            lazy[2*p] = !lazy[2*p] ;
            lazy[2*p+1] = !lazy[2*p+1] ;
        }
    }
    if ( s == e )
    {
        if (type == 0 )
            seg[p] = val ;
        else
            seg1[p] = val ;
    //    cout << "insert " << p << endl;
        return;
    }

    int mid = ( s + e )/2;
    if ( mid >= idx )
        insert(s, mid, p * 2, idx,val );
    else
        insert(mid + 1, e, 2 * p + 1, idx,val);

    seg[p] = seg[2*p]+ seg[2*p+1];
    seg1[p] = seg1[2*p]+ seg1[2*p+1];
}




void  update1(int startRange, int endRange,int low, int high, int pos)
{

    //cout << low << "  " << high << endl;

    if (lazy[pos] != 0 )
    {
      //  cout <<"lazy  "<< pos << endl;
        swap(seg1[pos], seg[pos]);
        lazy[pos] = 0 ;
        if (high != low )
        {
            lazy[2*pos] = !lazy[2*pos] ;
            lazy[2*pos+1] = !lazy[2*pos+1] ;
        }
    }


    if(startRange > high || endRange < low)
    {
        return;
    }

    if(startRange <= low && endRange >= high)
    {

        swap(seg[pos], seg1[pos]);

        //cout << low << " " << high <<"  " << seg[pos] << "  " << seg1[pos]<< endl;
        if(low != high)
        {
            lazy[2*pos ] = !lazy[2*pos];
            lazy[2*pos + 1] = !lazy[2*pos+1];
        }
        return ;
    }

    int mid = (low + high)/2;
    update1( startRange, endRange, low, mid, 2*pos);
    update1(startRange, endRange, mid+1, high, 2*pos+1);

    seg[pos] = seg[2*pos]+ seg[2*pos+1];
    seg1[pos] = seg1[2*pos]+ seg1[2*pos+1];
}


int query(int startRange, int endRange, int  pos,int low, int high )
{
   // cout << low << " " << high << endl;
    if (lazy[pos] != 0 )
    {
        //cout << "laz  " << pos << "  ";
        swap(seg1[pos], seg[pos]);
       // cout << seg[pos] << "  " << seg1[pos] << endl;
        lazy[pos] = 0 ;
        if (low != high )
        {
            lazy[2*pos ] = !lazy[2*pos];
            lazy[2*pos + 1] = !lazy[2*pos+1];
        }
    }

    if(startRange > high || endRange < low)
    {
        return 0;
    }

    //total overlap condition
    if(startRange <= low && endRange >= high)
    {
     //   cout << low << " " << high <<" "<< seg[pos] << " " << seg1[pos] << endl;
        if (type == 0 )
            return  seg[pos] ;
        else
            return seg1[pos]  ;
    }

    ll mid=(low+high)/2;
    int a = query(startRange,endRange,pos*2,low,mid);
    int b = query(startRange,endRange,pos*2+1,mid+1,high);
    //seg[pos]  = seg[2*pos]+ seg[2*pos+1];
    // seg1[pos] = seg1[2*pos]+ seg1[2*pos+1];
    return a + b ;

}


int main()
{

//#ifndef Ahmed_Ramadan
///  freopen("a.txt", "rt", stdin);
/// freopen("a.txt", "wt", stdout);
//#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m ;
cin >> n >> m ;
        mem(seg1, 0 );
        mem(seg, 0 );
        mem(lazy, 0 );
        rep( i, m )
        {
            cin >> a ;
            if (a == 0 )
            {
                cin >> type >> x >> y ;
                cout << query(x, y, 1, 0, n -1 ) << endl;
            }
            else if (a == 1 )
            {
                cin >> type >> x >> y ;
                insert(0, n-1, 1,x,y );
       //         cout << query(0, n-1, 1, 0, n -1 ) << endl;

            }
            else
            {
                cin >> x >> y ;
                update1(x, y, 0, n - 1, 1 );
               // type = 0 ;
             //   cout << query(x, y, 1, 0, n -1 ) << endl;
           //     type = 1;
         //       cout << query(x, y, 1, 0, n -1 ) << endl;

            }
        }
    }
