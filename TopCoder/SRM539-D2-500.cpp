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

given n box to store rocks each box can have an upperbound and lowerbound value , we need to count number of ways 
to store rocks in the boxes as sum of rocks > 9000 .

I used brute force to find all ranges that can occur by finding the upper bound  and lower value of each mask.
then sort all ranges and find the intercting point for every two consective ranges and count difference .
*/


class Over9000Rocks
{
public :
    int countPossibilities(vector <int> lowerBound, vector <int> upperBound)
    {
        int ans = 0 ;
        int n = sz(lowerBound);
        vector < pair < int, int > > v ;
        rep( mask,  1 << n )
        {
            int sum = 0, temp = 0 ;
            rep(k, n )
            if ((1 << k ) & mask)
                sum+= upperBound[k], temp += upperBound[k] - lowerBound[k];
            if (sum >= 9001 )
            {
                int first = max(9001, sum - temp ) ;
                if (sum >= first )
                    v.push_back({ first, sum });
            }
        }
        sort(all(v));
        int prev = 0;
        if (v.size())
            ans += v[0].second - v[0].first + 1 ;
        int last = 0 ;
        REP( i, 1, sz(v))
        {
            if (v[i].first <= v[last].second )
                v[i].first = v[last].second + 1;
            if (v[i].first <= v[i].second )
                ans += v[i].second - v[i].first + 1,last = i  ;
        }
        return ans ;
    }
};
/*
int main()
{
    ios_base::sync_with_stdio(false);

    Over9000Rocks l;
    cout << l.countPossibilities({1,1,1,1,1,1}
                                 , {3,4,5,6,7,8});
}

*/
