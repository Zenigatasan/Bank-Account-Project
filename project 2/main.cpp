/*
*Title: Project2.cpp
*Abstract: Makes a list of pointers for a Customer class with constructor, close, info, bank info, transfer, and customer list abilities.
Author: Colin Steele 
ID: 0412
*Date: 11/22/2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Customer.h"
using namespace std;

void menu()
{
  cout << "Select your choice: " << endl;
  cout << "       1. Read Customer data file" << endl;
  cout << "       2. Close an account" << endl;
  cout << "       3. Customer Info" << endl;
  cout << "       4. Bank Info" << endl;
  cout << "       5. Transfer Money" << endl;
  cout << "       6. Customer List" << endl;
  cout << "       7. Exit" << endl;
  return;
}

int main()
{
    Customer *cust_ptr[20];

    for (int i=0; i < 20; i++)
    {
        cust_ptr[i] = nullptr;
    }

    int ssn;
    string Fname;
    string Lname;
    int number;
    int type;
    int temp;
    double balance;
    int option;
    int holder;
    int place;
    int users = 0;
    bool fail;
    string fileName;

    cout << "Welcome to CSUMB Bank" << endl << endl; 

    do 
    {
      menu();
      cin >> option;


      if (option == 1)
      {
        cout << "Enter a file name: ";
        cin >> fileName;
        ifstream f_input(fileName);

        if (f_input.fail())
        {
          cout << "Incorrect file name. Exiting program now.";
          return 0;
        }

        f_input >> holder;
        cout << "Read data...." << endl;

        for (int i=0; i < holder; i++)
        {
          place = 21;
          fail = false;
          f_input >> ssn >> Fname >> Lname >> number >> type >> balance;
          for (int b=0; b < 20; b++)
          {
            if (cust_ptr[b] == nullptr && place > b)
            {
              place = b;
            }
            if (cust_ptr[b] != nullptr)
            {
              if (cust_ptr[b]->getChAccountNum() == number || cust_ptr[b]->getSaAccountNum() == number)
              {
                cout << "Accont creation faild - Account number " << number << " already exists." << endl;
                fail = true;
              }
              else if (cust_ptr[b]->getSSN() == ssn)
              {
                if (cust_ptr[b]->getLname() != Lname && cust_ptr[b]->getFname() != Fname)
                {
                  cout << "Account creation faild - SSN number " << ssn << " already exists." << endl;
                  fail = true;
                }
                else if (cust_ptr[b]->getLname() == Lname && cust_ptr[b]->getFname() == Fname)
                {
                  if (type == 1)
                  {
                    if (cust_ptr[b]->getChAccountNum() == -1)
                      {
                        cust_ptr[b]->setChAccount(number, balance);
                        fail = true;
                      }
                      else
                      {
                        cout << "Account creation faild - " << Fname << " " << Lname << " already has a checking account." << endl;
                        fail = true;
                      }
                    }
                  else if (type == 2)
                  {
                    if (cust_ptr[b]->getSaAccountNum() == -1)
                      {
                        cust_ptr[b]->setSaAccount(number, balance); 
                        fail = true;
                      }
                    else
                      {
                        cout << "Account creation faild - " <<  Fname << " " << Lname << " already has a savings account." << endl;
                        fail = true;
                      }
                    }
                  }
                }
              }
            }
          if (users == 20)
          {
            cout << "Account creation faild - Account list is full.\n";
            fail = true;
          }
          if (fail == false)
          {
            if (type == 1)
            {
              users++;
              cust_ptr[place] = new Customer;
              cust_ptr[place]->newCustomer(ssn, Fname, Lname, number, balance, -1, 0.0);
            }
            
            else if (type == 2)
            {
              users++;
              cust_ptr[place] = new Customer;
              cust_ptr[place]->newCustomer(ssn, Fname, Lname, -1, 0.0, number, balance);
            }
          }
        }
        cout << "Done." << endl; 
        f_input.close();
      }


      if (option == 2)
      {
        fail = true;
        cout << "Enter a account number: ";
        cin >> number;
        for (int i = 0; i < 20; i++)
          {
            if (cust_ptr[i] != nullptr)
            {
              if (cust_ptr[i]->getChAccountNum() == number)
              {
                cout << "Enter a SSN number: ";
                cin >> ssn;
                if (cust_ptr[i]->getSSN() == ssn)
                {
                  cout <<  "Account closed." << endl;
                  cust_ptr[i]->displayCustomerByNum(number);
                  cust_ptr[i]->setChAccount(-1, 0.0);
                  temp = -1;
                  if (cust_ptr[i]->getSaAccountNum() == -1)
                  {
                    cout << "Customer " << cust_ptr[i]->getFname() << " " << cust_ptr[i]->getLname() << " is also deleted." << endl;
                    delete cust_ptr[i];
                    cust_ptr[i] = nullptr;
                  }
                }
                else
                {
                    cout << "Incorrect SSN." << endl;
                    i = 21;
                    temp = -1;
                }
              }
              else if (cust_ptr[i]->getSaAccountNum() == number)
              {
                cout << "Enter a SSN number: ";
                cin >> ssn;
                if (cust_ptr[i]->getSSN() == ssn)
                {
                  cout <<  "Account closed." << endl;
                  cust_ptr[i]->displayCustomerByNum(number);
                  cust_ptr[i]->setSaAccount(-1, 0.0);
                  temp = -1;
                  if (cust_ptr[i]->getChAccountNum() == -1)
                  {
                    cout << "Customer " << cust_ptr[i]->getFname() << " " << cust_ptr[i]->getLname() << " is also deleted." << endl;
                    delete cust_ptr[i];
                    cust_ptr[i] = nullptr;
                  }
                }
                else
                {
                  cout << "Incorrect SSN." << endl;
                  i = 21;
                  temp = -1;
                }
              }
            }
          }
      if (temp != -1) 
        {
          cout << "Incorrect account number." << endl;
        }
      }

      if (option == 3)
      {
        fail = false;
        cout << "SSN(1)/Last Name(2)/Account Number(3): ";
        cin >> temp;
        if (temp == 1)
        {
          cout << "Enter SSN: ";
          cin >> ssn;
          for (int i = 0; i < 20; i++)
          {
            if (cust_ptr[i] != nullptr)
            {
              if (cust_ptr[i]->getSSN() == ssn)
              {
                cust_ptr[i]->displayCustomerByName();
                cout << endl;
                fail = true;
              }
            }
          }
          if (fail == false)
          {
            cout << "No Customer with the SSN." << endl;
          }
        }
        else if (temp == 2)
        {
          cout << "Enter a last name: ";
          cin >> Lname;
          for (int i = 0; i < 20; i++)
          {
            if (cust_ptr[i] != nullptr)
            {
              if (cust_ptr[i]->getLname() == Lname)
              {
                cust_ptr[i]->displayCustomerByName();
                cout << endl;
                fail = true;
              }
            }
          }
          if (fail == false)
          {
            cout << "No Customer with the last with that ssn." << endl;
          }
        }
        else if (temp == 3)
        {
          cout << "Enter account number: ";
          cin >> temp;
          for (int i = 0; i < 20; i++)
          {
            if (cust_ptr[i] != nullptr)
            {
              if (cust_ptr[i]->getChAccountNum() == temp || cust_ptr[i]->getSaAccountNum() == temp)
              {
                cust_ptr[i]->displayCustomerByNum(temp);
                cout << endl;
                fail = true;
              }
            }
          }
          if (fail == false)
          {
            cout << "No Customer with the account number." << endl;
          }
        }
        else 
        {
          cout << "No such option." << endl;
        }
      }


      if (option == 4)
      {
        int* sortArrayCh = new int [20];
        int* sortArraySa = new int[20];
        int* sortArrayC = new int [20];
        double total = 0;
        int nPeople = 0;
        int nChAccount = 0;
        int nSaAccount = 0;

        for (int i = 0; i < 20; i++)
        {
          if (cust_ptr[i]!= nullptr)
          {
            sortArrayC[nPeople] = i;
            if (cust_ptr[i]->getChAccountNum() != -1)
            {
              sortArrayCh[nChAccount] = i;
              for (int c = nChAccount-1; c >= 0; c--)
              {
                if (cust_ptr[(sortArrayCh[c])]->getChAccountNum() > cust_ptr[(sortArrayCh[c+1])]->getChAccountNum())
                {
                  temp = sortArrayCh[c];
                  sortArrayCh[c] = sortArrayCh[c+1];
                  sortArrayCh[c+1] = temp; 
                }
              }
              nChAccount++;
            }
            if (cust_ptr[i]->getSaAccountNum() != -1)
            {
              sortArraySa[nSaAccount] = i;
              for (int c = nSaAccount-1; c >= 0; c--)
              {
                if (cust_ptr[(sortArraySa[c])]->getSaAccountNum() > cust_ptr[(sortArraySa[c+1])]->getSaAccountNum())
                  {
                    temp = sortArraySa[c];
                    sortArraySa[c] = sortArraySa[c+1];
                    sortArraySa[c+1] = temp; 
                  }
              }
              nSaAccount++;
            }
            for (int c = nPeople-1; c > 0; c--)
            if (cust_ptr[(sortArrayC[c])]->getSSN() > cust_ptr[(sortArrayC[c+1])]->getSSN())
                {
                  temp = sortArrayC[c];
                  sortArrayC[c] = sortArrayC[c+1];
                  sortArrayC[c+1] = temp; 
                }
            nPeople++;
          }
        }
        cout << "Number of Accounts: " << (nChAccount + nSaAccount) << endl;
        for (int b = 0; b < nChAccount; b++)
        {
          cout << "       " << cust_ptr[(sortArrayCh[b])]->getChAccountNum() << ": $" << fixed << setprecision(2) << cust_ptr[(sortArrayCh[b])]->getChBalance() << " (checking)\n";
          total = total + cust_ptr[sortArrayCh[b]]->getChBalance();
        }
        for (int d = 0; d < nSaAccount; d++)
        {
          cout << "       " << cust_ptr[sortArraySa[d]]->getSaAccountNum() << ": $" << fixed << setprecision(2) << cust_ptr[sortArraySa[d]]->getSaBalance() << " (Saving)\n";
          total = total + cust_ptr[sortArraySa[d]]->getSaBalance();
        }
        delete[] sortArraySa;
        delete[] sortArrayCh; 
        cout << endl << "Number of Customers: " << nPeople << endl;
        for (int j = 0; j < nPeople; j++)
        {
          cust_ptr[sortArrayC[j]]->displayCustomerList();
        }
        delete[] sortArrayC;
        cout << endl << " Total: $" << fixed << setprecision(2) << total << endl; 
      }


      if (option == 5)
      {
        fail = true;
        cout << "Source Account: ";
        cin >> number;
        cout << "Destination Account: ";
        cin >> temp;
        for (int i = 0; i < 20; i++)
        {
          if (cust_ptr[i] != nullptr)
          {
            if (cust_ptr[i]->getChAccountNum() == number)
            {
              for (int b = 0; b < 20; b++)
              {
                if (cust_ptr[b] != nullptr)
                {
                  if (cust_ptr[b]->getChAccountNum() == temp)
                  {
                    cout << "Money Account: ";
                    cin >> balance;
                    if(cust_ptr[i]->ChWithdrawl(balance, false))
                    {
                      cust_ptr[b]->deposit(balance,1);
                      cout << "Transfer succeed." << endl;
                      cout << "      " << cust_ptr[i]->getChAccountNum() << ": $" << cust_ptr[i]->getChBalance() << endl;
                      cout << "      " << cust_ptr[b]->getChAccountNum() << ": $" << cust_ptr[b]->getChBalance() << endl;
                      fail = false;
                    }
                  }
                  if (cust_ptr[b]->getSaAccountNum() == temp)
                  {
                    cout << "Money Account: ";
                    cin >> balance;
                    if (b != i)
                    {
                      fail = false;
                    }
                    if(cust_ptr[i]->ChWithdrawl(balance, fail))
                    {
                      cust_ptr[b]->deposit(balance,2);
                      cout << "Transfer succeed." << endl;
                      cout << "      " << cust_ptr[i]->getChAccountNum() << ": $" << cust_ptr[i]->getChBalance() << endl;
                      cout << "      " << cust_ptr[b]->getSaAccountNum() << ": $" << cust_ptr[b]->getChBalance() << endl;
                      fail = false;
                    }
                  }
                }
              }
              if (fail == true)
              {
                cout << "Transfer fail - Inccorect account number." << endl;
              }
            }
            if (cust_ptr[i]->getSaAccountNum() == number)
            {
              for (int b = 0; b < 20; b++)
              {
                if (cust_ptr[b] != nullptr)
                {
                  if (cust_ptr[b]->getSaAccountNum() == temp)
                  {
                    cout << "Money Account: ";
                    cin >> balance;
                    if(cust_ptr[i]->SaWithdrawl(balance, false))
                    {
                      cust_ptr[b]->deposit(balance,2);
                      cout << "Transfer succeed." << endl;
                      cout << "      " << cust_ptr[i]->getSaAccountNum() << ": $" << cust_ptr[i]->getChBalance() << endl;
                      cout << "      " << cust_ptr[b]->getSaAccountNum() << ": $" << cust_ptr[b]->getChBalance() << endl;
                      fail = true;
                    }
                  }
                  if (cust_ptr[b]->getChAccountNum() == temp)
                  {
                    cout << "Money Account: ";
                    cin >> balance;
                    if (b != i)
                    {
                      fail = false;
                    }
                    if(cust_ptr[i]->SaWithdrawl(balance, fail))
                    {
                      cust_ptr[b]->deposit(balance,1);
                      cout << "Transfer succeed." << endl;
                      cout << "      " << cust_ptr[i]->getSaAccountNum() << ": $" << cust_ptr[i]->getSaBalance() << endl;
                      cout << "      " << cust_ptr[b]->getChAccountNum() << ": $" << cust_ptr[b]->getChBalance() << endl;
                      fail = false;
                    }
                  }
                }
              }
            }
          }
        }
      }


      if (option == 6)
      {
        int* SSNsort = new int [20];
        holder = 0;
        for (int i = 0; i < 20; i++)
        {
          if (cust_ptr[i] != nullptr)
          {
              SSNsort[holder] = i;
              for (int c = holder; c > 0; c--)
              {
                if (cust_ptr[(SSNsort[c])]->getSSN() < cust_ptr[(SSNsort[c-1])]->getSSN())
                  {
                    temp = SSNsort[c];
                    SSNsort[c] = SSNsort[c-1];
                    SSNsort[c-1] = temp; 
                  }
              }
            holder++;
          }
        }
        if (holder > 0)
        {
          cout << "========= Customer List =========";
        
          for (int b = 0; b < holder; b++)
          {
            cout << endl;
            cout << "      SSN: " << cust_ptr[SSNsort[b]]->getSSN() << endl;
            cout << "      Name: " << cust_ptr[SSNsort[b]]->getFname() << " " << cust_ptr[SSNsort[b]]->getLname() << endl;
          }
          cout << "=================================" << endl << endl;
        }
        delete[] SSNsort;
      }
    }
    while (option != 7);
    cout << "Bye!";
    return 0;
}
