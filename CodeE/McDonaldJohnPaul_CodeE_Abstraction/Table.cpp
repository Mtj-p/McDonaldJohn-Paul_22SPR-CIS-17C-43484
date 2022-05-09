/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Table.h"

Table::Table(unsigned int rows,unsigned int cols){
    szRow=rows;
    szCol=cols;
    columns=new RowAray*[cols];
    for(int col=0;col<cols;col++){
        columns[col]=new RowAray(rows);
    }
}

Table::Table(const Table &a){
    //Student to supply
    szRow=a.szRow;
    szCol=a.szCol;
    columns=a.columns;
}

Table::~Table(){
    //Student to supply
    for(int i=0;i<szCol;i++){
        delete columns[i];
    }
    delete [] columns;
}

int Table::getData(int row,int col)const{
    //Student to supply
    return columns[col]->getData(row);
}

void Table::setData(int row,int col,int val){
    //Student to supply
    columns[col]->setData(row,val);
}