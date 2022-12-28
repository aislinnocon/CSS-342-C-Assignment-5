#include "fund.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Default Constructor
Fund::Fund(): num_(0), amt_(0)
{
}

// Destructor
Fund::~Fund()
{
}

// Returns vector funds value
vector<int> Fund::Arr()
{
    return funds_;  
}

// Returns value of a particular fund
int Fund::Value(int num)
{
    return funds_[num];
}

// Adds value to a particular fund
void Fund::Add(int num, int amt)
{
    funds_[num] = funds_[num] + amt; 
}

// Subtracts value from a particular fund
void Fund::Subtract(int num, int amt)
{
    funds_[num] = funds_[num] - amt; 
}

// Sets the value of a particular fund
void Fund::Set(int num, int amt)
{
    funds_[num] = amt; 
}

// Adds to the history vector of a particular fund
void Fund::AddHistory(int num, string trans)
{
    history_[num].push_back(trans);

}

// Gets name for an individual fund
string Fund::GetName(int num)
{
    string ans;
    if (num == 0)
    {
        ans = "Money Market";
    }
    if (num == 1)
    {
        ans = "Prime Money Market";
    }
    if (num == 2)
    {
        ans = "Long-Term Bond";
    }
    if (num == 3)
    {
        ans = "Short-Term Bond";
    }
    if (num == 4)
    {
        ans = "500 Index Fund";
    }
    if (num == 5)
    {
        ans = "Capital Value Fund";
    }
    if (num == 6)
    {
        ans = "Growth Equity Fund";
    }
    if (num == 7)
    {
        ans = "Growth Index Fund";
    }
    return ans; 
}

// Prints out history of a particular fund
void Fund::Print(int num)
{
    if (history_[num].size() != 0)
    {
        cout << GetName(num) << ": $" << Value(num) << endl;
    }
    for(int i = 0; i < history_[num].size(); i++)
    {
        cout << "\t" << history_[num][i] << endl; 
    }
}

// Overloaded operator
ostream & operator<<(ostream &os, Fund &fund)
{
    for (int i = 0; i < 8; i ++)
    {
        cout << "\t" << fund.GetName(i) << ": $" << fund.Value(i) << endl;;
    }
	return os;
}




