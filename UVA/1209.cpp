#include <bits/stdc++.h>
using namespace std;


/*
easy ad hock problem need to find the s the largest minimum absolute distance between consecutive letters of the twenty-one permutation of a string .
so using next_permutation and prev_permutation.

*/




int fun(string s )
{
    int ans = 10000;
    for (int i = 1 ; i < s.size() ; i++ )
        ans =min( ans,  abs (s[i] - s[i-1]));
    return ans ;

}

int main()
{
    string s, y, sol ;

    while(cin >> s )
    {
        int i = 0;
        y = s ;
        int ans = 0;
        do
        {
            i++;
            int u = fun(s);
            if ( u >= ans )
                ans = u, sol = s;
        }
        while(prev_permutation(s.begin(), s.end()) && i <=10);

        next_permutation(y.begin(),y.end());
        s = y ;
        i = 0 ;
        do
        {
            i++;
            int u = fun(s);
            if ( u > ans )
                ans = u, sol = s;
        }
        while(next_permutation(s.begin(), s.end()) && i < 10);
        cout << sol << ans<<endl;

    }
}

