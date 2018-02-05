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
using namespace std;

template <class T>
class database{
private:
    char* f;
    T rec;
    string stored_Data;
public:
    int find(char * file, string SSN_check);
    void modify(char * file,string SSN_check, string change_item, string change_to);
    void add(char * file, T stuff);
    void print(char * file);
};
#endif /* database_hpp */
