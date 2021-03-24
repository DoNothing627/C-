#include <bits/stdc++.h>

using namespace std;

struct BankAccount
{
	int accountNumber;
	int balance;
};

int main()
{
	BankAccount *pAccount = new BankAccount;
    *pAccount = { 12345, 50 };

	std::cout << pAccount->accountNumber << " " << pAccount->balance << std::endl;

	return 0;
}
