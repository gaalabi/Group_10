#include "database.hpp"
#include "Student.hpp"
#include "Personnel.hpp"

template <class T>
database<T>::database()
{
    f = new char[20];

}
template <class T>
database<T>::~database(){}
template <class T>
int database<T>::find(char * file, string SSN_check, int Student_or_personnel){
    T A;
    ifstream f;
    f.open(file);
    A.readFromFile(f);
    A.print();
}
    /*Student ran1;
    Personnel ran2;
    int counter1 = 0;
    ifstream f;
    f.open(file);
    while (!f.eof()){
        counter1++;
        if (Student_or_personnel == 1){
            ran1.readFromFile(f);
            if (strcmp(ran1.getSSN(), SSN_check.c_str()) == 0 ){
                return counter1;
            }
        }
        else{
            ran2.readFromFile(f);
            if (strcmp(ran1.getSSN(), SSN_check.c_str()) == 0 ){
                return counter1;
            }
        }
    }
    f.close();
    return -1;
}

template <class T>
void database<T>::modify(char * file,string SSN_check, string change_item, string change_to, int Student_or_personnel){
    Student ran1;
    Personnel ran2;
    
    
    char * intermediate;
    strcpy(intermediate, change_to.c_str());
    
    int counter = 0;
    int Index = find(f, SSN_check);
    
    ifstream f;
    ofstream f2;
    f.open(file);
    f2.open(file,ios::app);
    while (!f.eof()){
        if (Student_or_personnel == 1){
            ran1.readFromFile(f);
        }
        else{
            ran2.readFromFile(f);
        }
        counter++;
        if (Student_or_personnel == 1){
            if (counter == Index){  //if found the line of what to change, keep it in A
                if (change_item == "name"){             //if they ask to change name
                    ran1.setname(intermediate);
                }
                else if (change_item == "city"){    //DID NOT ACCOUNT FOR THE SPACING
                    ran1.setcity(intermediate);
                }
                else if (change_item == "YOB"){
                    ran1.setYOB(intermediate);
                }
                else if (change_item == "Salary"){
                    ran1.setsalary(intermediate);
                }
                else if (change_item == "Major"){
                    ran1.setMajor(intermediate);
                }
            }
        }
        else{
            if (counter == Index){  //if found the line of what to change, keep it in A
                if (change_item == "name"){             //if they ask to change name
                    ran1.setname(intermediate);
                }
                else if (change_item == "city"){    //DID NOT ACCOUNT FOR THE SPACING
                    ran1.setcity(intermediate);
                }
                else if (change_item == "YOB"){
                    ran1.setYOB(intermediate);
                }
                else if (change_item == "Salary"){
                    ran1.setsalary(intermediate);
                }
            }
        }
        
        if (Student_or_personnel == 1){
            ran1.writeToFile(f2);
        }
        else{
            ran2.writeToFile(f2);
        }
    }
    f2.close();
    
}
*/
template <class T>
void database<T>::add(string file, T stuff){
    ofstream f;
    f.open(file);
    //stuff.writeToFile(f);
    f.close();
}
/*
template <class T>
void database<T>::print(char * file, int Student_or_personnel){
    Student ran1;
    Personnel ran2;
    
    string A;
    ifstream f;
    f.open(file);
    while (!f.eof()){
        if (Student_or_personnel == 1){
            ran1.readFromFile(f);
            ran1.print();
        }
        else{
            ran2.readFromFile(f);
            ran2.print();
        }
    }
    f.close();
}
*/
