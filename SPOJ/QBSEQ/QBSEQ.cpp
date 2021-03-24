//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "QBSEQ"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, k, a[mn], f[mn][55], b[mn][55], s, y;

void BUFF()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=a[i]%k;
        s+=a[i];
    }
    s=s%k;
    b[0][0]=0;
    for(int i=1;i<=k;i++)
        b[0][i]=1000000000;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
    {
        y=(j-a[i])%k;
        if(y<0) y+=k;
        b[i][j]=min(b[i-1][j],b[i-1][y]+1);
    }
    cout<<n-b[n][s];
}

void COW()
{
    cin>> n>> k;
    forr(i, 1, n)
    {
        cin>> a[i];
        a[i]%= k;
    }

    memset(f, -40);
    f[0][0]= 0;

    forr(i, 1, n)
        forr(j, 0, i- 1)
            forr(z, 0, k- 1)
                f[i][(z+ a[i])% k]= max(f[i][(z+ a[i])% k], f[j][z]+ 1);

    cout<< f[n][0];

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    BUFF();
    COW();

    return 0;
}
