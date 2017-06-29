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
given grid with height and width and you are in the bottom left .
and you have four option evey option make you move 1 step or 2 toward right find the numbers of visited cells .
you must do all the four options so the width must >= 7 and height >= 3 after doing the four options  you will be at (0 , 6)
and visiting 4 cells .
or you make less than 4 moves of any options .


*/

db dist[51][51];

class LameKnight
{
public:
   int maxCells(int height, int width)
    {
        int ans = 1 ;
       if (min(height , width) == 1 ) return ans ;
      if ( height < 3 ||width < 7  ){
      if (height >= 3  )
            return min(4,width);
            if (width >= 3 )
                return   min((width-1)/2+1 , 4) ;
      return ans ;
      }
      ans = 4;
      width -= 6;
        return width+ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
LameKnight l;
cout << l.maxCells(3, 2000000000);
}
