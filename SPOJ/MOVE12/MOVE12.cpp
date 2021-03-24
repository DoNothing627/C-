//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 10005
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "MOVE12"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;


int n, c[mn], t[mn];
ii p[mn];

bool chek()
{
    priority_queue< int> q;
    int j= 1;
    forr(i, 1, n)
    {
        while(j<= n&& p[j].x== i){
            q.push(-p[j].y);
            ++j;
        }
        if(!q.size()) return 0;
        if(-q.top()< i) return 0;
        q.pop();
    }

    return 1;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
        cin>> c[i]>> t[i];

    int l= -1, r= 1e8;

    while(r- l> 1)
    {
        int m= (l+ r)/ 2;
        forr(i, 1, n)
        {
            p[i].x= max(1, c[i]- m/ t[i]);
            p[i].y= min(n, c[i]+ m/ t[i]);
        }
        sort(p+ 1, p+ n+ 1);
        if(chek()) r= m;
        else l= m;
    }

    cout<< r;

    return 0;
}
