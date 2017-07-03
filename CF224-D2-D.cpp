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
const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-7;
//#define MAX 5000000
/*

problem description :
given string s , t we need that every char in s exist at least once in subsequence of s which match string t .

solution describtion :
save in the prevv all previous chars of current char
save in the nextt all next chars of current char
save in M  the index of the char number of some type // (5th a )[a][5] .

loop throw s chars
 if the char has the same previous and next characters of the char number (x) of type (y) in t then they match
else  try to match with previous char number in t .
//abaaba
//ababa
here the second b doesn't match with the second b in t so try to match it with the first b .
*/

bool used[200009];
bool vis[28];


int prevv[200009][28];
int nextt[200009][28];
int prevv2[200009][28];
int nextt2[200009][28];
int M[28][200009];
int cur[28];
int countt[28];
//bool vis[200009];
int last [28];
int main()
{

    /*
    mem(last, -1 );
    mem(M, -1 );
    ios_base::sync_with_stdio(false);
    string s, t ;
    cin >> s >> t ;
    mem(countt, 0 );
    mem(cur, 0 );

    rep( i, sz(s))
    {
        rep( j, 26 )
        prevv2[i][j] = cur[j];
        cur[s[i]-'a']++;
    }

    mem(cur, 0 );
    string r = s ;
    reverse(all(r));
    rep( i, sz(r))
    {
        rep(j, 26 )
        nextt2[sz(r)-i-1][j] = cur[j];
        cur[r[i]-'a']++;
    }

    mem(cur, 0 );
    rep( i, sz(t))
    {
        rep( j, 26 )
        prevv[i][j] = cur[j];
        countt[t[i]-'a']++;
        M[t[i]-'a'][countt[t[i]-'a']] = i;
        cur[t[i]-'a']++;
    }

    mem(cur, 0 );
    r = t ;
    reverse(all(r));
    rep( i, sz(r))
    {
        rep( j, 26 )
        nextt[sz(r)-i-1][j] = cur[j];
        cur[r[i]-'a']++;
    }

    mem(cur, 0 );
    rep(i, sz(s))
    {
        int temp = M[s[i]-'a'][min(cur[s[i]-'a']+1,countt[s[i]-'a']) ];
        if (temp == -1 )
        {
            puts("No");
            return 0;
        }

        int ttt = -1 ;
        rep( j, 26 )
        if ( prevv[temp][j] > prevv2[i][j] )
        {
            if ( last[s[i]-'a'] == -1 ) // first appear of char .
            {
                puts("No");
                return 0;
            }
            else // try to match with previous one  in t
            {
                ttt = last[s[i]-'a']; // last match with this char
                temp = ttt;
// prevv
                rep( j, 26 )
                if ( prevv[ttt][j] > prevv2[i][j])
                {
                    puts("No");
                    return 0;
                }

                // next char
                rep( j, 26 )
                if (nextt[ttt][j] > nextt2[i][j])
                {
                    puts("No");
                    return 0;
                }
            }
        }

        rep( j, 26 )
        if (nextt[temp][j] > nextt2[i][j])
        {
            puts("No");
            return 0;
        }

     last[s[i]-'a'] = temp;

        if (ttt == -1 ) // match with previous char
        {
            vis[temp] = 1;
            cur[s[i]-'a']++;// new char of this type appear
        }
    }

    rep( i, sz(t))
    if ( vis[i] == 0 ) // every char in t is used , one match occur
    {
        puts("No");
        return 0;
    }

    puts("Yes");
*/

string s , t ;
int cur = 0 ;
cin >> s >> t ;
rep(i , sz(s)){
if (s[i] == t[cur] ){
used[cur] = 1;
    cur++;
}
    else if (vis[s[i]-'a'] == 1 )
        continue;
if (cur == sz(t))
    cur %= sz(t);
vis[s[i]-'a'] = 1;
//cout << i << " " << cur << endl;
}
rep( i , sz(t))
if (used[i] == 0 )
    {
        puts("No");
    return 0;
}
    cout << "Yes" << endl;
}
