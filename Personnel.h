#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "ArguemnetManager.h"

using namespace std;



class Personnel
{
    public:
        Personnel();
        Personnel(char n[], char s[], char y[], char c[], char m[]);
        void setname(char n[]);
        void setSSN(char s[]);
        void setYOB(char y[]);
        void setcity(char c[]);
        void setsalary(char m[]);
        void print();
        void writeToFile(ofstream& out);
        void readFromFile(ofstream& in);

        char* getName();
        char* getSSN();
        char* getYOB();
        char* getCity();
        char* getSalary();

        virtual ~Personnel();

    protected:

    private:
        int nameLen, cityLen;
        char *_name, *_SSN, *_YOB, *_city, *_salary;

};

#endif // PERSONNEL_H
