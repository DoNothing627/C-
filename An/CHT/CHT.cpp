#include <bits/stdc++.h>
#define oo 1000000007
#define mn 1000010
#define LLC "CHT"
#define pb push_back
#define ii pair< double, double>
#define a first
#define b second
using namespace std;
ii p[mn];
long S[mn], top= 2, n, h[mn], k;

double gd(int u, int v)
{
    return (p[v].b- p[u].b)/ (p[u].a- p[v].a);
}
bool sx(ii A, ii B)
{
    return A.a> B.a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(LLC".inp", "r", stdin);
    //freopen(LLC".out", "w", stdout);
    cin>> n;
    for(int i= 1; i<= n; i++)
        cin>> p[i].a>> p[i].b;
    sort(p+ 1, p+ n+ 1, sx);
    S[1]= 1, S[2]= 2;
    for(int i= 3; i<= n; i++)
    {
        while(top> 2&& gd(S[top- 1], i)< gd(S[top], i)) --top;
        S[top++]= i;
    }
    h[0]= -oo;
    for(int i= 1; i< top; i++)
        h[i]= gd(S[i], S[i+ 1]);
    h[top]= oo;
    cin>> k;
    while(k--){
        long x;
        cin>> x;
        int id= lower_bound(h, h+ top+ 1, x)- h;
        id= S[id];
        double res= p[id].a* x+ p[id].b;
        cout<< res<< "\n";
    }
    return 0;
}
