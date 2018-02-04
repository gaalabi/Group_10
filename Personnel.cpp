#include "Personnel.h"


Personnel::Personnel() : nameLen(10),cityLen(10)
{
    _name = new char[nameLen+1];
    _SSN = new char[10];
    _YOB = new char[5];
    _city = new char[cityLen+1];
    _salary = new char[8];

}
Personnel::Personnel(char n[], char s[], char y[], char c[], char sal[])
{
    strncpy(_name, n, nameLen+1);
    strncpy(_SSN, s, 10);
    strncpy(_YOB, y, 5);
    strncpy(_city, c, cityLen+1);
    strncpy(_salary, sal, 8);

}
void Personnel::setname(char n[])
{
    strncpy(_name, n, nameLen+1);

}
void Personnel::setSSN(char s[])
{
    strncpy(_SSN, s, 10);
}
void Personnel::setcity(char c[])
{
    strncpy(_city, c, cityLen+1);
}
void Personnel::setYOB(char y[])
{
    strncpy(_YOB, y, 5);
}
void Personnel::setsalary(char sal[])
{
    strncpy(_salary, sal, 8);
}
char* Personnel::getName()
{
    return _name;
}
char* Personnel::getCity()
{
    return _city;
}
char* Personnel::getSalary()
{
    return _salary;
}
char* Personnel::getSSN()
{
    return _SSN;
}
char* Personnel::getYOB()
{
    return _YOB;
}
int Personnel::getNameLen()
{
    return nameLen;
}
int Personnel::getCityLen()
{
    return cityLen;
}

void Personnel::print()
{
    cout << "Name:" << this->getName() <<", SSN:" << this->getSSN() << ", City:" << this->getCity() <<", YOB:" << this->getYOB() << ", Salary:" << this->getSalary() << endl;
}
void Personnel::writeToFile(ofstream& out)
{
    out.write(_name,nameLen);
    out << this->getSSN();
    out.write(_city, cityLen);
    out << this->getYOB();
    out.write(_salary,8);
    //out.write(reinterpret_cast<const char*>(&_salary), sizeof(long));
}
Personnel* Personnel::readFromFile(ifstream& in)
{
    string record;
    char r, rec[41];
    string name, ssn, city, yob, salary;
    char n[nameLen+1], s[10], c[cityLen+1], ye[5], sa[8];


    while(in >> r)
    {
        record.push_back(r);
    }

    cout << record << '\n';

    for(int j = 0; j < 40; j++)
    {
        rec[j] = record[j];

        cout << rec[j];
    }

    cout << endl;



    for(int i = 0; i < nameLen; i++)
    {
        name.push_back(rec[i]);
    }

    for(int i = 0; i < 9; i++)
    {
        ssn.push_back(rec[nameLen+i]);
    }

    for(int i = 0; i < cityLen; i++)
    {
        city.push_back(rec[nameLen+9+i]);
    }

    for(int i = 0; i < 4; i++)
    {
        yob.push_back(rec[nameLen+9+cityLen+i]);
    }
    for(int i = 0; i < 8 && rec[nameLen+13+cityLen+i] != '\0' ; i++)
    {
        salary.push_back(rec[nameLen+13+cityLen+i]);
    }

    cout << name << endl;
    cout << ssn <<endl;
    cout << city <<endl;
    cout << yob << endl;
    cout << salary <<endl;


    strncpy(n, name.c_str(), nameLen+1);
    strncpy(s, ssn.c_str(), 10);
    strncpy(c,city.c_str(),cityLen+1);
    strncpy(ye, yob.c_str(), 5);
    strncpy(sa, salary.c_str(), 8);

    this->setname(n);
    this->setSSN(s);
    this->setcity(c);
    this->setYOB(ye);
    this->setsalary(sa);

    return this;

}


Personnel::~Personnel()
{
    delete _name;
    _name = nullptr;
    delete _SSN;
    _SSN = nullptr;
    delete _YOB;
    _YOB = nullptr;
    delete _city;
    _city = nullptr;
    delete _salary;
    _salary = nullptr;
}
