#include <bits/stdc++.h>
#define forr(i,a,b) for( long i=a ; i<=b ; ++i)
#define ll long long
#define s second
#define f first

using namespace std;

const long dad=2e6;
long n,k,m,test ;
long long t[2000],ans ;
pair< long,long > a[dad] ;


ll get(long u)
{
ll res=0;
while (u>0)
{
res+=t[u];
u-=u&-u;
}
return res;
}

void update(long u)
{
while (u<=m)
{
++t[u];
u+=u&-u;
}
}

void reset()
{
memset(t,0,sizeof(t));
ans=0ll;
}

int main()
{
// cout << "Hello world!" << endl;
// freopen( "MSE06H.inp" , "r" , stdin );
scanf("%d",&test);
forr(itest,1,test)
{
reset();
scanf("%d%d%d",&n,&m,&k);
forr(i,1,k) scanf("%d%d",&a[i].f,&a[i].s);
sort(a+1,a+k+1);
forr(i,1,k)
{
ans+=i-1-get(a[i].s);
update(a[i].s);
}

printf("Test case %d: %lld\n",itest,ans);
}
return 0;
}
