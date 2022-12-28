#include "account.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Default Constructor
Account::Account()
{
}

// Creates new account with necessary information
Account::Account(string firstName, string lastName, int id) : id_(id), firstName_(firstName), lastName_(lastName)
{
}

// Destructor
Account::~Account()
{
}

// Returns account owner's first name
string Account::getFirstName() const
{
    return firstName_;
}

// Returns account owner's last name
string Account::getLastName() const
{
    return lastName_; 
}

// Returns account ID
int Account::getID() const
{
	return id_; 
}

// Deposits amount into a particular fund
void Account::Deposit(int fund_id, int amt)
{
    funds_.Add(fund_id, amt);
}

// Withdraws specific amount from a particular fund
void Account::Withdraw(int fund_id, int amt) 
{
    if (funds_.Value(fund_id) >= amt)
    {
        funds_.Subtract(fund_id, amt);
        AddFundHistory("W", getID(), fund_id, amt); 
    } 
    else 
    {
        if (fund_id == 0 || fund_id == 1 || fund_id == 2 || fund_id == 3)
        {
            SpecialCase("W", fund_id, amt);
        }
        else
        {
            AddFundHistory("W", getID(), fund_id, amt);
            cerr << "ERROR: Not enough funds to withdraw " << amt << " from " << getFirstName() <<
                " " << getLastName() << " " << funds_.GetName(fund_id) << endl; 
        }
    }
}

// Aids withdrawing or transferring funds for special cases
void Account::SpecialCase(string type, int fund_id, int amt)
{
    string helper;
    if (type == "W")
    {
        helper = "withdraw";
    }
    if (type == "T")
    {
        helper = "transfer";
    }
    if (fund_id == 0)
    {
        if (funds_.Value(1) + funds_.Value(0) >= amt)
        {
            if (type == "W")
            {
                AddFundHistory(type, getID(), 0, funds_.Value(0));
                AddFundHistory(type, getID(), 1, (amt - funds_.Value(0))); 
            }
            funds_.Subtract(1, (amt - funds_.Value(0)));
            funds_.Set(0,0); 
        }
        else 
        {
            cerr << "ERROR: Not enough funds to " << helper << " " << amt << " from " << 
                getFirstName() << " " << getLastName() << " " << funds_.GetName(fund_id) << endl;   
        }
    }
    if (fund_id == 1)
    {
        if (funds_.Value(1) + funds_.Value(0) >= amt)
        {
            if (type == "W")
            {
                AddFundHistory(type, getID(), 1, funds_.Value(1));
                AddFundHistory(type, getID(), 0, (amt - funds_.Value(1)));             
            }
            funds_.Subtract(0, (amt - funds_.Value(1)));
            funds_.Set(1, 0);
        }
        else 
        {
            cerr << "ERROR: Not enough funds to " << helper << " " << amt << " from " << 
                getFirstName() << " " << getLastName() << " " << funds_.GetName(fund_id) << endl;    
        }
    }
    if (fund_id == 2)
    {
        if (funds_.Value(2) + funds_.Value(3) >= amt)
        {
            if (type == "W")
            {
                AddFundHistory(type, getID(), 2, funds_.Value(2));
                AddFundHistory(type, getID(), 3, (amt - funds_.Value(3)));  
            }
            funds_.Subtract(3, (amt - funds_.Value(2)));
            funds_.Set(2, 0);
        }
        else
        {
            cerr << "ERROR: Not enough funds to " << helper << " " << amt << " from " << 
                getFirstName() << " " << getLastName() << " " << funds_.GetName(fund_id) << endl;  
        }
    }
    if (fund_id == 3)
    {
        if (funds_.Value(3) + funds_.Value(2) >= amt)
        {
            if (type == "W")
            {
                AddFundHistory(type, getID(), 3, funds_.Value(3));
                AddFundHistory(type, getID(), 2, (amt - funds_.Value(2)));
            }
            funds_.Subtract(2, (amt - funds_.Value(3)));
            funds_.Set(3, 0);
        }
        else
        {
            cerr << "ERROR: Not enough funds to " << helper << " " << amt << " from " << 
                getFirstName() << " " << getLastName() << " " << funds_.GetName(fund_id) << endl;  
        }
    }
}

