/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringHashTableItem.cpp
 * Author: jaymc
 * 
 * Created on June 5, 2022, 8:43 PM
 */

#include "StringHashTableItem.h"

StringHashTableItem::StringHashTableItem(const string &xKey, const string &xValue) 
        : key(xKey), value(xValue), pnext(nullptr) {}

StringHashTableItem::~StringHashTableItem()
{
	if (this->pnext)
		delete this->pnext;
}

const string &StringHashTableItem::Key() const
{
	return this->key;
}

const string &StringHashTableItem::Value() const
{
	return this->value;
}

const string &StringHashTableItem::operator=(const string &value)
{
	this->value = value;
	return value;
}

const char *StringHashTableItem::operator=(const char *value)
{
	this->value = value;
	return value;
}

