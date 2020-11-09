#include<stdio.h>
#include<iostream>
using namespace std;
bool accrueInterest(
  double& balanceAmt,
  const int numMonths,
  const bool doPrintEachMonth
);

bool accrueOneMonthsInterest(
  double& balanceAmt,
  const bool doPrintInfo
);

// Programmer: Zihan Zhang
// Date: Sep. 2020
// Purpose: Calculate accrued interests based on input balance

#ifdef ANDREW_TEST
#include "andrewTest.h" 
#else 

int main()
{
  double initBalance;
  int numOfMonth;
  char yesChecking;
  bool doPrintEach;

  cout << "Welcome to the Interests Checking System" << endl;
  cout << "Please enter the initial bank accounnt balance: ";
  cin >> initBalance;

  cout << "Please enter the number of months to accure interests: ";
  cin >> numOfMonth;

  cout << "Show month-by-month results - 'y' for yes, any other for no: ";
  cin >> yesChecking;
  if (yesChecking == 'y') {
    doPrintEach = true;
  }
  else {
    doPrintEach = false;
  }


  accrueInterest(initBalance, numOfMonth, doPrintEach);
}

#endif

// accrueInterest(): calculate the accrued interest
// call accrueOneMonthsInterest() to calculate and display interest for each month
bool accrueInterest(
  double& balanceAmt,
  const int numMonths,
  const bool doPrintEachMonth)
{

  if (balanceAmt < 0) {
    cout << "ERROR in accrueInterest: balanceAmt must be >= 0,  but the value ";
    cout << balanceAmt << " was provided!" << endl;
    cout << "Sorry, an error was detected. Unable to provide results!" << endl;
    return false;
  }
  if (numMonths <= 0) {
    cout << "ERROR in accrueInterest: numMonths must be > 0,  but the value ";
    cout << numMonths << " was provided!" << endl;
    cout << "Sorry, an error was detected. Unable to provide results!" << endl;
    return false;
  }

  int initAmt = balanceAmt;

  int countMonth = numMonths;
  while (countMonth > 0) {
    accrueOneMonthsInterest(balanceAmt, doPrintEachMonth);
    countMonth--;
  }



  cout << "Interest accrued for " << numMonths << " months!" << endl;
  cout << endl;
  cout << "Initial balance: " << initAmt << endl;
  cout << "Total interest accrued: " << (balanceAmt - initAmt) << endl;
  cout << "Final balance: " << balanceAmt << endl;
  return true;
}

// accrueOneMonths interest(): called accrueInterest()
// To calculate and display interest for each month
bool accrueOneMonthsInterest(
  double& balanceAmt,
  const bool doPrintInfo)
{

  double rate;
  double newBalence;

  if (balanceAmt < 0) {
    cout << "ERROR in accrueOneMonthsInterest: balanceAmt must be >= 0, ";
    cout << "but the value - " << balanceAmt << " was provided!" << endl;
    cout << "Sorry, an error was detected. Unable to provide results!" << endl;
    return false;
  }

  if (balanceAmt < 1000.00){
    rate = 0.0015;
  }
  else if (balanceAmt >= 15000.00) {
    rate = 0.004;
  }
  else {
    rate = 0.00225;
  }
  newBalence = balanceAmt * (1 + rate);
  if (doPrintInfo){
    cout << "Accruing interest for 1 month: " << endl;
    cout << "  Initial balance: " << balanceAmt << endl;
    cout << "  Initial rate: " << rate << endl;
    cout << "  Interest accrued: " << (newBalence - balanceAmt) << endl;
    cout << "  New balance: " << newBalence << endl;
  }

  balanceAmt = newBalence;
  return true;
}