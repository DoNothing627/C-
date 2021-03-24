//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "EKO"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, k, a[mn];

bool chek(int m)
{
    int id= 1, res= 1;
    while(1){
        id= lower_bound(a+ 1, a+ n+ 1, a[id]+ m)- a;
        if(id== n+ 1) break;
        ++res;
        if(res== k) return true;
    }
    return false;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        int MAX= 0;
        cin>> n>> k;
        forr(i, 1, n)
        {
            cin>> a[i];
            MAX= max(MAX, a[i]);
        }
        sort(a+ 1, a+ n+ 1);
        int l= 0, r= MAX+ 1;
        while(r- l> 1){
            int m= (l+ r)/ 2;
            if(chek(m)) l= m;
            else r= m;
        }
        cout<< l<< "\n";
    }

    return 0;
}
