#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

long long x,n,ans = 1, maxc= 1000000007;
long long Pow(long long a,long long b)
{
    long long res = 1;
    for (;b;b >>= 1,a = (a * a) % maxc)
        if (b & 1) res = (res * a) % maxc;
    return res;
}
long long Pro(long long u)
{
    long long res = 1,temp = n / u;
    while (temp)
    {
        res = (res * Pow(u,temp)) % maxc;
        temp /= u;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
    //freopen(Task".inp", "r",stdin);
    //freopens(Task".out", "w",stdout);
    cin >> x >> n;
    FOR(i,2,sqrt(x))
    {
        if (x % i) continue;
        ans = (ans * Pro(i)) % maxc;
        while (x % i == 0) x /= i;
    }
    if (x != 1)
        ans = (ans * Pro(x)) % maxc;
    cout << ans;
    return 0;
}
