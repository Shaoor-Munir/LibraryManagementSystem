#ifndef DVD_H
#define DVD_H


#include<iostream>
#include<vector>
#include<string>
#include"LibItem.h"

using namespace std;

class DVD : public LibItem {
    string category;

public:
    DVD(int id = 0, string name = "", string genre = "");
    string get_category();
    string return_type();
};

#endif // DVD_H
