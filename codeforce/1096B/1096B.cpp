//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 998244353
#define int long long
#define DoNothing "1096B"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n;
string s;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> s;
    char c= s[0];
    int i= 0;
    while(s[i]== c) i++;
    c= s[n- 1];
    int j= n- 1;
    while(s[j]== c) j--;
    int ans= i+ n- j;
    if(s[0]== s[n- 1])
        ans= (ans+ i* (n- j- 1))% oo;
    cout<< ans;

    return 0;
}
