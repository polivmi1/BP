#ifndef _CONSTRAINTS_H_
#define _CONSTRAINTS_H_

#include "globals.h"

//********************************************************************************
bool CReverseEdge(int from, int to);	
bool CSavings(int from, int to, double tlength);
bool CInSwap(int from, double score);
bool CBetweenSwap(int from, int to);	
bool CDeleteAndInsert(int from, int to);

//********************************************************************************

#endif
