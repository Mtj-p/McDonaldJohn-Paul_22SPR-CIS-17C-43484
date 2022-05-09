/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbsRow.h
 * Author: jaymc
 *
 * Created on March 30, 2022, 7:36 PM
 */

#ifndef ABSROW_H
#define ABSROW_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

class AbsRow{
    protected:
        int size;
        int *rowData;
    public:
        virtual int getSize()const = 0;
        virtual int getData(int)const = 0;
};

#endif /* ABSROW_H */

