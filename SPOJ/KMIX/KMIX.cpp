//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "KMIX"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, t;
ii a[mn], o;
//vector< int> h, _h;

bool ccw(ii O, ii A, ii B)
{
    A.x-= O.x, A.y-= O.y;
    B.x-= O.x, B.y-= O.y;
    return 1ll* A.x* B.y> 1ll* A.y* B.x;
}

long long c(ii O, ii A, ii B)
{
    A.x-= O.x, A.y-= O.y;
    B.x-= O.x, B.y-= O.y;
    return 1ll* A.x* B.y- 1ll* A.y* B.x;
}

bool cmp(ii A, ii B)
{
    return ccw(o, A, B);
}

bool chek(int u, int v)
{

    if(n== 1){
        if(u== a[1].x&& v== a[1].y) return 1;
        return 0;
    }

    int l= 2, r= n;

    a[n+ 1]= ii(u, v);
    while(r- l> 1){
        int m= (r+ l)/ 2;
        if(ccw(a[1], a[m], a[n+ 1])) l= m;
        else r= m;
    }

    if(ccw(a[r], a[l], a[n+ 1])) return 0;
    if(ccw(a[1], a[r], a[n+ 1])) return 0;
    if(ccw(a[1], a[n+ 1], a[l])) return 0;
    return 1;

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
        cin>> a[i].x>> a[i].y;
    cin>> t;
    sort(a+1, a+n+1);
    if(n== 2){
        while(t--){
            int u, v;
            cin>> u>> v;
            a[n+ 1]= ii(u, v);
            if(c(a[1], a[2], a[3])!= 0) cout<< "NO\n";
            else{
                if(a[1].x<= u&& a[2].x>= u&& max(a[1].y, a[2].y)>= v&& min(a[1].y, a[2].y)<= v)
                    cout<< "YES\n";
                else cout<< "NO\n";
            }
        }
        return 0;
    }

    o = a[1];
    sort(a+2, a+n+1, cmp);
    a[0]=a[n]; a[n+1]=a[1];
    int j=1;
    for (int i=1; i<=n+1; i++){ // a[1] and a[n+1] will be both added
        while (j>2 && !ccw(a[j-2], a[j-1], a[i])) j--;
        a[j++]=a[i];
    }
    n=j-2;



    while(t--){
        int u, v;
        cin>> u>> v;

        if(chek(u, v)) cout<< "YES\n";
        else cout<< "NO\n";

    }

    return 0;
}
