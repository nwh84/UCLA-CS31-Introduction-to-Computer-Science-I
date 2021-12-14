//
//  main.cpp
//  project_2
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    //declare variables
    string month=" ";
    int day=1, year=1, month_code=0, century_value, century_code=1, year_code, day_code;
    
    //input date
    cout<<"Provide a month: ";
    getline(cin,month);
    cout<<"Provide a day: ";
    cin>>day;
    cout<<"Provide a year: ";
    cin>>year;
    
    //account for invalid inputs
    if (month!=
        "January"&&month!="February"&&month!="March"&&month!="April"&&month!="May"&&month!="June"&&month!="July"&&month!="August"&&month!="Septermber"&&month!="October"&&month!="November"&&month!="December"){
        cout<<"Invalid month!";
        return(1);
    }
    
    if (day<1 || day>31){
        cout<<"Invalid day!";
        return(1);
    }
    
    if (year<1 || year>3000){
        cout<<"Invalid year!";
        return(1);
    }
    
    //month code
    if (month=="January"){
        month_code=1;
    }
    if (month=="February"){
        month_code=4;
    }
    if (month=="March"){
        month_code=4;
    }
    if (month=="April"){
        month_code=0;
    }
    if (month=="May"){
        month_code=2;
    }
    if (month=="June"){
        month_code=5;
    }
    if (month=="July"){
        month_code=0;
    }
    if (month=="August"){
        month_code=3;
    }
    if (month=="September"){
        month_code=6;
    }
    if (month=="October"){
        month_code=1;
    }
    if (month=="November"){
        month_code=4;
    }
    if (month=="December"){
        month_code=6;
    }
  
    
    //leap year offset
    if (year%4==0 && (year%100!=0||year%400 == 0) && (month=="January"||month=="February")){
            month_code=month_code-1;
    }
    
    //century code
    century_value= (year/100)%4;
    if (century_value==0){
        century_code=-2;
    }
    if (century_value==1){
        century_code=3;
    }
    if (century_value==2){
        century_code=1;
    }
    if (century_value==3){
        century_code=-1;
    }
    //year code
    year_code = ((year%100)/4)+(year%100);
    
    //day code
    day_code=(century_code+day+year_code+month_code)%7;
    
    if (day_code==0){
        cout<<month<<" "<<day<<", "<<year<<" was a Sunday!";
    }
    if (day_code==1||day_code==-6){
        cout<<month<<" "<<day<<", "<<year<<" was a Monday!";
    }
    if (day_code==2||day_code==-5){
        cout<<month<<" "<<day<<", "<<year<<" was a Tuesday!";
    }
    if (day_code==3||day_code==-4){
        cout<<month<<" "<<day<<", "<<year<<" was a Wednesay!";
    }
    if (day_code==4||day_code==-3){
        cout<<month<<" "<<day<<", "<<year<<" was a Thursday!";
    }
    if (day_code==5||day_code==-2){
        cout<<month<<" "<<day<<", "<<year<<" was a Friday!";
    }
    if (day_code==6||day_code==-1){
        cout<<month<<" "<<day<<", "<<year<<" was a Saturday!";
    }
    return 0;
}
