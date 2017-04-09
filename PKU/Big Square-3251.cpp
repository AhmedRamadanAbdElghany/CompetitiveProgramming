#include <string>
#include <cstdio>
#include <vector>
#include<iostream>
#include <map>
using namespace std;
/*

given points in 2d grid each point can be a corner of a square and we can choose a free point and mark it as a corner if needed 
find the maximum area can be found .
so the native brute force solution will be O(n^3) .
sketching many squares find that if we have 2 points(a , b ) we can find the others (c , d ) and we have two choices for the other
2 point as they can be left or the right .
dy = b.y - a.x .
dx = b.x - a.x .
first choice :
c1x = b.x + dy .
c1y = b.y - dx .
d1x = a.x + dy .
d1y = a.y - dx .
second choice (other dimension ):
c1x = b.x - dy .
c1y = b.y + dx .
d1x = a.x - dy .
d1y = a.y + dx .
then for every two points find the other two points and maximize over them .


 



*/



int n;
vector< pair<int,int> > v;

bool in(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}
bool inn[101][101];
bool invalid[101][101];
bool exist(pair < int, int > d  )
{
    return inn[d.first][d.second];
}
int main()
{
    string s ;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        cin >> s ;
        for(int j = 0; j < n; j++)
        {
            if(s[j] == 'J')
            {
                v.push_back(make_pair(i,j)); // find all corner points 
                inn[i][j] = 1;
            }
            else if (s[j] == 'B')
                invalid[i][j] = 1 ;
        }
    }

    int ans = 0;
    for(int i = 0; i < v.size(); i++)
        for(int j = i+1; j < v.size(); j++)
        {
            pair<int,int> a = v[i], b = v[j];
            int di = b.first - a.first, dj = b.second - a.second;
            pair<int,int> c = make_pair(b.first + dj, b.second - di);
            pair<int,int> d = make_pair(a.first + dj, a.second - di);

            if(in(c.first, c.second) && in(d.first, d.second) && ((exist (c ) && invalid[d.first][d.second] == 0 ) 
            || ( exist (d ) && invalid[c.first][c.second] == 0 ) ))
            {
                ans =max(ans,  di*di+dj*dj);
                continue;
            }

            c = make_pair(b.first - dj, b.second + di);
            d = make_pair(a.first - dj, a.second + di);

            if(in(c.first, c.second) && in(d.first, d.second) && ((exist (c ) && invalid[d.first][d.second] == 0 ) 
            || ( exist (d ) && invalid[c.first][c.second] == 0 ) ))
            {
                ans =max(ans,  di*di+dj*dj);
            }
        }
    printf("%d\n", ans);
    return 0;
}



