//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 100005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "GROW"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int n, m, a[mn], h[mn], I[mn];

void up(int x, int val)
{
    while(x<= n)
    {
        I[x]+= val;
        x+= (x& (- x));
    }
}

int get(int x)
{
    int ans= 0;
    while(x> 0)
    {
        ans+= I[x];
        x-= (x& (- x));
    }
    return ans;
}

int FINDLB(int cost)
{
    int l= 0, r= n+ 1;
    while(r- l> 1){
        int mid= (l+ r)/ 2;
        if(a[mid]+ get(mid)< cost) l= mid;
        else r= mid;
    }
    return r;
}

int FINDUB(int cost)
{
    int l= 0, r= n+ 1;
    while(r- l> 1){
        int mid= (l+ r)/ 2;
        if(a[mid]+ get(mid)> cost) r= mid;
        else l= mid;
    }
    return r;
}

/*void BUFF()
{
    while(m--)
    {
        char type;
        int u, v, c= 0;
        cin>> type>> u>> v;
        if(type== 'F'){
            forr(i, 1, n)
                if(a[i]>= v&& c< u)
                    ++a[i], ++c;
            sort(a+ 1, a+ n+ 1);
        }
        else{
            forr(i, 1, n)
            if(u<= a[i]&& a[i]<= v) ++c;
            cout<< c<< "\n";
        }
    }
}*/

void COW()
{
    while(m--)
    {
        char type;
        int u, v, id, l, r, cost, pos;
        cin>> type>> u>> v;
        if(type== 'F'){
            id= FINDLB(v), up(id, 1);
            pos= min(n, id+ u- 1);
            cost= a[pos]+ get(pos);
            r= FINDUB(cost);
            l= FINDLB(cost);
            if(r!= pos+ 1){
                pos= l+ r- id- u;
                up(l, - 1), up(pos, 1);
            }
            up(r, -1);
        }
        else{
            l= FINDLB(u), r= FINDUB(v);
            cout<< r- l<< "\n";
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> m;
    forr(i, 1, n) cin>> a[i];

    sort(a+ 1, a+ n+ 1);

    //if(n<= 1000) BUFF();
    //else COW();
    COW();

    return 0;
}
