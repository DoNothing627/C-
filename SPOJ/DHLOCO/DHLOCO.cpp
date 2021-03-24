//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 100000000007
#define int long long
#define DoNothing "DHLOCO"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m;


struct mtrx
{
    int a[3][3];
    mtrx(){memset(a, 0);}
};


int calc(int x)
{
    x%= m;
    while(x< 0) x+= m;
    return x;
}


mtrx mul(mtrx A ,mtrx B)
{
    mtrx C;
    /*forr(i, 0, 2)
    {
        forr(j, 0, 2) cout<< C.a[i][j]<< " ";
        cout<< "\n";
    }*/
    forr(i, 0, 2)
    forr(j, 0, 2)
    forr(k, 0, 2)
    C.a[i][j]= calc(C.a[i][j]+ calc(A.a[i][k]* B.a[k][j]));
    return C;
}


mtrx power(mtrx A, int b)
{
    mtrx C;
    C.a[0][0]= C.a[1][1]= C.a[2][2]= 1;
    for(; b> 0; A= mul(A, A))
    {
        if(b% 2) C= mul(C, A);
        b/= 2;
    }
    return C;
}



main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;

    mtrx A, C;

    A.a[0][0]= A.a[0][1]= A.a[0][2]= A.a[1][0]= A.a[2][1]= 1;

    C= power(A, n- 3);

    cout<< calc(4* C.a[0][0]+ calc(2* C.a[0][1]+ C.a[0][2]));
    //cout<< C.a[0][0]<< " "<< C.a[0][1]<< " "<< C.a[0][2];

    return 0;
}
