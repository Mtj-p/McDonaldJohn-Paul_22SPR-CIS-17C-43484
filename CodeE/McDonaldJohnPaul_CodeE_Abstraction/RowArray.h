/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RowArray.h
 * Author: jaymc
 *
 * Created on March 30, 2022, 7:37 PM
 */

#ifndef ROWARRAY_H
#define ROWARRAY_H

#include "AbsRow.h"

class RowAray:public AbsRow{
    public:
        RowAray(unsigned int);
        virtual ~RowAray();
        int mrkRand(int);
        int getSize()const{return size;}
        int getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,int);
};

#endif /* ROWARRAY_H */

