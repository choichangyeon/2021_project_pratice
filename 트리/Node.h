#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>

class node
{   
public:
    node(int key = 0, int num = 0, int chek = 0, int l_child = 0, int r_child = 0);

    void set(int key, int num, int chek);
    void l_set(int l_child);
    void r_set(int r_chlid);

public:
    int val, no;
    int fill;
    int l_child, r_child;
};

#endif
