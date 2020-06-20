#include <thread>
#include <future>
#include <mutex>
#include <iostream>
#include <exception>
#include <vector>

using namespace std;

class Account
{
private:
	mutable recursive_mutex _mutex;
	int _balance;
public:
	Account() : _balance(0) {}
	void deposit(int sum)
	{
		lock_guard<recursive_mutex> lck(_mutex);
		_balance += sum;
	}
	int balance() const
	{
		lock_guard<recursive_mutex> lck(_mutex);
		return _balance;
	}
	recursive_mutex & getMutex() { return _mutex; }
};

class Bank
{
	Account _accts[2];
	int _minBalance;
public:
	Bank(int minBalance) : _minBalance(minBalance)
	{
		_accts[0].deposit(minBalance);
	}
	void transfer(int from, int to, int sum)
	{
		lock(_accts[from].getMutex(), _accts[to].getMutex());
		lock_guard<recursive_mutex> lck1(_accts[from].getMutex(), adopt_lock);
		lock_guard<recursive_mutex> lck2(_accts[to].getMutex(), adopt_lock);
		if (_accts[from].balance() >= sum)
		{
			_accts[from].deposit(-sum);
			_accts[to].deposit(sum);
		}
	}
	void assertPositive() const
	{
		if (_accts[0].balance() < 0 || _accts[1].balance() < 0)
			throw "Negative balance!";
	}
	void assertSolvent() const
	{
		if (_accts[0].balance() + _accts[1].balance() < _minBalance)
			throw "Need bailout!";
	}

	int getAccount(int accountNumber)
	{
		return _accts[accountNumber].balance();
	}
};

future<void> trans(Bank& bank, int from, int to, int sum)
{
	return async(launch::async, [&](int from, int to, int sum)
		{
			bank.assertPositive();
			bank.transfer(from, to, sum);
			bank.assertSolvent();
		}, from, to, sum);
}

future<void> depositor(Account& acct, int sum)
{
	return async([&](int sum)
		{
			acct.deposit(sum);
		}, sum);
}

future<void> balancer(Account const & acct)
{
	return async([&]()
		{
			cout << acct.balance() << endl;
		});
}

void test()
{
	Account acct;
	vector<future<void>> futures;
	futures.emplace_back(depositor(acct, 10));
	futures.emplace_back(depositor(acct, 20));
	futures.emplace_back(balancer(acct));
	futures.emplace_back(depositor(acct, -10));
	futures.emplace_back(depositor(acct, -10));
	futures.emplace_back(depositor(acct, -10));
	for (auto& fut : futures)
		fut.wait();
	cout << "Final balance " << acct.balance() << endl;
}

void testBank()
{
	Bank bank(10);
	vector<future<void>> futures;
	for (int i = 0; i < 5; ++i)
	{
		futures.emplace_back(trans(bank, 0, 1, 10));
		futures.emplace_back(trans(bank, 1, 0, 10));
		cout << "bank[" << i << "]:acct[0]=" << bank.getAccount(0) << " acct[1]=" << bank.getAccount(1) << endl;
	}
	for (auto & fut : futures)
		fut.get();

}


int main()
{
	try
	{
		//test();
		testBank();
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
