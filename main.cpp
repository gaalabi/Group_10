#include <iostream>
#include <fstream>
#include "Personnel.h"

using namespace std;

int main(int argc, char* argv[])
{
    ofstream outstream("newfangled.txt");

    char name[] = "Reggie";
    char ssn[]= "001124567";
    char yob[] = "4576";
    char city[] = "New York";
    char salary[] = "120000";


    Personnel p;
    p.setname(name);
    p.setSSN(ssn);
    p.setYOB(yob);
    p.setcity(city);
    p.setsalary(salary);



    p.print();

    p.writeToFile(outstream);

    outstream.close();



    return 0;
}
