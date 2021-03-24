#include <bits/stdc++.h>
using namespace std;
long n;
int a[5005][5005];
long f[5005][5005];
int main()
{
    freopen("vuongcan.inp","r",stdin);
    freopen("vuongcan.out","w",stdout);
    cin>>n;
    for(long i=1;i<=n;i++)
        for(long j=1;j<=n;j++)
        cin>>a[i][j];
    memset(f,0,sizeof(f));
    long res=0;
    for(long i=1;i<=n;i++)
        for(long j=1;j<=n;j++)
        {if(a[i][j]==1)
        f[i][j]=min(f[i-1][j],f[i][j-1])+1;
        res=max(res,f[i][j]);}
    cout<<res;
    return 0;
}
