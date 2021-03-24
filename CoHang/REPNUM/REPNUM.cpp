//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 20
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "REPNUM"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, k, MOD, z[25], res= 0;

struct mtrx
{
    int f[25][25];
    mtrx(){
        memset(f, 0);
    }
}F[45], C;

int calc(int a, int b)
{
    int c= 0;
    for(; b> 0; a= (a+ a)% MOD)
    {
        if(b% 2) c= (c+ a)% MOD;
        b/= 2;
    }
    return c;
}

mtrx mul(mtrx A, mtrx B)
{
    mtrx c;
    //forr(i, 1, n) C.f[i][i]= 1;
    forr(i, 1, n)
        forr(j, 1, n)
            forr(e, 1, n)
                c.f[i][j]= (c.f[i][j]+ calc(A.f[i][e], B.f[e][j]))% MOD;
    return c;
}

void RESET()
{
    forr(e, 0, 40)
    forr(i, 1, n+ 2)
    forr(j, 1, n+ 2)
    F[e].f[i][j]= 0;
}

void init()
{
    forr(i, 1, n- 1)
    forr(j, i+ 1, n)
    if(__gcd(z[i], z[j])== 1)
    {
        F[0].f[i][j]= 1;
        F[0].f[j][i]= 1;
    }
}

void work()
{
    forr(i, 1, 40)
    F[i]= mul(F[i- 1], F[i- 1]);

    forr(i, 0, 40)
    if((k>> i)& 1)
        C= mul(C, F[i]);

    //res= C.f[1][n- 1];
}

void again()
{
    forr(i, 1, n+ 2)
    forr(j, 1, n+ 2)
    C.f[i][j]= 0;
    forr(i, 1, n) C.f[i][i]= 1;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> t;
    while(t--){
        cin>> n>> k>> MOD;
        RESET();
        forr(i, 1, n) cin>> z[i];

        //++n;
        init();
        again();
        ++n;
        F[0].f[n- 1][n]= 1;
        ++n;
        F[0].f[n- 1][n]= F[0].f[n][n- 1]= 1;

        ++k;
        work();
        res= (C.f[1][n- 1]+ C.f[1][n])% MOD;

//        --k;
//
//        again();
//        forr(i, 0, 40)
//        if((k>> i)& 1)
//            C= mul(C, F[i]);
//
//        res= (res+ C.f[1][n- 2])% MOD;

        cout<< res<< "\n";

    }

    return 0;
}
