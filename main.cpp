#include <iostream>
using namespace std;

class personnel{
    //friend ostream& operator << (ostream& a, const personnel& b){}
    //friend istream& operator >> (istream& a, const personnel& b){}
protected:
    string SSN;
    string Name;
    string city;
    string year_of_birth;
    string salary;
public:
    //constructors
    personnel(string a, string b, string c, string d, string e){
        setSSN(a);
        setName(b);
        setCity(c);
        setYear_of_birth(d);
        setSalary(e);
    }
    //destructors
    //setter
    void setSSN (string a)              {SSN = a;}
    void setName (string a)             {Name = a;}
    void setCity (string a)             {city = a;}
    void setYear_of_birth (string a)    {year_of_birth = a;}
    void setSalary (string a)           {salary = a;}
    //getter
    string getSSN ()                    {return SSN;}
    string getName ()                   {return Name;}
    string getCity ()                   {return city;}
    string getYear_of_birth ()          {return year_of_birth;}
    string getSalary ()                 {return salary;}
    
    
    
    void writeToFile();
    void readFromFile();
};


class student:public personnel{
protected:
    string major;
};



template <class T>
class database{
    //friend operator == (const personnel& b){}
private:
    int nameLen;
    int cityLen;
public:
    database();
    database(T a, T b, T c, T d, T e){
        personnel A(a,b,c,d,e);
        nameLen = b.size();
        cityLen = c.size();
    }
    void add(){
        //add it to a file, but how?
    }
    string find(){
        // find if something matches something else
        return "as";
    }
    void modify(){
        //if found, then can modify, it not, you can't
    }
    void print(){
        //i'm assuminng we use cout
    }
    void writeToFile();
    
};






int main() {
    database <student> studentfile;
    bool over = false;
    int answer;
    while (!over){
        cout<<"what would you like to do:"<<endl;
        cout<<"1: add"<<endl;
        cout<<"2: find"<<endl;
        cout<<"3: modify"<<endl;
        cout<<"4: exit"<<endl;
        cin>>answer;
        
        switch (answer) {
            case 1:
                studentfile.add();
                break;
            case 2:
                studentfile.find();
                break;
            case 3:
                studentfile.modify();
                break;
            case 4:
                over = true;
                break;
            default:
                break;
        }
    }
    return 0;
}
