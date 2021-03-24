//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 250005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "NPR"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)

using namespace std;

string s, S[2][mn], f[mn][2];
int n[2], type= 1, val[mn];

struct trie
{
    int COUNT;
    vector<int> v;
    string save[2];
    trie *t[26];
}T, R;

void init()
{
    while(getline(cin, s)){
         if(s== ""){
            --type;
            continue;
         }
         S[type][++n[type]]= s;
         //cout<< S[type][n[type]]<< "\n";
    }

    sort(S[1]+ 1, S[1]+ n[1]+ 1);
}

void deSign()
{
    forr(i, 1, n[1])
    {
         trie *c= &T;
         for(int j= S[1][i].size()- 1; j>= 0; j--)
         {
             //cout<< S[1][i][j]<< " ";
             int x= S[1][i][j]- 'a';
             if(c-> t[x]== NULL) c-> t[x]= new trie();
             c= c-> t[x];
             ++ c-> COUNT;
         }
         //cout<< "\n";
    }

    forr(i, 1, n[0])
    {
        trie *c= &T;
        int l= lower_bound(S[1]+ 1, S[1]+ n[1]+ 1, S[0][i])- S[1];
        int r= upper_bound(S[1]+ 1, S[1]+ n[1]+ 1, S[0][i])- S[1];
        for(int j= S[0][i].size()- 1; j>= 0; j--)
        {
            int x= S[0][i][j]- 'a';
            /*if(c-> t[x]== NULL){
                val[i]= S[0][i].size()- j;
                break;
            }
            else c= c-> t[x];*/
            c= c-> t[x];
            if(c-> COUNT== r- l){
                val[i]= S[0][i].size()- j- 1;
                break;
            }
        }
        if(!val[i])
            val[i]= S[0][i].size();
    }

}

void doIt()
{
    forr(i, 1, n[0])
    {
        trie *c= &R;
        forr(j, 1, val[i])
        {
            int x= S[0][i][S[0][i].size()- j]- 'a';
            if(c-> t[x]== NULL) c-> t[x]= new trie();
            c= c-> t[x];
        }
        c-> v.pb(i);
    }

    forr(i, 1, n[1])
    {
        trie *c= &R;
        for(int j= S[1][i].size()- 1; j>= 0; j--)
        {
            int x= S[1][i][j]- 'a';
            if(c-> t[x]== NULL) break;
            else c= c-> t[x];
            if(c-> save[0]== "") c-> save[0]= S[1][i];
            else{
                if(c-> save[1]== "") c-> save[1]= S[1][i];
                else{
                    if(S[1][i]< c-> save[0]){
                        c-> save[1]= c-> save[0];
                        c-> save[0]= S[1][i];
                    }
                    else if(S[1][i]< c-> save[1])
                        c-> save[1]= S[1][i];
                }
           }
        }
    }

}

void dfs(trie *r)
{
    trie *c;
    forr(i, 0, 25)
        if(r-> t[i]!= NULL){
            c= r-> t[i];
            for(int j: c-> v){
                f[j][0]= c-> save[0];
                f[j][1]= c-> save[1];
            }
            dfs(c);
        }
}

void reSult()
{
    dfs(&R);

    forr(i, 1, n[0])
        if(S[0][i]== f[i][0]) cout<< f[i][1]<< "\n";
        else cout<< f[i][0]<< "\n";
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    //freopen(DoNothing".out", "w", stdout);

    init();
    deSign();
    doIt();
    reSult();

    return 0;
}
