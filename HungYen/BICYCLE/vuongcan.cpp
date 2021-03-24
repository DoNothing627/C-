#include<bits/stdc++.h>
using namespace std;
long f[5000][5000];
long n,i,j;
long a[5000][5000];
long h=0;
int main()
{
    freopen("vuongcan.inp","r",stdin);
    freopen("vuongcan.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        cin>>a[i][j];
        f[i][j]=1;
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        if(a[i][j]==a[i-1][j-1] && a[i][j]==a[i-1][j] && a[i][j]==a[i][j-1])
            f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
        h=max(h,f[i][j]);
    }
    cout<<h;
    return 0;
}
