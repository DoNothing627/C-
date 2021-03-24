//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 205
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "NKMINES"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, m, a[mn][mn], c[mn][mn];

int sum(int u, int v)
{
    return a[u- 1][v- 1]+ a[u- 1][v]+ a[u- 1][v+ 1]+
           a[u][v- 1]               + a[u][v+ 1]+
           a[u+ 1][v- 1]+ a[u+ 1][v]+ a[u+ 1][v+ 1];
}

bool Try(int u, int v){
   int t, u2,v2;
   if(u==m || v==1){
         if(u+v>=n) { v2 = n; u2 = u+v+1-v2;}
         else { u2 = 1; v2= u+v+1-u2;}
   }
   else{ u2 = u+1; v2 = v-1;}

   if(u==m && v==n){
      a[u][v]=0; t=c[u-1][v-1]-sum(u-1, v-1);
      if(t<0 || t>1) return false;
      a[u][v]=t; return true;
   }
   if(u==1|| v== 1){
      a[u][v]=0; if(Try(u2, v2)) return true;
      a[u][v]=1;
      return Try(u2, v2);
   }

   a[u][v]=0; t=c[u-1][v-1]-sum(u-1, v-1);
   if(t<0 || t>1) return false;
   a[u][v]=t;
   if(u==m && sum(u, v-1)!=c[u][v-1]) return false;
   if(v==n && sum(u-1, v)!=c[u-1][v]) return false;
   return Try(u2, v2);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> m>> n;
    forr(i, 1, m)
    forr(j, 1, n)
    cin>> c[i][j];

    a[1][1]= 0; if(Try(1, 2)) goto over;
    memset(a, 0);
    a[1][1]= 1;
    Try(1, 2);

    over: ;

    forr(i, 1, m)
    {
        forr(j, 1, n) cout<< a[i][j]<< " ";
        cout<< "\n";
    }

    return 0;
}
