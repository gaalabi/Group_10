#include <iostream>
#include <fstream>
#include "Personnel.h"

using namespace std;

int main(int argc, char* argv[])
{
    ofstream outstream("newfangled.txt");
    ifstream intake("newfangled.txt");

    char name[] = "Micheal";
    char ssn[]= "123456789";
    char yob[] = "2012";
    char city[] = "Lexington";
    char salary[] = "50010";


    Personnel p, q;
    p.setname(name);
    p.setSSN(ssn);
    p.setYOB(yob);
    p.setcity(city);
    p.setsalary(salary);

    p.print();

    cout <<'\n';

    p.writeToFile(outstream);

    outstream.close();

    cout <<sizeof(p)<< "\n";

    cout << "Name size: " <<sizeof(p.getName()) << "\n";
    cout << "SSN size: " <<sizeof(p.getSSN())<<"\n";
    cout << "YOB size: " <<sizeof(p.getYOB())<<"\n";
    cout << "City size: " <<sizeof(p.getCity()) <<"\n";
    cout << "Salary size: "<<sizeof(p.getSalary())<<"\n";

    q.readFromFile(intake);
    q.print();



    intake.close();



    return 0;
}
