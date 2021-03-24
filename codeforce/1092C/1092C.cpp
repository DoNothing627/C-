//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
#define x first
#define y second
#define mn 105
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "1092C"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n= 0, chek[mn], mm[mn];
string s[mn];
vector< string> p[mn];


void lm()
{
    if(n== 2){
        cout<< "PS";
        return;
    }
    string st= p[n- 1][0], ts= p[n- 1][1];
    string ss= st.substr(1, n- 2), sx= ts.substr(0, n- 2);
    string ss1= st.substr(0, n- 1), sx1= ts.substr(1, n- 2);
    string res;

    if(ss== sx) res= st[0]+ ts;
    else res= ts[0]+ st;

    int c= 0, d= 0;
    vector< ii> v;

    forr(i, 1, 2* n- 2)
    {
        string k= s[i];
        int k1= k.size();
        if(k== res.substr(0, k1)&& k== res.substr(n- k1, k1))
        {
            v.pb(ii(i, k1));
            continue;
        }
        if(k== res.substr(0, k1))
        {
            ++c;
            mm[k1]= 1;
            chek[i]= 1;
        }
        else{
            mm[k1]= 2;
            ++d;
            chek[i]= 2;
        }
    }

    forr(i, 0, v.size()- 1)
    {
        if(!mm[v[i].y])
        {
            chek[v[i].x]= 1;
            mm[v[i].y]= 1;
            continue;
        }
        if(mm[v[i].y]== 2)
        {
            res[v[i].x]= 1;
            mm[v[i].y]= 1;
            continue;
        }
        chek[v[i].x]= 2;
        mm[v[i].y]= 2;
    }

    forr(i, 1, 2* n- 2)
    {
        if(chek[i]== 1) cout<< "P";
        else cout<< "S";
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, 2* n- 2)
    {
        cin>> s[i];
        p[s[i].size()].pb(s[i]);
    }

    lm();
    return 0;
}
