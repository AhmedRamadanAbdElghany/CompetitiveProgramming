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
#include <iostream>
#include <cstring>


#define SZ 50007
// classical one 

int a[SZ];

struct SegmentTree{ int prefixSum , suffixSum ,Sum ,maxSum ; };

SegmentTree tree[ SZ<<3 ];

SegmentTree merge( SegmentTree a , SegmentTree b)
{
    SegmentTree res ;

    res.Sum = a.Sum + b.Sum ;
    res.maxSum = max( max( a.maxSum , b.maxSum ) , (a.suffixSum + b.prefixSum ) ) ;

    res.prefixSum = max( a.prefixSum , a.Sum + b.prefixSum );

    res.suffixSum = max( b.suffixSum , b.Sum + a.suffixSum );

    return res ;
}

void BUILD(int node , int start , int end)
{
        if(start == end)
        {
            int X;
            scanf("%d",&X);
            tree[node].prefixSum = tree[node].suffixSum = tree[node].Sum = tree[node].maxSum = X ;

            return ;
        }

        int l = node<<1 ;
        int r = node<<1|1;

        int mid = (start + end )>>1;

        BUILD(l , start , mid );
        BUILD(r , mid + 1 , end );

        tree[ node ] = merge( tree[l] , tree[r] );
}


SegmentTree Query(int node , int start , int end , int x , int y)
{
    if(start == x && end == y)
        return tree[node];

    int l = node<<1 ;
    int r = node<<1|1;

    int mid = (start + end )>>1;

    if(y <= mid )
        return Query(l,start,mid,x,y); // whole side is in left

    else if( x > mid )
        return Query(r,mid+1,end,x,y) ; // whole side is in right

    else
    {
        return merge( Query(l,start,mid,x,mid) , Query(r,mid+1,end,mid+1,y)  ) ; // split in two side so merging
    }
}


void insert(int s , int e , int p , int idx ,int val ){

if ( s == e )
{

tree[p].prefixSum = tree[p].suffixSum = tree[p].Sum = tree[p].maxSum = val ;
               return;
}
int mid = ( s + e )/2;
if ( mid >= idx )
    insert(s , mid , p * 2 , idx,val );
else
    insert(mid + 1 , e , 2 * p + 1 , idx ,val);
tree[p] = merge(tree[2*p] , tree[2*p+1]);
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N ;
    scanf("%d",&N);
        BUILD(1,0,N-1);

        int Q ;
         scanf("%d",&Q);

        while(Q--)
        {

            int x , y , a;
            scanf("%d %d %d",&a,&x,&y);
            if (a == 1 )
            printf("%d\n",Query(1,0,N-1,x-1,y-1).maxSum );
            else
                insert(0 , N - 1 , 1 , x - 1 , y );
        }
    }
