#include <iostream>
#include<map>
#include<utility>
#include <stdexcept>

struct Account
{
	private :
	static size_t next_id;
		size_t id;
		float value;

	Account(float value) :
		id(++next_id),
		value(value)
	{
	
	}

	friend struct Bank;

	size_t getValue() const
	{
		return this->value;
	}
	
	int getId() const 
	{
		return this->id;
	}

	friend struct Bank;
	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
	{
		p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
		return (p_os);
	}
};

size_t Account::next_id = 0;

struct Bank
{
	private :
		float liquidity;
		std::map<size_t, Account *> clientAccounts;

	public : 
	Bank() :
		liquidity(0)
	{

	}

	void setLiquidity(float liquidity)
	{
		if (liquidity < 0)
			throw std::runtime_error("BANK ONLY TAKE LIQUIDITY , NOT THE OTHER WAY AROUND ");
		this->liquidity += liquidity;
	}

	size_t addAccount(int value)
	{
		Account * newAcc = new Account(value);
		this->clientAccounts.insert(std::make_pair(newAcc->getId(), newAcc));
		return (newAcc->getId());
	}

	void inflowToId(float value, size_t accId)
	{
		std::map<size_t, Account *>::iterator it = clientAccounts.find(accId);
		if(it == clientAccounts.end())
				throw std::runtime_error("ERROR ACCOUNT ID DOESN'T EXIST !!");

		if (value > 0)
		{
			float bankFee = (5 * value) / 100;
			liquidity += bankFee;			
			it->second->value += value - bankFee;
		}
		else
			it->second->value += value; 
	}

	void giveLoan(float loan, size_t accId)
	{
		if (loan > liquidity)
			throw std::runtime_error("LOAN AMOUNT EXCEED THE BANK LIQUIDITY LIMIT , GHAYARHA");
		std::map<size_t, Account *>::iterator it = clientAccounts.find(accId);
		if(it == clientAccounts.end())
			throw std::runtime_error("ERROR ACCOUNT ID DOESN'T EXIST !!");
		it->second->value += loan;
		this->liquidity -= loan;
	}

	void deleteAccount(size_t accId)
	{
		if (clientAccounts.erase(accId))
		{
			std::cout << "ACCOUNT WITH ID " << accId << "HAS BEEN DELETED :)" << std::endl;;
			return;
		}
		throw std::runtime_error("ERROR ACCOUNT ID DOESN'T EXIST !!");
		
	}

	Account &operator[](size_t accId)
	{
		std::map<size_t, Account *>::iterator it = clientAccounts.find(accId);
		if(it == clientAccounts.end())
			throw std::runtime_error("ERROR ACCOUNT ID DOESN'T EXIST !!");
		return *(it->second);
	}

	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
	{
		p_os << "Bank informations : " << std::endl;
		p_os << "Liquidity : " << p_bank.liquidity << std::endl;
		p_os << "ACCOUNTS : " << std::endl;
		for (std::map<size_t, Account *>::const_iterator	 it = p_bank.clientAccounts.begin(); it != p_bank.clientAccounts.end(); ++it)
        	p_os << *(it->second) << std::endl;
		return (p_os);
	}
};


int main()
{
	try
	{
		Bank bank = Bank();
		bank.setLiquidity(999);
		bank.addAccount(500);
		bank.addAccount(100);
		bank.deleteAccount(2);
		std::cout << bank[1] << std::endl;
		bank.giveLoan(900, 1);
		bank.setLiquidity(0);
		bank.inflowToId(0, 1);

		std::cout << bank << std::endl;		
		}
		catch(const std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	return (0);
}
