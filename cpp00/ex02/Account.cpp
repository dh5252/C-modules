
#include "Account.hpp"
#include <ctime>
#include <iostream>

void    Account::_displayTimestamp(void)
{
    time_t  ts;
    char    buf[16];

    time(&ts);
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&ts));
    std::cout << "[" << buf << "]";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << "\n";
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";_nbDeposit:" << ":withdrawals:" << _nbWithdrawals << "\n" ;
}

void Account::makeDeposit(int deposit)
{
    _amount += deposit;
    _totalAmount = _totalAmount + deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits" << _nbDeposits << "\n";
}

int Account::checkAmount(void) const
{
    return (_amount >= 0) ;
}

// 함수추가
// https://techdebt.tistory.com/36