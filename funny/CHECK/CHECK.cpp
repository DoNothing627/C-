#include <bits/stdc++.h>
using namespace std;
// ten chuong trinh
const string NAME = "vuongcan";
// so test kiem tra
const int NTEST = 100;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        // Code sinh test

        int n= Rand(1, 50);

        inp<< n<< "\n";

        for(int i= 1; i<= n; i++)
        {
            for(int j= 1; j<= n; j++)
                inp<< Rand(0, 1)<< " ";
            inp<< "\n";
        }

        inp.close();
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
