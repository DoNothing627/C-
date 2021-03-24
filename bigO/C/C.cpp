//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, q, I[40][mn], a[mn];

void up(int j, int x, int val)
{
    while(x<= n){
        I[j][x]+= val;
        x+= (x& (- x));
    }
}

int get(int j, int x)
{
    int ans= 0;
    while(x> 0){
        ans+= I[j][x];
        x-= (x& (- x));
    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> q;

    forr(i, 1, n) cin>> a[i];

    forr(i, 1, n){
        forr(j, 0, 30)
            if(((a[i]>> j)& 1)== 1) up(j, i, 1);
    }

    while(q--){
        int type, l, r;
        cin>> type>> l>> r;
        if(type== 1){
            forr(j, 0, 30)
                if(((a[l]>> j)& 1)== 1) up(j, l, -1);
            a[l]= r;
            forr(j, 0, 30)
                if(((a[l]>> j)& 1)== 1) up(j, l, 1);
        }
        else{
            long long res= 0;
            forr(j, 0, 30)
            {
                int ans= get(j, r)- get(j, l- 1);
                ans= r- l+ 1- ans;
                if(ans> (r- l+ 1) / 2) res+= (1<< j);
            }
            cout<< res<< "\n";
        }
    }

    return 0;
}
