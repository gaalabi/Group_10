#include "Student.h"


Student::Student():Personnel(), majorLen(20)
{
    _major = new char[majorLen+1];
}
Student::Student(char n[], char s[], char y[], char c[], char sal[], char m[]):Personnel(n,s,y,c,sal)
{
    strncpy(_major, m, majorLen+1);
}
void Student::setMajor(char m[])
{
    strncpy(_major, m, majorLen+1);
}
char* Student::getMajor() const
{
    return _major;
}
int Student::getBPR()
{
    return (this->getNameLen())+(this->getCityLen())+majorLen+4+9+7;
}
void Student::print() const
{
    cout << "Name:" << this->getName() <<", SSN:" << this->getSSN() << ", City:" << this->getCity() <<", YOB:"
    << this->getYOB() << ", Salary:" << this->getSalary() <<", Major:" << this->getMajor() << endl;
}
void Student::writeToFile(ofstream& out)
{
    /*char* name = this.getName();
    char* city  this.getCity();
    char* ssn = this.getSSN();
    char* yob = this.getYOB();
    char* salary = this.getSalary();*/

    out.write(this->getName(),this->getNameLen());
    out << this->getSSN();
    out.write(this->getCity(),this->getCityLen());
    out << this->getYOB();
    out.write(this->getSalary(),7);

    out.write(_major, majorLen);
}
Student* Student::readFromFile(ifstream& in)
{
    string record;
    int nL = this->getNameLen();
    int cL = this->getCityLen();
    char r, rec[61];
    string name, ssn, city, yob, salary, major;
    char n[nL+1], s[10], c[cL+1], ye[5], sa[8], m[majorLen+1];


    while(in >> r)
    {
        record.push_back(r);
    }

    //cout << record << '\n';

    for(int j = 0; j < 60; j++)
    {
        rec[j] = record[j];

    }

    //cout << endl;



    for(int i = 0; i < nL; i++)
    {
        name.push_back(rec[i]);
    }

    for(int i = 0; i < 9; i++)
    {
        ssn.push_back(rec[nL+i]);
    }

    for(int i = 0; i < cL; i++)
    {
        city.push_back(rec[nL+9+i]);
    }

    for(int i = 0; i < 4; i++)
    {
        yob.push_back(rec[nL+9+cL+i]);
    }
    for(int i = 0; i < 8; i++)
    {
        salary.push_back(rec[nL+13+cL+i]);
    }
    for(int i = 0; i < majorLen && rec[nL+20+cL+i] != '\0' ; i++)
    {
        major.push_back(rec[nL+20+cL+i]);
    }

    /*cout << name << endl;
    cout << ssn <<endl;
    cout << city <<endl;
    cout << yob << endl;
    cout << salary <<endl;
    cout << major << endl;*/


    strncpy(n, name.c_str(), nL+1);
    strncpy(s, ssn.c_str(), 10);
    strncpy(c,city.c_str(),cL+1);
    strncpy(ye, yob.c_str(), 5);
    strncpy(sa, salary.c_str(), 8);
    strncpy(m, major.c_str(), majorLen+1);

    this->setname(n);
    this->setSSN(s);
    this->setcity(c);
    this->setYOB(ye);
    this->setsalary(sa);
    this->setMajor(m);

    return this;

}

Student::~Student()
{
    delete _major;
    _major = nullptr;
}
