#ifndef FUND_H_
#define FUND_H_
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

class Fund
{
public:
    Fund();
    ~Fund();

    // Getter-Setter
    vector<int> Arr();

    // Actions
    int Value(int num);
    void Add(int num, int amt);
    void Subtract(int num, int amt);
    void Set(int num, int amt);
    void AddHistory(int num, string trans);
    void Print(int num); 
    string GetName(int num);

    // Overloaded operator
    friend ostream & operator<<(ostream &os, Fund &acct);

private:
    vector<int> funds_ = vector<int>(8, 0);

    // Vector of size 8 that holds 8 string vectors for the history of each fund
    vector<vector<string>> history_ = vector<vector<string>>(8);

    int num_ = 0;
    int amt_ = 0;
};
#endif