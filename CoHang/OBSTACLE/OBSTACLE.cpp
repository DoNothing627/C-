//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "OBSTACLE"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, k, cnt, I1[205][205][805], I2[205][205][805], lazy1[205][205][805], lazy2[205][205][805], q[205][205][55], p[205][205][55], res= 0, a[205][205], c[205], d[205], goal;




void up1(int z, int i, int k, int l, int r, int u, int v, int val)
{
    if(u> r|| v< l) return;
    if(l>= u&& r<= v){
        I1[z][i][k]= max(I1[z][i][k], val);
        lazy1[z][i][k]= max(lazy1[z][i][k], val);
        return;
    }
    int mid= (l+ r)/ 2;
    if(lazy1[z][i][k]){
        up1(z, i, 2* k, l, mid, l, r, lazy1[z][i][k]);
        up1(z, i, 2* k+ 1, mid+ 1, r, l, r, lazy1[z][i][k]);
        lazy1[z][i][k]= 0;
    }
    up1(z, i, 2* k, l, mid, u, v, val);
    up1(z, i, 2* k+ 1, mid+ 1, r, u, v, val);
    I1[z][i][k]= max(I1[z][i][2* k], I1[z][i][2* k+ 1]);
}


void up2(int z, int i, int k, int l, int r, int u, int v, int val)
{
    if(u> r|| v< l) return;
    if(l>= u&& r<= v){
        I2[z][i][k]= max(I2[z][i][k], val);
        lazy2[z][i][k]= max(lazy2[z][i][k], val);
        return;
    }
    int mid= (l+ r)/ 2;
    if(lazy2[z][i][k]){
        up2(z, i, 2* k, l, mid, l, r, lazy2[z][i][k]);
        up2(z, i, 2* k+ 1, mid+ 1, r, l, r, lazy2[z][i][k]);
        lazy2[z][i][k]= 0;
    }
    up2(z, i, 2* k, l, mid, u, v, val);
    up2(z, i, 2* k+ 1, mid+ 1, r, u, v, val);
    I2[z][i][k]= max(I2[z][i][2* k], I2[z][i][2* k+ 1]);
}


int get1(int z, int i, int k, int l, int r, int u)
{
    if(l> u|| r< u) return 0;
    if(l== r)
        return I1[z][i][k];
    int mid= (l+ r)/ 2;
    if(lazy1[z][i][k]){
        up1(z, i, 2* k, l, mid, l, r, lazy1[z][i][k]);
        up1(z, i, 2* k+ 1, mid+ 1, r, l, r, lazy1[z][i][k]);
        lazy1[z][i][k]= 0;
    }
    return max(get1(z, i, 2* k, l, mid, u), get1(z, i, 2* k+ 1, mid+ 1, r, u));
}

int get2(int z, int i, int k, int l, int r, int u)
{
    if(l> u|| r< u) return 0;
    if(l== r)
        return I2[z][i][k];
    int mid= (l+ r)/ 2;
    if(lazy2[z][i][k]){
        up2(z, i, 2* k, l, mid, l, r, lazy2[z][i][k]);
        up2(z, i, 2* k+ 1, mid+ 1, r, l, r, lazy2[z][i][k]);
        lazy2[z][i][k]= 0;
    }
    return max(get2(z, i, 2* k, l, mid, u), get2(z, i, 2* k+ 1, mid+ 1, r, u));
}


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> m>> n>> k;
    forr(i, 1, m)
    {
        char c;
        forr(j, 1, n){
            cin>> c;
            if(c== '*') a[i][j]= 1;
        }
    }

    forr(i, 1, m)
    {
        memset(d, 0);
        c[0]= 0, cnt= 0;
        forr(j, 1, n) if(a[i][j]) c[++cnt]= j, d[j]= cnt;
        forr(j, 0, n)
        {
            forr(z, 0, k)
            {
                if(d[j]+ z+ 1> cnt) goal= n+ 1;
                else goal= c[d[j]+ z+ 1];
                if(j+ 1<= goal- 1) up1(z, i, 1, 1, n, j+ 1, goal- 1, goal- j- 1);
            }
        }
    }

    forr(i, 1, n)
    {
        memset(d, 0);
        c[0]= 0, cnt= 0;
        forr(j, 1, m) if(a[j][i]) c[++cnt]= j, d[j]= cnt;
        forr(j, 0, m)
        {
            forr(z, 0, k)
            {
                if(d[j]+ z+ 1> cnt) goal= m+ 1;
                else goal= c[d[j]+ z+ 1];
                if(j+ 1<= goal- 1) up2(z, i, 1, 1, m, j+ 1, goal- 1, goal- j- 1);
            }
        }
    }


    forr(i, 1, m)
        forr(j, 1, n)
            forr(z, 0, k)
            {
                p[i][j][z]= get1(z, i, 1, 1, n, j);
                q[i][j][z]= get2(z, j, 1, 1, m, i);
            }

    forr(i, 1, m)
        forr(j, 1, n)
        {
            int C= k, e= 0;
            if(a[i][j]) ++C, e= 1;
            forr(z, e, k)
                res= max(res, p[i][j][z]+ q[i][j][C- z]- 1);
            //if(p[i][j][0]+ q[i][j][0]- 1== 284) cout<< i<< " "<< j<< " "<< a[i][j]<< "\n";
        }

    //cout<< a[7][115];
    //cout<< k;
    cout<< res;

    return 0;
}
