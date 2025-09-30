#include "../includes/Account.hpp"
#include <iostream>


int main( void ) {
	Account::t	accounts(254);
	
	std::cout << "Nombre de compte :	" << accounts.getNbAccounts() << std::endl;
	std::cout << "Montant total :		" << accounts.getTotalAmount() << std::endl;
	std::cout <<  "Nombre de dépots :	" << accounts.getNbDeposits() << std::endl;
	Account::t	acc(500);
	Account::t	a(25);
	std::cout << "Nombre de compte :	" << acc.getNbAccounts() << std::endl;
	std::cout << "Montant total :		" << acc.getTotalAmount() << std::endl;
	std::cout << "Montant du compte a :	" << a.checkAmount() << std::endl;
	a.makeDeposit( 50 );
	std::cout <<  "Nombre de dépots :	" << accounts.getNbDeposits() << std::endl;
	std::cout << "Montant du compte a :	" << a.checkAmount() << std::endl;
	accounts.displayAccountsInfos();
	acc.displayAccountsInfos();
	a.displayAccountsInfos();
}