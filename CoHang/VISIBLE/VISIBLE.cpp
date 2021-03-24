//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "VISIBLE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a[mn], l[mn], r[mn];
stack< int> S;
string s;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n) cin>> a[i];
    cin>> s;
    s= " "+ s;

    forr(i, 1, n){
        while(S.size()&& a[i]>= a[S.top()]) S.pop();
        if(S.empty()) r[1]= i;
        else r[S.top()]= i;
        S.push(i);
    }

    forr(i, 1, n)
    r[i]= max(r[i- 1], r[i]);
    //S.clear();
    while(S.size()) S.pop();

    memset(l, 40);
    for(int i= n; i> 0; i--)
    {
        while(S.size()&& a[i]>= a[S.top()]) S.pop();
        if(S.empty()) l[n]= i;
        else l[S.top()]= i;
        S.push(i);
    }

    forr(i, 1, n)
    l[i]= min(l[i+ 1], l[i]);

    forr(i, 1, n)
    {
        if(s[i]== 'L') cout<< i- l[i]<< " ";
        else cout<< r[i]- i<< " ";
    }

    return 0;
}
