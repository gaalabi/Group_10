#include "Personnel.h"


Personnel::Personnel() : nameLen(10),cityLen(10)
{
    _name = new char[nameLen+1];
    _SSN = new char[10];
    _YOB = new char[5];
    _city = new char[cityLen+1];
    _salary = new char[8];

}
Personnel::Personnel(char n[], char s[], char y[], char c[], char m[])
{
    strncpy(_name, n, nameLen);
    strncpy(_SSN, s, 10);
    strncpy(_YOB, y, 5);
    strncpy(_city, c, cityLen);
    strncpy(_salary, m, 8);

}
void Personnel::setname(char n[])
{
    strncpy(_name, n, nameLen);

}
void Personnel::setSSN(char s[])
{
    strncpy(_SSN, s, 10);
}
void Personnel::setcity(char c[])
{
    strncpy(_city, c, cityLen);
}
void Personnel::setYOB(char y[])
{
    strncpy(_YOB, y, 5);
}
void Personnel::setsalary(char m[])
{
    strncpy(_salary, m, 8);
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

void Personnel::print()
{
    cout << "Name:" << this->getName() <<", SSN:" << this->getSSN() << ", City:" << this->getCity() <<", YOB:" << this->getYOB() << ", Salary:" << this->getSalary();
}
void Personnel::writeToFile(ofstream& out)
{
    out << "Name:";
    out.write(_name,nameLen);
    out <<", SSN:" << this->getSSN() << ", City:";
    out.write(_city, cityLen);
    out <<", YOB:" << this->getYOB() << ", Salary:";
    out.write(_salary,sizeof(_salary));
    //out.write(reinterpret_cast<const char*>(&_salary), sizeof(long));
    out << '\n';


}
char* Personnel::readFromFile(ofstream& in)
{
    in.read
    /*
    maybe we can do something like this?
    while(!eof){
        cin>>Name>>City>>SSN>>YOB>>Salary;
        Personnel A(Name,SSN,YOB,City,Salary)
    }
    *;/
};


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
