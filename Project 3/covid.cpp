//
//  main.cpp
//  Project_3
//


#include <iostream>
#include <string>
using namespace std;

// function declarations
bool isValidResultString(string results);
int positiveTests(string results);
int negativeTests(string results);
int totalTests(string results);
int batches(string results);

int main() {

    string s;
    cout.setf( ios::boolalpha ); // prints bool values as "true" or "false"
    for(;;)
    {
        cout << "Enter a possible result string: ";
        getline(cin, s); if (s == "quit") break;
        cout << "isValidResultString returns ";
        cout << isValidResultString(s) << endl;
        cout << "positiveTests(s) returns ";
        cout << positiveTests(s) << endl;
        cout << "negativeTests(s) returns ";
        cout << negativeTests(s) << endl;
        cout << "totalTests(s) returns ";
        cout << totalTests(s) << endl;
        cout << "batches(s) returns ";
        cout << batches(s) << endl;
    }
    
    return(0);
}


//function definitions
bool isValidResultString(string results)
{
    int size = results.size();
    
    //variables for total tests, negative tests, and positive tests
    int total_tests=0;
    int positive_tests=0,negative_tests=0;
    
    //test first R is valid
    if(results[0]!='R'){return(0);}
    
    //loop through entire string
    for(int i=0;i<=size-1;i++)
    {
        //test that all values are valid
        if(results[i]!='R'&&results[i]!='+'&&results[i]!='-'&&results[i]!='0'&&results[i]!='1'&&results[i]!='2'&&results[i]!='3'&&results[i]!='4'&&results[i]!='5'&&results[i]!='6'&&results[i]!='7'&&results[i]!='8'&&results[i]!='9'){return 0;}
        //check that 0 isn't after R
        if (results[i]=='R'&& results[i+1]!='1'&& results[i+1]!='2'&& results[i+1]!='3'&& results[i+1]!='4'&& results[i+1]!='5'&& results[i+1]!='6'&& results[i+1]!='7'&& results[i+1]!='8'&& results[i+1]!='9'){return 0;}
        
        //find total number of tests
        if (results[i]=='R'){
            int g=0;
            //create int g equal to digits of positive test value
            for(int  j=i+1;results[j]=='0'||results[j]=='1'||results[j]=='2'||results[j]=='3'||results[j]=='4'||results[j]=='5'||results[j]=='6'||results[j]=='7'||results[j]=='8'||results[j]=='9';j++){
                    g++;
                }
                //add up the digits to find positive_tests
            for(int k=1;k<=g;k++){
                int x= (results[i+k]-48);
                int value=1;
                for(int i = 0; i < g-k; ++i)
                {
                    value*= 10;
                }
                x=x*value;
                total_tests=total_tests+x;
            }
        }

        //check that + and - is always followed by a value 0-9
        if ((results[i]=='+'||results[i]=='-')&& results[i+1]!='0'&& results[i+1]!='1'&& results[i+1]!='2'&& results[i+1]!='3'&& results[i+1]!='4'&& results[i+1]!='5'&& results[i+1]!='6'&& results[i+1]!='7'&& results[i+1]!='8'&& results[i+1]!='9'){return 0;}
        //find number of positive tests
        if (results[i]=='+'){
                int g=0;
                //create int g equal to digits of positive test value
                for(int  j=i+1;results[j]=='0'||results[j]=='1'||results[j]=='2'||results[j]=='3'||results[j]=='4'||results[j]=='5'||results[j]=='6'||results[j]=='7'||results[j]=='8'||results[j]=='9';j++){
                        g++;
                    }
                //add up the digits to find positive_tests
                for(int k=1;k<=g;k++){
                    int x= (results[i+k]-48);
                    int value=1;
                    for(int i = 0; i < g-k; ++i)
                    {
                        value*= 10;
                    }
                    x=x*value;
                    positive_tests=positive_tests+x;
                }
            }
        //find number of negative tests
        if (results[i]=='-'){
            int g=0;
            //create int g equal to digits of positive test value
            for(int  j=i+1;results[j]=='0'||results[j]=='1'||results[j]=='2'||results[j]=='3'||results[j]=='4'||results[j]=='5'||results[j]=='6'||results[j]=='7'||results[j]=='8'||results[j]=='9';j++){
                    g++;
                }
            //add up the digits to find negative_tests
            for(int k=1;k<=g;k++){
                int x= (results[i+k]-48);
                int value=1;
                for(int i = 0; i < g-k; ++i)
                    {
                    value*= 10;
                    }
                x=x*value;
                negative_tests=negative_tests+x;
            }
        }
        
        //check that there are no leading zeros
        if((results[i]=='+'||results[i]=='-')&&results[i+1]=='0'&&(results[i+2]=='0'||results[i+2]=='1'||results[i+2]=='2'||results[i+2]=='3'||results[i+2]=='4'||results[i+2]=='5'||results[i+2]=='6'||results[i+2]=='7'||results[i+2]=='8'||results[i+2]=='9')){return 0;}
        //check that + and - tests equal the number of tests reported
        if(total_tests!=positive_tests+negative_tests && (results[i+1]=='R'|| i==size-1)){return 0;}
        //check that there is a + and - inside every batch
        if(results[i+1]=='R'||i==size-1){
            int plus=0;
            int minus=0;
            for(int j=i;results[j]!='R';j--){
                if (results[j]=='+'){
                    plus=1;
                    }
                if(results[j]=='-'){
                    minus=1;
                    }
            }
            if(plus+minus!=2){return 0;}
        }
    }
    return (1);
}