// Transfer funds from rhs account into lhs account 
void Account::AccountTransfer(Account &other, int fund_one, int fund_two, int amt)
{
    if (this->funds_.Value(fund_two) >= amt)
    {
        other.funds_.Add(fund_one, amt);
        this->funds_.Subtract(fund_two, amt);
        AddFundHistoryTransfer("T", this->getID(), fund_one, other.getID(), fund_two, amt);        
    }
    else 
    {
        if (fund_one == 0 || fund_one == 1 || fund_one == 2 || fund_one == 3)
        {
            
            int check = this->funds_.Value(fund_one);
            SpecialCase("T", fund_one, amt);
            if (check - this->funds_.Value(fund_one) != 0)
            { 
                other.funds_.Add(fund_two, amt); 
                AddFundHistoryTransfer("T", this->getID(), fund_one, other.getID(), fund_two, amt);    
            }
        }
        else
        {
            cerr << "ERROR: Not enough funds to transfer " << amt << " from " << this->getFirstName() << " " 
                << this->getLastName() << " " << this->funds_.GetName(fund_one) << " to " << other.getFirstName() <<
                " " << other.getLastName() << " " << other.funds_.GetName(fund_two) << endl;  
        }
    }
}

// Transfer funds for the same client with amount being taken from fund two 
// and added into fund one
void Account::FundTransfer(int fund_one, int fund_two, int amt)
{
    if (funds_.Value(fund_two) < amt)
    {
        if (fund_two == 0 || fund_two == 1 || fund_two == 2 || fund_two == 3)
        {
            int check = funds_.Value(fund_two); 
            SpecialCase("T", fund_two, amt);
            if (check - funds_.Value(fund_two) != 0)
            {  
                funds_.Add(fund_one, amt); 
                AddFundHistoryTransfer("T", getID(), fund_two, getID(), fund_one, amt);
            }
        }
        else
        {
            cerr << "ERROR: Not enough funds to transfer " << amt << " from " << getFirstName() <<
                " " << getLastName() << " " << funds_.GetName(fund_one) << " to " << funds_.GetName(fund_two) << endl;
        } 
    } 
    else
    {
        AddFundHistoryTransfer("T", getID(), fund_two, getID(), fund_one, amt);
        funds_.Subtract(fund_two, amt); 
        funds_.Add(fund_one, amt);
    }
}

// Prints out an account's history
void Account::PrintAccountHistory()
{
    cout << "Transaction History for " << firstName_ << " " << lastName_ << " by fund." << endl; 
    for(int i = 0; i < 8; i++)
    {
        funds_.Print(i); 
    }
    cout << endl; 
}

// Adds transactions to a fund's history
void Account::AddFundHistory(string type, int id, int fundNumber, int amount)
{ 
    string trans = type + " " + to_string(id) + " " + to_string(fundNumber) + " " + to_string(amount); 
    funds_.AddHistory(fundNumber, trans);
}

// Special case for adding transfers to the history 
void Account::AddFundHistoryTransfer(string type, int id, int fundNumber, int otherID, int otherFundNumber, int amount)
{
    string trans = type + " " + to_string(id) + " " + to_string(fundNumber) + " " + to_string(otherID) + " " +
        to_string(otherFundNumber) + " " + to_string(amount);
    if (fundNumber == otherFundNumber)
    {
       funds_.AddHistory(fundNumber, trans); 
    }
    else
    {
        funds_.AddHistory(fundNumber, trans);
        funds_.AddHistory(otherFundNumber, trans);  
    }
}

// Print out fund's history
void Account::PrintFundHistory(int fundNumber)
{
    cout << "Transaction History for " << getFirstName() << " " << getLastName() << " "; 
    funds_.Print(fundNumber); 
}


// Prints out paths created and number of paths -- used for testing
ostream & operator<<(ostream &os, Account &acct)
{
    cout << acct.getFirstName() << " " << acct.getLastName() << " Account ID: " << acct.getID() << endl;
    cout << acct.funds_; 
	return os;
} 


