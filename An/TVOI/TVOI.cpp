#include <bits/stdc++.h>

using namespace std;
typedef pair<long,long>ii;
const long N=2505;
long n,k;
vector<long>a[N];
double l,r,mid,C[N],V[N];
double f[N][N],val[N];
long in[N],out[N],cnt,pos[N];
void nhap()
{
    cin>>k>>n;
    long u;
    long c,v;
    for(long i=1;i<=n;++i)
    {
        cin>>c>>v>>u;
        C[i]=c;
        V[i]=v;
        a[u].push_back(i);
    }
}
void dfs(long u)
{
    long v;
    in[u]=cnt;
    val[u]=(V[u]-mid*C[u]);
    for(long i=0;i<a[u].size();++i)
    {
        v=a[u][i];
        dfs(v);
        val[u]+=val[v];
    }
    out[u]=++cnt;
    pos[cnt]=u;
}
bool kt()
{
    for(long i=0;i<=n;++i)
    {
        for(long j=0;j<=n;++j)
            f[i][j]=1e9;
        val[i]=0;
    }
    cnt=0;
    dfs(0);
    f[0][n]=0;
    long u,res;
    for(long i=1;i<=n;++i)
    {
        for(long j=n;j>=1;--j)
        {
            f[i][j]=f[i-1][j];
            u=pos[i];
            res=(out[u]-in[u]);
            if(j+res<=n)
            f[i][j]=min(f[in[u]][j+res]+val[u],f[i][j]);
        }
    }
    return val[0]>=f[n][k];
}
void lam()
{
    r=1e9;
    l=0;
    while(r-l>1e-4)
    {
        mid=(l+r)/2;
        if(kt())
            l=mid;
        else
            r=mid;
    }
    mid=l;
    kt();
    cout<<fixed<<setprecision(3)<<l<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("tvoi.inp","r",stdin);
    //freopen("tvoi.out","w",stdout);
    nhap();
    lam();
    return 0;
}
