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

pair < int, int > seg[1000000];
int arr[200009];
int arr2[200009];

/*
- problem description :
  given two arrays find number of ranges which max value in the first array equal min value in second array . 

sol :
for every index find first and last index where max equal min using binary search 
and the answer using this index will be difeence between last and first .


*/

void build (int s, int e, int p )
{
    if (s == e )
    {
        seg[p].first = arr2[s];
        seg[p].second = arr[s];
        return;
    }
    build(s, (s + e ) / 2, 2 * p );
    build((s + e ) / 2 + 1, e, 2 * p + 1  );
    seg[p].first = min (seg[2*p].first, seg[2*p+1].first );
    seg[p].second = max (seg[2*p].second, seg[2*p+1].second );

}
int le, ri ;
pair < int, int > query(int s, int e, int  p)
{
    if ( s >= le && e <= ri  )
        return seg[p];
    int mid = (s + e ) >> 1;

    if(ri <= mid )
        return query(s,mid, 2 * p ); // whole side is in left

    else if( le > mid )
        return query(mid+1,e, 2 * p + 1 ) ; // whole side is in right

    pair <int, int > p1 = query(s,mid, 2 * p );
    pair <int, int > p2 = query(mid + 1, e, 2 * p + 1 );

    return {min(p1.first, p2.first), max(p1.second, p2.second)};

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ;
    cin >> n ;
    rep( i, n )
    cin >> arr[i];
    rep( i, n )
    cin >> arr2[i];
build(0 , n -1 , 1);
ll res = 0;
	for (int i = 0; i < n; i++){
		int st = i, en = n - 1;
		int mxi, mni;
		while (st < en) {
			int mid = st + (en - st) / 2;
			le = i , ri = mid ;
			pair < int , int > ret = query(0, n-1,1);
			mni = ret.first ,mxi = ret.second ;
			if (mxi < mni)
				st = mid + 1;
			else
				en = mid;
		}
				le = i , ri = st ;
			pair < int , int > ret = query(0, n-1,1);
			mni = ret.first ,mxi = ret.second ;

		if (mxi == mni) {
			int fr = st;
			en = n - 1;
			while (st < en) {
				int mid = st + (en - st + 1) / 2;
				le = i , ri = mid ;
			pair < int , int > ret = query(0, n-1,1);
			mni = ret.first ,mxi = ret.second ;

				if (mxi == mni)
					st = mid;
				else
					en = mid - 1;
			}
			res += st - fr + 1;
		}
	}
	cout << res << endl;
	return 0;
}
