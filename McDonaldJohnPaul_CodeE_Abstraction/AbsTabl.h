/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbsTabl.h
 * Author: jaymc
 *
 * Created on March 30, 2022, 7:38 PM
 */

#ifndef ABSTABL_H
#define ABSTABL_H

#include "RowArray.h"

class AbsTabl{
    protected:
        int szRow;
        int szCol;
        RowAray **columns;
    public:
        virtual int getSzRow()const = 0;
        virtual int getSzCol()const = 0;
        virtual int getData(int,int)const = 0;
};


#endif /* ABSTABL_H */

