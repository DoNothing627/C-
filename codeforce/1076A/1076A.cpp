#include <bits/stdc++.h>

using namespace std;
int n;
string s;
bool ok= 0;
int main()
{
    cin>> n>> s;
    for(int i= 0; i< s.size()- 1; i++)
    {
        if(s[i]> s[i+ 1]&& !ok){ok= 1; continue;}
        cout<< s[i];
    }
    if(ok) cout<< s[s.size()- 1];
    return 0;
}
