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
        friend ostream& operator <<(ostream& outs,const Personnel& p)
        {
            p.print();

        };
        friend bool operator ==(const Personnel& o, const Personnel& p)
        {
            char* ss1 = o.getSSN();
            char* ss2 = p.getSSN();

            int comp = strcmp(ss1, ss2);


            return (comp == 0);
        };
        Personnel();
        Personnel(char n[], char s[], char y[], char c[], char sal[]);
        void setname(char n[]);
        void setSSN(char s[]);
        void setYOB(char y[]);
        void setcity(char c[]);
        void setsalary(char sal[]);
        void print() const;
        void writeToFile(ofstream& out);
        Personnel* readFromFile(ifstream& in);

        char* getName() const;
        char* getSSN() const;
        char* getYOB() const;
        char* getCity() const;
        char* getSalary() const;
        int getNameLen();
        int getCityLen();
        int getBPR();

        virtual ~Personnel();

    protected:

    private:
        int nameLen, cityLen;
        char *_name, *_SSN, *_YOB, *_city, *_salary;

};

#endif // PERSONNEL_H
