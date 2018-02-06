#include <iostream>
#include <fstream>
using namespace std;
#include "Personnel.hpp"
#include "Student.hpp"
#include "database.hpp"
#include <string>

int main() {
    
    database <Student> Studentfile;
    //database <Personnel> Personnelfile;
    
    bool over = false;
    int answer;
    int answer2;
    string Change_What = "";
    string Change_To_What = "";
    string ASDF;
    string QWERTY;
    
    string Text;
    char *textFile;
    
    Personnel A;
    Student B;
    
    string name;
    string SSN;
    string City;
    string YOB;
    string Salary;
    string Major;
    
    char * name2;
    char * SSN2;
    char * City2;
    char * YOB2;
    char * Salary2;
    char * Major2;
    
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
                cin>>Text;
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
                
                strncpy(name2, name.c_str(), 11);
                strncpy(SSN2, SSN.c_str(), 10);
                strncpy(City2, City.c_str(), 11);
                strncpy(YOB2, YOB.c_str(), 5);
                strncpy(Salary2, Salary.c_str(), 8);
                strncpy(Major2, Major.c_str(), 21);
                strcpy(textFile, Text.c_str());
                if (answer2 == 1){
                    //i'm not sure how to use the set for student
                        //nvm, if i initialted the stuff as char*, it works
                    B.setname(name2);
                    B.setSSN(SSN2);
                    B.setYOB(YOB2);
                    B.setcity(City2);
                    B.setsalary(Salary2);
                    B.setMajor(Major2);
                    
                    //or we could do something like this
                    //Studentfile.add(Text, B);
                }
                else{
                    //i'm not sure how to use the set for personnel
                        //nvm, if i initialted the stuff as char*, it works
                    A.setname(name2);
                    A.setSSN(SSN2);
                    A.setYOB(YOB2);
                    A.setcity(City2);
                    A.setsalary(Salary2);
                    
                    //or we could do something like this
                    //Personnelfile.add(Text, A);
                }
                break;
            /*case 2:
                //if they choose to Find
                cout<<"Student (1) or personnel (2) ?: ";
                cin>>answer2;
                cout<<endl;
                
                cout<<"What is the database txt file name: ";
                cin>>Text;
                cout<<endl;
                
                cout<<"Who is the person whom you are trying to find (type in their SSN): ";
                cin>>QWERTY;
                cout<<endl;
                
                strcpy(textFile, Text.c_str());
                
                if (answer2 == 1){
                    if (Studentfile.find(textFile, QWERTY,answer2) != -1){
                        cout<<"This person do exist in file"<<endl;
                    }
                    else{
                        cout<<"This person does not exist in file"<<endl;
                    }
                }
                else{
                    if (Personnelfile.find(textFile, QWERTY,answer2) != -1){
                        cout<<"This person do exist in file"<<endl;
                    }
                    else{
                        cout<<"This person does not exist in file"<<endl;
                    }
                }
                break;
                
            case 3:
                //if they choose to modify
                cout<<"Student (1) or personnel (2) ?: ";
                cin>>answer2;
                cout<<endl;
                
                cout<<"What is the database txt file name: ";
                cin>>Text;
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
                
                strcpy(textFile, Text.c_str());
                
                if (answer2 == 1){
                    Studentfile.modify(textFile,QWERTY,Change_What,Change_To_What,answer2);
                }
                else{
                    Personnelfile.modify(textFile,QWERTY,Change_What,Change_To_What,answer2);
                }
                break;
                
            case 4:
                cout<<"Student (1) or personnel (2) ?: ";
                cin>>answer2;
                cout<<endl;
                cout<<"What is the database txt file name: ";
                cin>>Text;
                cout<<endl;
                
                strcpy(textFile, Text.c_str());
                Studentfile.print(textFile,answer2);
                break;*/
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
