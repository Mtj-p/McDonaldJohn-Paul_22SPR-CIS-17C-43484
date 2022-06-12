/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: jaymc
 *
 * Created on June 1, 2022, 10:14 PM
 */

#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <ostream>
#include <iostream>

using namespace std;

class Tree {

public:
    Tree();
    ~Tree();
    void insert(int value);
    void erase(int value);
    void clear();
    void printback();
    friend std::ostream& operator<<(std::ostream& ostr, const Tree& rhs);
    
    
private:
    Node *root;
    std::ostream& Print(std::ostream& ostr, Node *rhs) const;
    void deleten(Node *);
    Node *backprint(Node *);
};

#endif /* TREE_H */

