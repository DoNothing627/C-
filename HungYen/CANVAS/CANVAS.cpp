//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "CANVAS"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, k, m, a[4001][101][101], save[4005], cnt= 0;
string s;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> k>> m;

    forr(i, 0, n- 1)
        forr(j, 0, n- 1)
            a[0][i][j]= 1;

    forr(COUNT, 1, m)
    {
        int o, x, y, u, v;
        cin>> s;
        int r= COUNT- 1;
        if(s== "PAINT"){
            cin>> o>> x>> y>> u>> v;
            forr(i, 0, n- 1)
                forr(j, 0, n- 1)
                {
                    a[COUNT][i][j]= a[r][i][j];
                    if(i>= x&& i<= u&& j>= y&& j<= v&& (i+ j)% 2== (x+ y)% 2) a[COUNT][i][j]= o;
                }
        }
        else{
            if(s== "SAVE") save[++cnt]= COUNT;
            else{
                cin>> o;
                r= save[o];
            }
            forr(i, 0, n- 1)
                forr(j, 0, n- 1)
                    a[COUNT][i][j]= a[r][i][j];
        }
    }

    forr(i, 0, n- 1)
    {
        forr(j, 0, n- 1)
            cout<< a[m][i][j]<< " ";
        cout<< "\n";
    }

    return 0;
}
