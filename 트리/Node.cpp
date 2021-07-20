#include "Node.h"

node::node(int key, int num, int chek, int l_child, int r_child){
    val = key;
    no = num;
    fill = chek;
    this->l_child = l_child;
    this->r_child = r_child;
    
}

void node::set(int key, int num, int chek){
    val = key;
    no = num;
    fill = chek;
}

void node::l_set(int l_child){
    this->l_child = l_child;
}

void node::r_set(int r_child){
    this->r_child = r_child;
}
