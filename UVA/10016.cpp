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

/*
it a simulation probelm .
*/
int n;
int board[101][101], tmp[101][101];

void go(int ring)
{
   REP( i , ring,  n - ring )
         REP( j , ring,  n - ring )
        if (i == ring || i == n - ring - 1 || j == ring || j == n - ring - 1)
            board[i][j] = tmp[i][j];

}

void upsideDown(int ring)
{
    rep( i, n  )
    rep( j, n  )
    tmp[i][j] = board[n-i-1][j];


    go(ring);
}

void leftRight(int ring)
{
    rep( i, n )
    rep( j, n )
    tmp[i][j] = board[i][n-j-1];

    go(ring);
}

void mainDiagonal(int ring)
{
    rep( i, n )
    rep( j, n )
    tmp[i][j] = board[i][j];
    rep( i, n )
    REP( j,i, n )
    swap(tmp[i][j], tmp[j][i]);
    go(ring);
}

void mainInverseDiagonal(int ring)
{
    rep( i, n )
    rep( j, n )
    tmp[i][j] = board[i][j];

    rep( i, n )
    rep( j, n-i )
    swap(tmp[i][j], tmp[n - j - 1][n - i - 1]);

    go(ring);
}



int main(void)
{
    int cases, t, c;

    cin >> cases;

    while (cases--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> board[i][j];
            }
        }

        int rings = (n % 2 == 0) ? n / 2 : n / 2 + 1;

        rep( k , rings) {
            cin >> t;

            while (t--)
            {
                cin >> c;
                switch (c)
                {
                case 1:
                    upsideDown(k);
                    break;
                case 2:
                    leftRight(k);
                    break;
                case 3:
                    mainDiagonal(k);
                    break;
                case 4:
                   mainInverseDiagonal(k);
                    break;
                }
            }
        }

       for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
                cout << " ";
            cout << board[i][j];
        }
        cout << endl;
    }

    }

    return 0;
}
