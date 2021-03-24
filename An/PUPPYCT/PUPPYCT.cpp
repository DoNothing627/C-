//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 2000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "PUPPYCT"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, k, res= 0, z;
ii p[mn];
bool chek[mn], a[mn], d[mn];
vector< int> f[4][2];

void RESET()
{
    forr(i, 0, 3)
        forr(j, 0, 1)
            f[i][j].clear();
    memset(chek, 0);
    memset(a, 0);
    memset(d, 0);
    res= 0;
}

void COW()
{
    while(t--)
    {
        cin>> n>> k;

        RESET();
        forr(i, 1, k)
        {
            int u, v;
            cin>> u>> v;
            int sum= u+ v;
            if(!chek[sum])
            {
                if(sum- 1<= n){
                    f[0][sum% 2].pb(sum- 1);
                    f[3][sum% 2].pb(sum- 1);
                    res+= sum- 1;
                }
                else{
                    f[1][sum% 2].pb(sum- n);
                    f[2][sum% 2].pb(sum- n);
                    res+= n- sum+ n+ 1;
                }
                chek[sum]= 1;
            }
            p[i]= ii(u, v);
        }

        forr(i, 0, 3)
            forr(j, 0, 1)
                if(f[i][j].size())
                    sort(f[i][j].begin(), f[i][j].end());

        /*forr(i, 0, 3)
        {
            forr(j, 0, 1)
            {
                cout<< i<< " "<< j<< " ";
                for(auto cc: f[i][j])
                    cout<< cc<< " ";
                cout<< "\n";
            }
        }*/

        forr(i, 1, k)
        {
            int u= p[i].x, v= p[i].y;
            int c= u- v;
            if(c> 0){
                if(!a[c]){
                    res+= n- c;
                    if(f[3][c% 2].size()){
                        z= lower_bound(f[3][c% 2].begin(), f[3][c% 2].end(), c+ 1)- f[3][c% 2].begin();
                        res-= (f[3][c% 2].size()- z);
                    }
                    if(f[2][c% 2].size()){
                        z= upper_bound(f[2][c% 2].begin(), f[2][c% 2].end(), n- c)- f[2][c% 2].begin();
                        res-= z;
                    }
                    a[c]= 1;
                }
            }
            else{
                c*= -1;
                if(!d[c]){
                    res+= n- c;
                    if(f[0][c% 2].size()){
                        z= lower_bound(f[0][c% 2].begin(), f[0][c% 2].end(), 1+ c)- f[0][c% 2].begin();
                        res-= (f[0][c% 2].size()- z);
                    }
                    if(f[1][c% 2].size()){
                        z= upper_bound(f[1][c% 2].begin(), f[1][c% 2].end(), n- c)- f[1][c% 2].begin();
                        res-= z;
                    }
                    d[c]= 1;
                }
            }
        }

        cout<< n* n- res<< "\n";

    }
}

void BUFF()
{
    while(t--)
    {
        cin>> n>> k;
        RESET();
        forr(i, 1, k)
        {
            int u, v;
            cin>> u>> v;
            chek[u+ v]= 1;
            int c= u- v;
            if(c> 0) a[c]= 1;
            else{
                c*= -1;
                d[c]= 1;
            }
        }
        forr(i, 1, n)
            forr(j, 1, n)
            {
                if(chek[i+ j]) continue;
                int c= i- j;
                if(c> 0){
                    if(a[c]) continue;
                }
                else{
                    c*= -1;
                    if(d[c]) continue;
                }
                ++res;
                //cout<< i<< " "<< j<< "\n";
            }
        cout<< res<< "\n";
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;

    //BUFF();

    COW();

    return 0;
}
