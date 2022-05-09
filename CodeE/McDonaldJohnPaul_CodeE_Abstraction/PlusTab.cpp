/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PlusTab.h"

PlusTab PlusTab::operator+(const PlusTab &a){
    //Student to supply
    PlusTab b(this->szRow,this->szCol);
    for(int i=0;i<this->szRow;i++){
        for(int j=0;j<this->szCol;j++){
            b.columns[j]->setData(i,this->getData(i,j) + a.getData(i,j));
        }
    }    
    return b;
}