#ifndef _LOAD_H_
#define _LOAD_H_

#include "globals.h"

//********************************************************************************
void LoadChristofidesEilon(const string &file);								  //**
void LoadSolomon(const string &file);										  //**
void LoadAugerat(const string &file);										  //**
void LoadKelly(const string &file, double &optimal);
void LoadTaillard(const string &file, double &optimal);
void LoadLi(const string &file, double & best);

//********************************************************************************

#endif
