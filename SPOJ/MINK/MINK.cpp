//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 17005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "MINK"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int t, n, k, a[mn];
deque< int> q;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);


    cin>> t;
    while(t--){

        while(q.size()) q.pop_back();
        cin>> n>> k;
        forr(i, 1, n) cin>> a[i];

        forr(i, 1, k)
        {
            while(q.size()&& a[i]<= a[q.front()]) q.pop_front();
            q.push_front(i);
        }
        cout<< a[q.back()]<< " ";

        forr(i, k+ 1, n)
        {
            while(i- q.back()+ 1> k) q.pop_back();
            while(q.size()&& a[i]<= a[q.front()]) q.pop_front();
            q.push_front(i);
            cout<< a[q.back()]<< " ";
        }

        cout<< "\n";
    }

    return 0;
}
