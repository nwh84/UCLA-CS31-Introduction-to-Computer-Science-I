//
//  FrequentFlyerAccount.hpp
//  Project 5
//
//

#ifndef FrequentFlyerAccount_h
#define FrequentFlyerAccount_h

#include <string>
#include "PlaneFlight.h"
using namespace std;

class FrequentFlyerAccount
{
public:
    FrequentFlyerAccount(string name);
    double getBalance();
    string getName();
    bool addFlightToAccount(PlaneFlight flight);
    bool canEarnFreeFlight(double mileage);
    bool freeFlight(string from, string to, double mileage, PlaneFlight& flight);
    
private:
    string mName;
    double mBalance;
};

#endif
