#include <bits/stdc++.h>
using namespace std;
// ten chuong trinh
const string NAME = "EFILL";
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

        int n= Rand(3, 10), xa= Rand(1, 10), ya= Rand(1, 10), xb= Rand(1, 10), yb= Rand(1, 10);

        inp<< n<< "\n"<< 0<< " "<< 0<< "\n"<< 1<< " "<< 1<< "\n";

        for(int i= 1; i<= n- 2; i++)

        inp<< Rand(1, 100)<< " "<< Rand(1, 100)<< "\n";

        inp<< 2<< " "<< 2<< "\n"<< 3<< " "<< 3;

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
