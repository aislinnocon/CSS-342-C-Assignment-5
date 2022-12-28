#include "transaction.h"

// Default Constructor
Transaction::Transaction()
{
}

// Constructor for Open() - opens an account
Transaction::Transaction(string type, int accountID, string lastName, string firstName) : type_(type), accountID_(accountID),
    lastName_(lastName), firstName_(firstName)
{
}

// Constructor for Transfer() - transfers money between funds of one client or two clients
Transaction::Transaction(string type, int accountID, int fundNumber, int otherAccountID, int otherFundNumber, int amount) 
    : type_(type), accountID_(accountID), fundNumber_(fundNumber), otherAccountID_(otherAccountID), otherFundNumber_(otherFundNumber),
    amount_(amount)
{
}

// Constructor for Deposit() & Withdraw() - withdraws and/or deposits money into and/or out of funds
Transaction::Transaction(string type, int accountID, int fundNumber, int amount) 
    : type_(type), accountID_(accountID), fundNumber_(fundNumber), amount_(amount)
{
}

// Constructor for AccountHistory() - prints out history for an account
Transaction::Transaction(string type, int accountID) : type_(type), accountID_(accountID)
{
}

// Constructor for FundHistory() - prints out history for a fund
Transaction::Transaction(string type, int accountID, int fundNumber) 
    : type_(type), accountID_(accountID), fundNumber_(fundNumber)
{
}

// Destructor
Transaction::~Transaction()
{
}

// Returns type of transaction
string Transaction::getType() const
{
    return type_; 
}

// Returns last name of client
string Transaction::getLastName() const
{
    return lastName_;
}
    
// Returns first name of client
string Transaction::getFirstName() const
{
    return firstName_;
}

// Returns account ID
int Transaction::getAccountID() const
{
    return accountID_;
}

// Returns second account ID
int Transaction::getOtherAccountID() const
{
    return otherAccountID_;
}
    
// Returns which fund is called upon
int Transaction::getFundNumber() const
{
    return fundNumber_;
}

// Returns second fund called upon
int Transaction::getOtherFundNumber() const
{
    return otherFundNumber_;
}

// Returns amount 
int Transaction::getAmount() const
{
    return amount_; 
}    












