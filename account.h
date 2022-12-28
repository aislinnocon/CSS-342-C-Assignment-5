#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "transaction.h"
#include "fund.h"
using namespace std;

class Account
{
public:
    Account(); 
    Account(string firstName, string lastName, int id);
    ~Account();

    // action
    void Deposit(int fund_id, int amt);
    void Withdraw(int fund_id, int amt);
    void SpecialCase(string type, int fund_id, int amt); 

    // getter-setter
    string getFirstName() const;
    string getLastName() const;
    int getID() const; 

    /* Takes money from the called upon account from the fund # that correlates 
    to fund_two. The money is transferred into the other Account into the fund # 
    that correlates to fund_one.
    ex. current.AccountTransfer(other, 0, 1, 100) -> 100 will be taken from fund #1 from Account 
    current and transferred to Account other in fund #0  
    */ 
    void AccountTransfer(Account &other, int fund_one, int fund_two, int amt);
    // Transfers money from fund_two into fund_one
    void FundTransfer(int fund_one, int fund_two, int amt); 

    void PrintAccountHistory();
    void AddFundHistory(string type, int id, int fundNumber, int amount);
    void AddFundHistoryTransfer(string type, int id, int fundNumber, int otherID, int otherFundNumber, int amount);
    void PrintFundHistory(int fundNumber);

    // Overloaded operator
    friend ostream & operator<<(ostream &os, Account &acct);

private:
    Fund funds_; 
    string firstName_;
    string lastName_; 
    int id_; 
};
#endif