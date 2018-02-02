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

    /*
    
    Assumming this is how it will look like?
    
    database <student> studentfile;
    bool over = false;
    int answer;
    string Reply = "";
    string Reply_what = "";
    personnel A;
    while (!over){
        cout<<"what would you like to do:"<<endl;
        cout<<"1: add"<<endl;
        cout<<"2: find"<<endl;
        cout<<"3: modify"<<endl;
        cout<<"4: print"<<endl;
        cout<<"5: exit"<<endl;
        cout<<"answer here: ";
        cin>>answer;
        
        switch (answer) {
            case 1:
                studentfile.add(A);
                break;
            case 2:
                studentfile.find(A);
                break;
            case 3:
                //if they choose to modify
                cout<<"what would you like to modify (name,city,YOB,Salary):";
                cin>>Reply;
                cout<<endl;
                cout<<"what would you like to change it to: ";
                cin>>Reply_what;
                studentfile.modify(A,Reply,Reply_what);
                Reply = "";
                Reply_what = "";
                break;
            case 4:
                studentfile.print();
                break;
            case 5:
                over = true;
                break;
            default:
                break;
        }
        cout<<endl<<endl;
    }
    */

    return 0;
}
