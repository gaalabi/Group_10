#include "database.hpp"
#include <fstream>

template <class T>
int database<T>::find(char * file, string SSN_check){
    int counter = 0;
    string A;
    ifstream f;
    f.open(file);
    while (!f.eof()){
        getline(f,A);
        counter++;
        if (A[0] == SSN_check[0]){
            if (A[1] == SSN_check[1]){
                if (A[2] == SSN_check[2]){
                    if (A[3] == SSN_check[3]){
                        if (A[4] == SSN_check[4]){
                            if (A[5] == SSN_check[5]){
                                if (A[6] == SSN_check[6]){
                                    if (A[7] == SSN_check[7]){
                                        if (A[8] == SSN_check[8]){ //ie, if the 9 number matches
                                            return counter;
                                        }}}}}}}}}
    }
    return -1;
}

template <class T>
void database<T>::modify(char * file,string SSN_check, string change_item, string change_to){
    string A;
    string B;
    int counter = 0;
    int Index = find(f, SSN_check);
    
    ifstream f;
    ofstream f2;
    f.open(file);
    f2.open(file);
    while (!f.eof()){
        getline(f,A);
        counter++;
        if (counter == Index){  //if found the line of what to change, keep it in A
            if (change_item == "name"){             //if they ask to change name
                for(int i = 0; i < 11; i++){
                    A[10+i] = change_to[i];
                }
            }
            else if (change_item == "city"){    //DID NOT ACCOUNT FOR THE SPACING
                for(int i = 0; i < 11; i++){
                    A[21+i] = change_to[i];
                }
            }
            else if (change_item == "YOB"){
                for(int i = 0; i < 5; i++){
                    A[32+i] = change_to[i];
                }
            }
            else if (change_item == "Salary"){
                for(int i = 0; i < 8; i++){
                    A[37+i] = change_to[i];
                }
            }
        }
        f2<<A;  //either keep the rest of the txt the same, or change what was changed.
    }
    f2.close();
    
}

template <class T>
void database<T>::add(char * file, T stuff){
    ofstream f;
    f.open(file,ios::app);
    file<<stuff;
    f.close();
}

template <class T>
void database<T>::print(char * file){
    string A;
    ifstream f;
    f.open(file);
    while (!f.eof()){
        getline(f,A);
        cout<<A<<endl;
        A="";
    }
    
}
