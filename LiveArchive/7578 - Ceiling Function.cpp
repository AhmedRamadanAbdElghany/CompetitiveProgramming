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
given binary trees need to find number of different tree shapes .

so compare every two binary tree every node has same right and left node structure  .
then group same binary trees. 

*/
 struct trie
{
    trie *left, *right ;
    int val;

    trie()
    {
        left = 0, right = 0 ;
    }
};
typedef trie* tree ;
void insert( tree & p , int node )
{
    if (p == NULL )
    {
        p = new trie();
        p->val = node ;
     //   cout << p-> val << " new " << endl;
        return ;
    }
    //cout << p->val << endl;
    if(p -> val < node )
        insert(p ->right, node );
    else
        insert( p->left, node );
}
trie * p[22];
bool vis[200];
bool dfs(trie *  a , trie *  b)
{
    int l = 0, r = 0 ;
    if(a == NULL && b == NULL)return true;
    if(a && b)
    {
        l =dfs(a->left, b->left);
        r =dfs(a->right, b->right);
    }
    return (l && r );
}

int main()
{
    // auto __startTime = chrono::system_clock::now();

    int n, k, a ;

    while(cin >> n >> k )
    {
        rep( i, n )
        {
         trie *  tt = NULL ;

            rep( j, k )
            {
                cin >> a;
              if ( j== 0 )
              {
                  tt = new trie();
                  tt->val = a ;
              }
              else
             /*cout << (tt == NULL),*/   insert( tt, a );
            }
                p[i] = tt ;
        }
        mem(vis, 0 );
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if (vis[i] == 1 ) continue ;
            for(int j = i + 1; j < n; j++)
                if(vis[j] == 0 && dfs(p[i], p[j]))
                    vis[j] = 1 ;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;

}