int positiveTests(string results){
if (!isValidResultString(results)){return(-1);}
int size = results.size(), positive_test=0;
    //loop through string
    for(int i=0;i<=size-1;i++){
        if (results[i]=='+'){
            int g=0;
            //create int g equal to digits of positive test value
                for(int  j=i+1;results[j]=='0'||results[j]=='1'||results[j]=='2'||results[j]=='3'||results[j]=='4'||results[j]=='5'||results[j]=='6'||results[j]=='7'||results[j]=='8'||results[j]=='9';j++){
                    g++;
                }
                //add up the digits to find positive_tests
                for(int k=1;k<=g;k++){
                    int x= (results[i+k]-48);
                    int value=1;
                    for(int i = 0; i < g-k; ++i)
                    {
                        value*= 10;
                    }
                    x=x*value;
                    positive_test=positive_test+x;
                }
            }
        }
    return(positive_test);
}
    


int negativeTests(string results){
    if (!isValidResultString(results)){return(-1);}
    int size = results.size(), negative_test=0;
        //loop through string
        for(int i=0;i<=size-1;i++){
            if (results[i]=='-'){
                int g=0;
                //create int g equal to digits of negative test value
                for(int  j=i+1;results[j]=='0'||results[j]=='1'||results[j]=='2'||results[j]=='3'||results[j]=='4'||results[j]=='5'||results[j]=='6'||results[j]=='7'||results[j]=='8'||results[j]=='9';j++){
                    g++;
                }
                //add up the digits to find negative_tests
                for(int k=1;k<=g;k++){
                int x= (results[i+k]-48);
                    int value=1;
                    for(int i = 0; i < g-k; ++i)
                    {
                        value*= 10;
                    }
                    x=x*value;
                    negative_test=negative_test+x;
                }
            }
        }
    return(negative_test);
}


int totalTests(string results)
{
    //check that string is valid
    if (!isValidResultString(results)){return(-1);}
    int positive_tests=0, negative_tests=0, total_tests=0;
    //run positive_tests to find number of positive tests
    positive_tests=positiveTests(results);
    //run negative_tests to find number of negative tests
    negative_tests=negativeTests(results);
    //add up positive and negative tests to find total_tests
    total_tests=positive_tests+negative_tests;
    return(total_tests);
}


int batches(string results){
    if (!isValidResultString(results)){return(-1);}
    int size = results.size(),batches=0;
    for(int i=0;i<=size+1;i++){
        if (results[i]=='R'){
            batches++;
        }
    }
    return(batches);
}

