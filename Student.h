#ifndef STUDENT_H
#define STUDENT_H

#include <Personnel.h>


class Student : public Personnel
{
    public:
        Student();
        Student(char n[], char s[], char y[], char c[], char sal[], char m[]);
        void setMajor(char m[]);
        void print() const;
        void writeToFile(ofstream& out);

        int getBPR();
        char* getMajor() const;
        Student* readFromFile(ifstream& in);

        virtual ~Student();

    protected:

    private:
        int majorLen;
        char *_major;

};

#endif // STUDENT_H
