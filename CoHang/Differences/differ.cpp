//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 300005
#define pb push_back
#define oo 100000000007
#define int long long
#define DoNothing "differ"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, a[mn], LAX[mn], LIN[mn], res= 0, c;
stack< int> MAX, MIN;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n) cin>> a[i];

    forr(i, 1, n)
    {
        while(MAX.size()&& a[i]> a[MAX.top()]) MAX.pop();
        if(MAX.size()) LAX[i]= MAX.top();
        else LAX[i]= 0;
        MAX.push(i);
        while(MIN.size()&& a[i]< a[MIN.top()]) MIN.pop();
        if(MIN.size()) LIN[i]= MIN.top();
        else LIN[i]= 0;
        MIN.push(i);
    }

    while(MAX.size()) MAX.pop();
    while(MIN.size()) MIN.pop();

    for(int i= n; i> 0; i--)
    {
        while(MAX.size()&& a[i]>= a[MAX.top()]) MAX.pop();
        if(MAX.size()) c= MAX.top();
        else c= n+ 1;
        res+= (c- i)* (i- LAX[i])* a[i];
        MAX.push(i);
        while(MIN.size()&& a[i]<= a[MIN.top()]) MIN.pop();
        if(MIN.size()) c= MIN.top();
        else c= n+ 1;
        res-= (c- i) *(i- LIN[i])* a[i];
        MIN.push(i);
    }

    cout<< res;

    return 0;
}
