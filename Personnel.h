#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <typeinfo>


using namespace std;



class Personnel
{
    public:
        Personnel();
        Personnel(char n[], char s[], char y[], char c[], char sal[]);
        void setname(char n[]);
        void setSSN(char s[]);
        void setYOB(char y[]);
        void setcity(char c[]);
        void setsalary(char sal[]);
        void print();
        void writeToFile(ofstream& out);
        Personnel* readFromFile(ifstream& in);

        char* getName();
        char* getSSN();
        char* getYOB();
        char* getCity();
        char* getSalary();
        int getNameLen();
        int getCityLen();

        virtual ~Personnel();

    protected:

    private:
        int nameLen, cityLen;
        char *_name, *_SSN, *_YOB, *_city, *_salary;

};

#endif // PERSONNEL_H
