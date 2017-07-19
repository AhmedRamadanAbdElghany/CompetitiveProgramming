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
/*
  problem description :
- given n number every number can be kill it's right if the left is larger .
  
  solution description :
- every block of decreasing numbers can be destroyed with 1 step and remain the largest number .
  then need to merge blocks so do it again with new numbers of every largest number in every block .

- if I have two numbers [x ,..... ,y ]  as it decreasing numbers , x in the left of y  
  also x ,y can be the largest number in the blocks .
  number of steps to destroy y will be maximum between destroy every number between them + 1 .
- we take maximum and don't add 1 to any of them as one block may be merged more than other one .      
*/


int main()
{
    int n, res= 0;
    cin >> n;
    vector<int> arr(n), ans(n + 1);
    rep(i, n)
    scanf("%d", &arr[i]);
    stack<int> s;
    s.push(0);
    REP(i, 1, n)
    {
        while (s.empty() == 0 && arr[i] > arr[s.top()])
        {
            ans[i] = max(ans[i], ans[s.top()] + 1 );
            //cout << arr[i] << "  " << ans[i] << endl;
            s.pop();
        }

        if (  s.empty() == 0 && ans[i] == 0 ) // have at least one step as I have less element after me .
            ans [i] = 1;

        if ( s.empty() == 0 ) // don't take answer which kill all left elements .
            res = max(res, ans[i]);

        s.push(i);
    }
    cout << res << endl;
}
