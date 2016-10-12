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
    void update_info(string name, string category);
};

#endif // DVD_H
