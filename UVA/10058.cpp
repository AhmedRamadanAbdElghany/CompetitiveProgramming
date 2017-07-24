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
/*
implementation problem 
*/


string NOUN[8] = {"tom", "jerry", "goofy", "mickey", "jimmy", "dog", "cat", "mouse"};

string VERB[4] = {"hate", "love", "know", "like"};

bool article(string s)
{
  return s == "a" || s == "the";
}

bool noun(string s)
{
   for (auto i : NOUN)
    if ( i == s  )
    return 1 ;
return 0;
}

bool verb(string s)
{
   for (auto i : VERB)
    if ( i == s || i +"s" == s )
    return 1 ;
return 0;
}

bool actor(string s)
{
  int i = s.find(" ");
  if(i == -1)
    return noun(s);
  return article(s.substr(0, i)) && noun(s.substr(i + 1));
}

bool active_list(string s)
{
  int i = s.rfind(" and ");
  if(i == -1)return actor(s);
  return  active_list(s.substr(0, i)) && actor(s.substr(i + 5));
}

bool action(string s)
{
  int cnt = 0, idx;
  istringstream iss(s);
  vector<string> v;
  string t;
  while(iss >> t)v.push_back(t);
  if(v.size() < 3)return false;
 rep( i , sz(v))
    if(verb(v[i])){
      ++cnt;
      idx = i;
    }

  if(cnt != 1)
    return false;
  string p, q;
rep( i , idx){
    if(p.size())p += " ";
    p += v[i];
  }
  REP( i , idx + 1 , sz(v)){
    if(q.size())q += " ";
    q += v[i];
  }
  return active_list(p) && active_list(q);
}

bool statement(string s)
{
  int i = s.rfind(" , ");
  if(i == -1)
    return action(s);
  return statement(s.substr(0, i))
   && action(s.substr(i + 3));
}


string reg(string s)
{
string u , t ="" ;
  istringstream iss(s);
  while(iss >> u){
    if(t.size())t += " ";
    t += u;
  }
  return t;
}

int main(void)
{
  const string T = "YES I WILL";
  const string F = "NO I WON'T";
  string s, t;


  while(getline(cin, s)){
    t = reg(s);
    cout << (t.size() && statement(t) ? T : F) << endl;
  }
  return 0;
}
