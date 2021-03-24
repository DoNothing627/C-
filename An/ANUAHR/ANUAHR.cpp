//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "ANUAHR"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, m, res= 0;
priority_queue< int> q;
ii a[mn];

void RESET()
{
    while(q.size()) q.pop();
    res= 0;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n>> m;
        m= n- m;
        forr(i, 1, n)
        cin>> a[i].x>> a[i].y;
        sort(a+ 1, a+ n+ 1);
        RESET();
        for(int i= n; i> 0; i--)
        {
            q.push(-a[i].y);
            //if(i== n- m+ 1) res= max(res, a[i].x* -q.top());
            if(i<= n- m) q.pop();
            if(i<= n- m+ 1) res= max(res, a[i].x* -q.top());
        }
        cout<< res<< "\n";
    }


    return 0;
}
