#include "../includes/Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout <<
		"index:" << _accountIndex <<
		";amount:" << _amount <<
		";created" << std::endl;
}

Account::~Account( void ) {
	_nbAccounts--;
	_displayTimestamp();
	std::cout <<
		"index:" << _accountIndex <<
		";amount:" << _amount <<
		";closed" << std::endl;
}

int		Account::getNbAccounts( void )			{ return _nbAccounts; }
int		Account::getTotalAmount( void )			{ return _totalAmount; }
int		Account::getNbDeposits( void )			{ return _totalNbDeposits; }
int		Account::getNbWithdrawals( void )		{ return _totalNbWithdrawals; }


void	Account::displayAccountsInfos( void )	{
	_displayTimestamp();

	std::cout <<
		"accounts:" << _nbAccounts <<
		";total:" << _totalAmount <<
		";deposits:" << _totalNbDeposits <<
		";withdrawals:" << _totalNbWithdrawals <<
	std::endl;

}

void Account::_displayTimestamp(void) {
		std::time_t now = std::time(0);
		std::tm* tm_struct = std::localtime(&now);
		char buffer[20];
		std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", tm_struct);
		std::cout << buffer;
	}

void	Account::makeDeposit( int deposit )	{
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout <<
		"index:" << _accountIndex <<
		";p_amount:" << _amount - deposit <<
		";deposit:" << deposit <<
		";amount:" << _amount <<
		";nb_deposits:" << _nbDeposits <<
	std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )	{
	_displayTimestamp();
	std::cout <<
		"index:" << _accountIndex;
	if (withdrawal > _amount) {
		std::cout <<
			";p_amount:" << _amount <<
			";withdrawal:refused" <<
		std::endl;
		return false;
	}
	else {
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout <<
			";p_amount:" << _amount  + withdrawal <<
			";withdrawal:" << withdrawal <<
			";amount:" << _amount <<
			";nb_withdrawals:" << _nbWithdrawals <<
		std::endl;
		return true;
	}
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();

	std::cout <<
		"index:" << _accountIndex <<
		";amount:" << _amount <<
		";deposits:" << _nbDeposits <<
		";withdrawals:" << _nbWithdrawals <<
	std::endl;
}

int Account::checkAmount( void ) const { return _amount; }