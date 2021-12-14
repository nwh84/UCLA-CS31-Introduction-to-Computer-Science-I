//
//  FrequentFlyerAccount.cpp
//  Project 5
//
//

#include "FrequentFlyerAccount.h"
#include <iostream>
using namespace std;

FrequentFlyerAccount::FrequentFlyerAccount(string name)
{
    mName=name;
    mBalance=0.0;
}

double FrequentFlyerAccount::getBalance()
{
    return (mBalance);
}

string FrequentFlyerAccount::getName()
{
    return (mName);
}

bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight)
{
    //add flight if flight name equals account name
    if (mName==flight.getName()){
        double m= flight.getMileage();
    //don't add mileage if flight is a free flight
        if (flight.getCost()!=0.0){
            //city values are not empty, they can't be matching so I didn't check for that
            if(flight.getToCity()!="" &&flight.getFromCity()!="")
            mBalance=mBalance+m;}
        return true;
    }
    return false;
}

bool FrequentFlyerAccount::canEarnFreeFlight(double mileage)
{
    //eligible for free flight if mileage is less than account balance
    if(mBalance>= mileage && mileage>0){
        return true;
    }
    return false;
}


bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight& flight)
{
    //eligible for free flight if mileage is less than account balance
    if(mBalance>= mileage && mileage>0 && from!=to){
    //set name equal to account name
    flight.setName(mName);
    //set cost equal to zero
    flight.setCost(0.0);
    flight.setMileage(mileage);
    //set To City and From City equal to blank strings first to prevent errors in setting ToCity and FromCity
    flight.setToCity(" ");
    flight.setFromCity("  ");
    flight.setToCity(to);
    flight.setFromCity(from);
    //free flight mileage does not count towards account balance
    mBalance=mBalance-mileage;
        
    return true;
    }
    return false;
}
