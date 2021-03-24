//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "VODIVIDE"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, res;
priority_queue< ii> q;
bool c[mn];
stack< int> s;

struct data
{
    int x, y, z;
}a[mn];

bool cmp(data A, data B)
{
    return A.x< B.x;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
        cin>> a[i].x;
    forr(i, 1, n)
        cin>> a[i].y;
    forr(i, 1, n)
        a[i].z= i;

    sort(a+ 1, a+ n+ 1, cmp);

    forr(i, 1, n)
    {
        q.push(ii(a[i].y, i));
        if(i% 2){
            res+= q.top().x;
            c[q.top().y]= 1;
            q.pop();
        }
    }

    cout<< res<< "\n";

    forr(i, 1, n)
    {
        if(c[i]) s.push(a[i].z);
        else{
            cout<< a[i].z<< " "<< s.top()<< "\n";
            s.pop();
        }
    }

    return 0;
}
