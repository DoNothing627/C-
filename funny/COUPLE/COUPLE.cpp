#include <bits/stdc++.h>

using namespace std;

int n, a[1000005], S, c, d;
long long res= 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("COUPLE.inp", "r", stdin);
    freopen("COUPLE.out", "w", stdout);

    cin>> n>> S;
    for(int i= 1; i<= n; i++)
        cin>> a[i];

    /*sort(a+ 1, a+ n+ 1);

    for(int i= 1; i<= n; i++)
    {
        int b= S- a[i];
        if(b< 0) break;
        c= lower_bound(a+ 1, a+ n+ 1, b)- a;
        d= upper_bound(a+ 1, a+ n+ 1, b)- a;
        res+= (d- c);
        if(a[i]== b) --res;
    }

    cout<< res/ 2;*/

    for(int i= 1; i<= n; i++)
        for(int j= i+ 1; j<= n; j++)
            if(a[i]+ a[j]== S) ++res;

    cout<< res;


    return 0;

}
