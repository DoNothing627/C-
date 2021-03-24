#include <bits/stdc++.h>
#define int long long
#define mn 10000000
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int t, n, oo, k, f[10000005], g[10000005];

int power(int a, int b)
{
    int c= 1;
    for(; b> 0; a= (a* a)% oo)
    {
        if(b% 2) c= (c* a)% oo;
        b/= 2;
    }
    return c;
}

void init()
{
    f[0]= 1;
    for(int i= 1; i<= n; i++)
    f[i]= (f[i- 1]* i)% oo;
    for(int i= 0; i<= n; i++)
    g[i]= power(f[i], oo- 2);
}

int C(int K, int N)
{
    int ans= (f[N]* g[K])% oo;
    ans= (ans* g[N- K])% oo;
    return ans;
}

main()
{
    freopen("cute.inp", "r", stdin);


    //cout<< mn;

    cin>> t;
    while(t--){
        cin>> n>> k>> oo;
        init();
        cout<< C(k, n)<< "\n";
    }
}
