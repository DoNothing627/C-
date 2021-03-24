//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 1000005
#define pb push_back
#define oo 100000000007
//#define int long long
#define DoNothing "1354D"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

/*set< int> s;
set< int> :: iterator c;
int type, u;*/
int n, q, I[mn], c;

void up(int x, int val)
{
    while(x<= n){
        I[x]+= val;
        x+= (x& (- x));
    }
}

int get(int x)
{
    int ans= 0;
    while(x> 0){
        ans+= I[x];
        x-= (x& (- x));
    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n>> q;
    forr(i, 1, n){
        cin>> c;
        //s.insert(c);
        up(c, 1);
    }

    forr(i, 1, q){
        cin>> c;
        if(1<= c&& c<= n){
            //s.insert(c);
            up(c, 1);
        }
        if(c< 0){
            c= -c;
            int l= 0, r= n+ 1;
            while(r- l> 1){
                int m= (r+ l)/ 2;
                if(get(m)< c) l= m;
                else r= m;
            }
            if(r) up(r, -1);
        }
    }

    forr(i, 1, n)
        if(get(i)){
            cout<< i;
            return 0;
        }

    cout<< 0;

    return 0;
}
