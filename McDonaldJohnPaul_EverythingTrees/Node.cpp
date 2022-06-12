/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: jaymc
 * 
 * Created on June 1, 2022, 10:41 PM
 */

#include "Node.h"

Node::Node(int data, Node *left, Node *right){
    Value = data;
    this->Left=left;
    this->Right=right;
}

