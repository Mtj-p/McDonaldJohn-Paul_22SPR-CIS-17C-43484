/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.cpp
 * Author: jaymc
 * 
 * Created on June 1, 2022, 10:14 PM
 */

#include "Tree.h"
#include <ostream>

using namespace std;

Tree::Tree(){
    root=nullptr;
}

Tree::~Tree(){
    clear();
}


void Tree::clear(){
    deleten(root);
    root=nullptr;
}
void Tree::deleten(Node *nod){
    if(nod!=nullptr){
        deleten(nod->Left);
        deleten(nod->Right);
        delete nod;
    }
}


/* erase function from */
//https://programming-techniques.com/2011/11/binary-tree-implementation-on-c-algorithm-and-source-code.html

void Tree::erase(int value){
    Node *temp = root, *parent = root, *marker;
    if(temp==NULL){
        throw std::exception();
    }
    else{
        while(temp!= NULL && temp -> Value != value){
            parent = temp;
            if (temp->Value <value){
                temp = temp->Right;
            }
            else{
                temp = temp->Left;
            }
        }
    }
    marker = temp;
    if(temp==NULL){
        
    }
    else if(temp == root){
        if(temp->Right == NULL && temp->Left == NULL){
            root=NULL;
        }
        else if (temp->Left == NULL){
            root=temp->Right;
        }
        else if (temp->Right == NULL){
            root=temp->Left;
        }
        else{
            Node *temp1;
            temp1=temp->Right;
            while(temp1->Left != NULL){
                temp = temp1;
                temp1 = temp1->Left;
            }
            if(temp1 != temp->Right){
                temp->Left = temp1->Right;
                temp1->Right = root->Right;
            }
            temp1->Left = root->Left;
            root=temp1;
        }
    }
    else {
        if(temp->Right == NULL && temp->Left == NULL){
            if(parent->Right == temp){
                parent->Right = NULL;
            }
            else{
                parent->Left = NULL;
            }
        }
        else if(temp->Left == NULL){
            if(parent -> Right == temp){
                parent->Right = temp->Right;
            }
            else{
                parent->Left = temp->Right;
            }
        }
        else if(temp->Right == NULL){
            if(parent->Right == temp){
                parent->Right = temp->Left;
            }
            else{
                parent->Left=temp->Left;
            }
        }
        else{
            Node *temp1;
            parent = temp;
            temp1 = temp->Right;
            while(temp1->Left != NULL){
                parent = temp1;
                temp1 = temp1->Left;
            }
            if(temp1 != temp->Right){
                temp->Left = temp1->Right;
                temp1->Right = parent->Right;
            }
            temp1->Left = parent->Left;
            parent = temp1;
        }
    }
    delete marker;
}

void Tree::insert(int value){
    if(root==nullptr){
        root = new Node(value);
    }
    else{
        Node *Current = root;
        while(true){
            if(value < Current->Value){
                if(Current->Left == nullptr){
                    Current->Left = new Node(value);
                    break;
                }
                else{
                    Current = Current->Left;
                }
            }
            else if (value > Current->Value){
                if(Current->Right == nullptr){
                    Current->Right = new Node(value);
                    break;
                }
                else{
                    Current = Current->Right;
                }
            }
            else{
                break;
            }
        }
    }
}

void Tree::printback(){
    Tree::backprint(root);
}

std::ostream& operator<<(std::ostream& ostr, const Tree& rhs){
    return rhs.Print(ostr, rhs.root);
}

std::ostream& Tree::Print(std::ostream& ostr, Node *rhs) const{
    if(rhs != nullptr){
        Print(ostr,rhs->Left);
        std::cout<< " " << rhs->Value;
        Print(ostr, rhs->Right);
    }
    return ostr;
}

Node *Tree::backprint(Node *cur){
    if(cur!=nullptr){
        backprint(cur->Right);
        std::cout<<" "<<cur->Value;
        backprint(cur->Left);
    }
    return cur;
}