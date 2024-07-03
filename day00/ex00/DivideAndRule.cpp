#include <iostream>
#include <vector>

struct Account
{
	static int next_id;
	private :
		int id;
		int value;

	public :
	Account() :
		id(++next_id),
		value(0)
	{
	
	}

	friend struct Bank;

	void setValue(int value)
	{
		this.value += value;
	}

	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
	{
		p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
		return (p_os);
	}
};

int Account::next_id = 0;

struct Bank
{
	int liquidity;
	std::unordered_map<int , Account *> clientAccounts;

	Bank() :
		liquidity(0)
	{

	}

	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
	{
		p_os << "Bank informations : " << std::endl;
		p_os << "Liquidity : " << p_bank.liquidity << std::endl;
		for (std::unordered_map<int, Account *>::const_iterator it = p_bank.clientAccounts.begin() ; it != p_bank.clientAccounts.end(); ++it)
        	p_os << **it << std::endl;
		return (p_os);
	}
};


int main()
{
	Account accountA = Account();
	accountA.id = 0;
	accountA.value = 100;

	Account accountB = Account();
	accountB.id = 1;
	accountB.value = 100;

	Bank bank = Bank();
	bank.liquidity = 999;
	bank.clientAccounts.push_back(&accountA);
	bank.clientAccounts.push_back(&accountB);

	bank.liquidity -= 200;
	accountA.value += 400;

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
