//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 7005
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "1230D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, a[mn], b[mn], c[70];
vector< int> d[70];
priority_queue< ii> pq;
long long res= 0;
bool chek[mn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;

    forr(i, 1, n)
    {
        cin>> a[i];
        forr(j, 0, 59)
            if((a[i]>> j)& 1== 1){
                ++c[j];
                d[j].pb(i);
            }
    }

    forr(i, 0, 59)
    {
        if(!c[i]) continue;
        pq.push(ii(-c[i], i));
        /*cout<< c[i]<< " ";
        cout<< "\n";*/
    }

    forr(i, 1, n)
    {
        cin>> b[i];
        res+= b[i];
    }

    while(1){
       //cout<< -pq.top().x<< "\n";
       if(-pq.top().x!= 1) break;
       int u= pq.top().y;
       pq.pop();
       for(auto v: d[u])
       {
           if(chek[v]) continue;
           chek[v]= 1;
           res-= b[v], --n;
           forr(i, 0, 59)
           {
               if((v>> i)& 1== 1){
                   --c[i];
                   if(c[i]) pq.push(ii(-c[i], i));
               }
           }
       }

    }

    if(n< 2) cout<< 0;
    else cout<< res;

    return 0;
}
