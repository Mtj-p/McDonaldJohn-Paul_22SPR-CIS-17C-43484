/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: jaymc
 *
 * Created on June 1, 2022, 10:41 PM
 */

#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node(int data, Node *left = nullptr, Node *right = nullptr);
    
    int Value;
    Node *Left;
    Node *Right;

};

#endif /* NODE_H */

