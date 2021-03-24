//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 400005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "PROJECT"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a[mn], f[2* mn], c[mn], res= 0, h, s, d, m;
deque< int> q;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> h>> s>> d;

    m= (h+ d)/ s;
    forr(i, 1, n) cin>> a[i];

    forr(i, 1, m){
        f[1]= max(f[1], a[i]);
        while(q.size()&& a[i]>= a[q.front()]) q.pop_front();
        q.push_front(i);
    }

    forr(i, m+ 1, n+ m- 1)
    {
        while(q.size()&& a[i]>= a[q.front()]) q.pop_front();
        while(q.size()&& i- q.back()>= m) q.pop_back();
        q.push_front(i);
        f[n- m+ 1]= a[q.back()];

    }

    //c[1]= a[1];
    f[0]= 1;
    forr(i, 0, n)
    {
        res+= s* c[i];
        if(c[i]<= f[i]){
            c[i+ 1]= c[i];
            if(a[i+ 1]> c[i]){
                res+= (a[i+ 1]- c[i])* h;
                c[i+ 1]= a[i+ 1];
            }
        }
        else{
            c[i+ 1]= a[i+ 1];
            res+= (c[i]- c[i+ 1])* d;
        }
    }

    cout<< res<< "\n";
    forr(i, 1, n) cout<< c[i]<< " ";

    return 0;
}
