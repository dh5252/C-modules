/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:19:16 by cahn              #+#    #+#             */
/*   Updated: 2023/11/04 17:19:24 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts= 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


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

Account::~Account()
{
    _nbAccounts--;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -=_nbWithdrawals;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" <<  _amount << ";closed" << "\n";
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
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposit:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n" ;
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
    return (_amount >= 0);
}

bool Account::makeWithdrawal(int withdrawal)
{
    _amount -= withdrawal;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount + withdrawal;
    if (!checkAmount())
    {
        _amount += withdrawal;
        std::cout << ";withdrawal:refused\n";
        return false;
    }
    else
    {
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbDeposits++;
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawal:" << _nbWithdrawals << "\n";
        return true;
    }
}
