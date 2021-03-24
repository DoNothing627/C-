//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 2000005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "QSEQ"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

int a, x, y, n, m, q, d[mn], res[mn], step, u, c= 0, MOD;
string s;

bool chek()
{
    /*int k= log(c);
    if(n> k) return 0;*/
    if(n> 8) return 0;
    string t;
    int val= c;
    while(val)
    {
        int r= val% 10;
        t= (char)(r+ '0')+ t;
        val/= 10;
    }
    if(n> t.size()) return 0;
    //MOD= 0;
    if(n< t.size()){
        forr(i, 1, n) MOD= MOD* 10+ (s[i]- '0');
        return 1;
    }
    forr(i, 1, n)
    {
        MOD= MOD* 10+ (s[i]- '0');
        if(t[i]> s[i]) return 0;
    }
    return 1;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);
    //freopen(DoNothing".inp", "w", stdout);

    cin>> a>> x>> y>> m>> q;

    forr(i, 0, m) d[i]= -1;

    res[0]= a;
    while(d[a]== -1){
        d[a]= c;
        a= (long long)(1ll* a* x+ y)% m;
        ++c;
        res[c]= a;
    }

    int step= c- d[a];


    //cout<< c<< " "<< d[a]<< "\n";
    c= d[a];

    //cout<< step<< "\n";

    while(q--){
        cin>> s;
        /*if(u<= c) cout<< res[u]<< "\n";
        else cout<< res[c+ ((u- c)% step)]<< "\n";*/
        n= s.size();
        s= " "+ s;
        //if(n> c){
        MOD= 0;
        if(chek()) cout<< res[MOD]<< " ";
        else{
            forr(i, 1, n)
                MOD= (MOD* 10+ (int)(s[i]- '0'))% step;
            int r= c% step;
            MOD= MOD- r;
            if(MOD< 0) MOD+= step;
            cout<< res[c+ MOD]<< " ";
        }
    }

    return 0;
}
