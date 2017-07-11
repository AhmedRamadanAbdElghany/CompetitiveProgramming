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
//#define MAX 5000000

int x[8] = {-1,1,-2,2,-2,2,-1,1};
int y[8] = {-2,-2,-1,-1,1,1,2,2};

#define black 0
#define white 1
#define gray 2

/*
we have n nodes and n edges so we have one cycle.
and the graph may consist of more than 1 components so every component have a cycle .
  
- by tracing more much example find that :
  if you delete an edge of some nodes not in the cycle ...>>> the component will split to 2 component . 
  so you need nodes only in cycles .
- number of nodes needed to be reconstruct to make all the graph connected not less than number of component you have .
- so for every component count number of nodes that is in the cycle 
  and for every node in the cycle you can take it or leave it but take at least one
  so you have (2^n-1) choices to choose nodes from these component 
*/
bool stackk[100];
int ans ;
int v[3009];
vi adj[3009], components;
stack < int > ss ;
void  dfs2(int node ) // for one cycle detection
{
    ss.push(node);
    stackk[node] = 1 ;
    v[node] = 1 ;
    rep( i, sz(adj[node]))
    {
        if ( v[adj[node][i]] == 0 )
        {
            dfs2(adj[node][i]) ;
        }
        else if (stackk[adj[node][i]] == 1 )
        {
            int cnt  = 0 ;
            //   cout << "aaa  " << adj[node][i] << endl;
            while(ss.empty() == 0  )
            {
                cnt++;
                // cout <<" xxx   " <<ss.top() << endl;
                if(ss.top() == adj[node][i])
                    break;
                ss.pop();
            }
            if (cnt)
                components.pb(cnt);
            ans += cnt ;
        }
    }
    stackk[node] = 0 ;
    if (ss.empty() == 0 )
        ss.pop();
}


class Sunnygraphs2
{

    long long count(vector <int> data)
    {
        int n = sz(data);
        rep( i, n )
        adj[i].pb(data[i]);

        rep(i, n )
        dfs2(i);

        int notcycles = n - ans ;
        ll res = ( 1LL << notcycles );
        // cout << res << endl;
        for (auto i : components)
            res *= ((1LL << i) - 1);


        if (components.size() == 1)  // take empty set if one component
            res++;

        cout << res << endl;

        return res ;
    }

};

int main(void)
{

// number of vertices not in cycles.

}
