//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "CAKES"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, t, res, ans;
ii a[mn];
priority_queue< ii> pq;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> t;
    forr(i, 1, n){
        cin>> a[i].x>> a[i].y;
        pq.push(ii(a[i].y, i));
        ans+= a[i].y;
        while(pq.size()&& a[i].x+ ans> t){
            ans-= a[pq.top().y].y;
            pq.pop();
        }
        int c= pq.size();
        res= max(res, c);

    }

    cout<< res;

    return 0;
}
