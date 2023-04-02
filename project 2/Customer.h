/*
*Title: Customer.h
*Abstract: Header file for Customer that is for project2.
Author: Colin Steele 
ID: 0412
*Date: 11/22/2019
*/

// A sample interface file for Account class.
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;

class Customer
{
public:
    bool ChWithdrawl(double amount, bool same);
    bool SaWithdrawl(double amount, bool same);
    bool deposit(double amount, int type);
    void displayCustomerByName();
    void displayCustomerByNum(int account);
    void displayCustomerList( );
    bool newCustomer(int newSSN, string newFname, string newLname, int newChNumber, double newChBalance, int newSaNumber, double newSaBalance);
    int getChAccountNum();
    double getChBalance();
    int getSaAccountNum();
    double getSaBalance();
    int getSSN();
    string getFname();
    string getLname();
    bool setChAccount(int newNumber, double newbalance);
    bool setSaAccount(int newNumber, double newbalance);

private:
    int SSN;
    string Fname;     
    string Lname;
    int ChNumber;     
    int SaNumber;
    double ChBalance;
    double SaBalance;
};
#endif