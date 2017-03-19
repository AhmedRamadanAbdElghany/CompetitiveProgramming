#include <bits/stdc++.h>
using namespace std;
typedef double db;


/*
given n points find the point in x axis (y = 0 )where the largest distance
between that point and any of n points is minimum .
  
there is a pattern for the distance of the n points to the needed point    
IIIIDDDDDIIIII  where I means Increasing ,D means Deceasing .
so used ternary search to get needed point 

*/


int n ;
pair < db, db >  arr[500001];

db f( db mid )
{
    db mx = 0 ;
    for (int i = 0 ; i < n ; i ++ )
    {
        db temp = (arr[i].first - mid) * (arr[i].first - mid) + arr[i].second * arr[i].second ;
        mx = max(mx, temp );
    }
    return mx ;
}

db mn,mx  ;
pair<double, double> ternaryReal()
{
    double left = mn, right = mx;
    while (right - left > 1e-8)
    {
        double g = left + (right - left) / 3
                   , h = left + 2 * (right - left) / 3;

        if (f(g) < f(h) )
            right = h;
        else
            left = g;
    }

    return make_pair(left, f(left));
}


int main ()
{
    while( cin >> n && n )
    {
        mn = 1e9, mx = 0 ;
        for (int i = 0 ; i < n ; i ++ )
        {
            cin >> arr[i].first >> arr[i].second;
            mn = min (mn, arr[i].first);
            mx = max (mx, arr[i].first);

        }
        pair < db, db > ans = ternaryReal();
        cout <<  fixed <<setprecision(6) << ans.first << " " << fixed <<setprecision(6)<<sqrt(ans.second) << endl;
    }
}
