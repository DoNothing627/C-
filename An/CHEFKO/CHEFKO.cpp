//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 1000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "CHEFKO"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int t, n, k, res= 0;
ii p[mn];


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    //memset(c, 40);

    cin>> t;
    while(t--)
    {
        res= 0;
        cin>> n>> k;
        forr(i, 1, n)
            cin>> p[i].x>> p[i].y;

        sort(p+ 1, p+ n+ 1);

        priority_queue< int> pq;

        forr(i, 1, n)
        {
            while(pq.size()&& p[i].x> -pq.top()) pq.pop();
            pq.push(-p[i].y);
            while(pq.size()> k) pq.pop();
            if(pq.size()== k) res= max(res, -pq.top()- p[i].x);
        }
        cout<< res<< "\n";
    }

    return 0;
}
