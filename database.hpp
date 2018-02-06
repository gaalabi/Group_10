//
//  database.hpp
//  GroupProject01
//
//  Created by Tony Tran on 2/4/18.
//  Copyright © 2018 Tonney7. All rights reserved.
//

#ifndef database_hpp
#define database_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Personnel.hpp"
#include "Student.hpp"

using namespace std;

template <class T>
class database{
private:
    char* f;
    //T rec;
    //string stored_Data;
public:
    
    database();
    ~database();
    int find(char * file, string SSN_check,int Student_or_personnel);
    void modify(char * file,string SSN_check, string change_item, string change_to, int Student_or_personnel);
    void add(string file, T stuff);
    void print(char * file, int Student_or_personnel);
};
#endif /* database_hpp */


template <class T>
database<T>::database(){}
template <class T>
database<T>::~database(){}

template <class T>
int database<T>::find(char * file, string SSN_check, int Student_or_personnel){
    /*T A;
    ifstream f;
    f.open(file);
    A.readFromFile(f);
    A.print();*/
    
    Student ran1;
    Personnel ran2;
    
    int counter1 = 0;
    ifstream f;
    f.open(file);
    while (!f.eof()){       //while not end of file
        counter1++;                             //add to counter each loop
        if (Student_or_personnel == 1){         //if student
            ran1.readFromFile(f);               //read the information onto ran1
            if (strcmp(ran1.getSSN(), SSN_check.c_str()) == 0 ){        //check for similarity in SSN
                return counter1;                //return the counter position
            }
        }
        else{
            ran2.readFromFile(f);               //if Personnel,read the information onto ran2
            if (strcmp(ran1.getSSN(), SSN_check.c_str()) == 0 ){    //check for similarity in SSN
                return counter1;           //return the counter position
            }
        }
    }
    f.close();
    return -1;      //if no matches, return -1
}
 
 template <class T>
 void database<T>::modify(char * file,string SSN_check, string change_item, string change_to, int Student_or_personnel){
     Student ran1;
     Personnel ran2;
 
 
     char * intermediate;
     strcpy(intermediate, change_to.c_str());
 
     int counter = 0;
     int Index = find(f, SSN_check,Student_or_personnel); //find the index of where the matching
 
     ifstream f;
     ofstream f2;
     f.open(file);
     f2.open(file);
     while (!f.eof()){      //while not end of file
         if (Student_or_personnel == 1){    // if student
             ran1.readFromFile(f);      //read from file onto ran1
         }
         else{                              // if Personnel
             ran2.readFromFile(f);      //read from file onto ran2
         }
         counter++;
         if (Student_or_personnel == 1){
             if (counter == Index){  //if found the line of what to change, keep it in A
                 if (change_item == "name"){             //if they ask to change name
                     ran1.setname(intermediate);        //change the name
                 }
                 else if (change_item == "city"){
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
                     ran1.setname(intermediate);        //change the name
                 }
                 else if (change_item == "city"){
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
     if (Student_or_personnel == 1){//write to file if student
         ran1.writeToFile(f2);
        }
    else{
        ran2.writeToFile(f2); //write to file if personnel
        }
    }
     f2.close();     
}
template <class T>
void database<T>::add(string file, T stuff){
    ofstream f;
    f.open(file);
    stuff.writeToFile(f);
    f.close();
}

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

