#include <iostream>
#include <fstream>
using namespace std;
#include "Personnel.hpp"
#include "Student.hpp"
#include "database.hpp"


int main() {
    
    database <Student> Studentfile;
    database <Personnel> Personnelfile;
    
    bool over = false;
    int answer;
    int answer2;
    string Change_What = "";
    string Change_To_What = "";
    string ASDF;
    string QWERTY;
    
    char *textFile;
    
    Personnel A;
    Student B;
    
    string name;
    string SSN;
    string City;
    string YOB;
    string Salary;
    string Major;
    
    while (!over){
        
        cout<<"what would you like to do:"<<endl;
        cout<<"1: add"      <<endl;
        cout<<"2: find"     <<endl;
        cout<<"3: modify"   <<endl;
        cout<<"4: print"    <<endl;
        cout<<"5: exit"     <<endl;
        cout<<"answer here: ";
        cin>>answer;
        
        switch (answer) {
            case 1:
                cout<<"Student (1) or personnel (2) ?: ";
                cin>>answer2;
                cout<<endl;
                
                cout<<"What is the database txt file name: ";
                cin>>textFile;
                cout<<endl;
                
                cout<<"What is the name (no spaces please): ";
                cin>>name;
                cout<<endl;
               
                cout<<"What is the SSN (no hyphen, just the numbers (9 digits only): ";
                cin>>SSN;
                cout<<endl;
                
                cout<<"What is the City (no spaces please): ";
                cin>>City;
                cout<<endl;
                
                cout<<"What is the YOB (4 numbers only): ";
                cin>>YOB;
                cout<<endl;
                
                cout<<"What is the Salary (no commas, only numbers): ";
                cin>>Salary;
                cout<<endl;
                
                if (answer2 == 1){
                    cout<<"What is the Major (no spaces please): ";
                    cin>>Major;
                    cout<<endl;
                }
                if (answer2 == 1){
                    //i'm not sure how to use the set for student
                    B.setname(name);
                    B.setSSN(SSN);
                    B.setYOB(YOB);
                    B.setcity(City);
                    B.setsalary(Salary);
                    
                    B.writeToFile(File2);
                    File2.close();
                    
                    //or we could do something like this
                    Studentfile.add(textFile, B);
                }
                else{
                    //i'm not sure how to use the set for personnel
                    A.setname(name);
                    A.setSSN(SSN);
                    A.setYOB(YOB);
                    A.setcity(City);
                    A.setsalary(Salary);
                    
                    A.writeToFile(File2);
                    File2.close();
                    
                    //or we could do something like this
                    Personnelfile.add(textFile, A);
                }
                break;
            case 2:
                //if they choose to Find
                cout<<"What is the database txt file name: ";
                cin>>textFile;
                cout<<endl;
                
                cout<<"Who is the person whom you are trying to find (type in their SSN): ";
                cin>>QWERTY;
                cout<<endl;
                
                if (Studentfile.find(textFile, QWERTY) != -1){
                    cout<<"This person do exist in file"<<endl;
                }
                else{
                    cout<<"This person does not exist in file"<<endl;
                }
                break;
                
            case 3:
                //if they choose to modify
                cout<<"What is the database txt file name: ";
                cin>>textFile;
                cout<<endl;
                
                cout<<"Who is the person whom you are trying to change (type in their SSN): ";
                cin>>QWERTY;
                cout<<endl;
                
                cout<<"what would you like to modify (name,city,YOB,Salary):";
                cin>>Change_What;
                cout<<endl;
                
                cout<<"what would you like to change it to: ";
                cin>>Change_To_What;
                cout<<endl;
                
                Studentfile.modify(textFile,QWERTY,Change_What,Change_To_What);
                break;
                
            case 4:
                cout<<"What is the database txt file name: ";
                cin>>textFile;
                cout<<endl;
                Studentfile.print(textFile);
                break;
            case 5:
                over = true;
                break;
            default:
                cout<<"That is not one of the choices"<<endl;
                break;
        }
        cout<<endl<<endl;
    }
    return 0;
}
