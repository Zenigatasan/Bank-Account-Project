/*
*Title: Customer.cpp
*Abstract: Customer Class implimintation for project2.
Author: Colin Steele 
ID: 0412
*Date: 11/22/2019
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Customer.h"
using namespace std;

int Customer::getChAccountNum()
{
  return ChNumber;
}

int Customer::getSaAccountNum()
{
  return SaNumber;
}

int Customer::getSSN()
{
  return SSN;
}

string Customer::getFname()
{
  return Fname;
}

string Customer::getLname()
{
  return Lname;
}

double Customer::getChBalance()
{
  return ChBalance;
}

double Customer::getSaBalance()
{
  return SaBalance;
}

bool Customer::setChAccount(int newNumber, double newbalance)
{
  ChNumber = newNumber;
  ChBalance = newbalance;
  return true;
}

bool Customer::setSaAccount(int newNumber, double newbalance)
{
  SaNumber = newNumber;
  SaBalance = newbalance;
  return true;
}

bool Customer::newCustomer(int newSSN, string newFname, string newLname, int newChNumber, double newChBalance, int newSaNumber, double newSaBalance)
{
    SSN = newSSN;
    Fname = newFname;
    Lname = newLname;

      ChNumber = newChNumber;
      if(newChBalance < 0.00)
      {
        cout << "Error: Negative balance is not acceptable." << endl;
        return false;
      }
      else
      {
        ChBalance  = newChBalance;
      }
      SaNumber = newSaNumber;
      if(newSaBalance < 0.00)
      {
        cout << "Error: Negative balance is not acceptable." << endl;
        return false;
      }
      else
      {
        SaBalance  = newSaBalance;
      }
    
    return true;
}



bool Customer::deposit(double amount, int type)
{
    if (amount < 0.0) 
    {
        cout << "Error: No negative amount to tranfer." << endl;
        return false;
    }
    else if(type == 1)
    {
        ChBalance += amount;
        return true;
    }
    else if(type == 2)
    {
      SaBalance += amount;
      return true;
    }
    return false;
}


bool Customer::ChWithdrawl(double amount, bool same)
{
    if (same == false && amount + 5 > ChBalance) 
    {
        cout << "Transfer Fail - insufficient amount." << endl;
        return false;
    }
    else if (amount > ChBalance)
    {
      cout << "Transfer Fail - insufficent amount." << endl;
      return false;
    }
    else
    {
        if (same == false)
        {
          ChBalance = ChBalance-5;
        }
        ChBalance = ChBalance-amount;
        return true;
    }
}

bool Customer::SaWithdrawl(double amount, bool same)
{
    if (same == false && amount + 5 > SaBalance) 
    {
        cout << "Transfer Fail - insufficient amount." << endl;
        return false;
    }
    else if (amount > SaBalance)
    {
      cout << "Transfer Fail - insufficent amount." << endl;
      return false;
    }
    else
    {
        if (same == false)
        {
          SaBalance = SaBalance-5;
        }
        SaBalance = SaBalance-amount;
        return true;
    }
}


void Customer::displayCustomerList( )
{
    cout << Fname << " " << Lname << ": " << SSN << " - ";
    if (ChNumber != -1 && SaNumber != -1)
    {
      cout << ChNumber << " ($" << fixed << setprecision(2) << ChBalance << ")," << SaNumber << "($" << fixed << setprecision(2)<< SaBalance << ")" << endl;
    }
    else if (ChNumber != -1)
    {
      cout << ChNumber << " ($" << fixed << setprecision(2) << ChBalance << ")" << endl;
    }
    else
    {
      cout << SaNumber << " ($" << fixed <<  setprecision(2) << SaBalance << ")" << endl;
    }

}

void Customer::displayCustomerByName()
{
    cout << "      Name: " << Fname << " " << Lname << endl;
    cout << "      Account Number: ";
    if (ChNumber > -1 && SaNumber > -1)
    {
      cout << ChNumber << ", " << SaNumber << endl;
      cout << "      Account Type: Checking, Savings\n";
      cout << "     Balance: $" << fixed << setprecision(2) << ChBalance << ", $" << fixed << setprecision(2) << SaBalance << endl;
    }
    else if (ChNumber != -1)
    {
      cout << ChNumber << endl;
      cout << "      Account Type: Checking" << endl;
      cout << "     Balance: $" << fixed << setprecision(2) << ChBalance << endl;
    }
    else
    {
      cout << SaNumber << endl;
      cout << "      Account Type: Savings " << endl;
      cout << "     Balance: $" << fixed << setprecision(2) << SaBalance << endl;
    }
}
void Customer::displayCustomerByNum(int account)
  {
    cout << "      Name: " << Fname << " " << Lname << endl;
    cout << "      Account Number: ";
    if (ChNumber == account)
    {
      cout << ChNumber << endl;
      cout << "      Account Type: Checking" << endl;
      cout << "     Balance: $" << fixed << setprecision(2) << ChBalance << endl;
    }
    else
    {
      cout << SaNumber << endl;
      cout << "      Account Type: Savings " << endl;
      cout << "     Balance: $" << fixed << setprecision(2) << SaBalance << endl;
    }
    }

