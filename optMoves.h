#ifndef _OPT_MOVES_H_
#define _OPT_MOVES_H_

#include "globals.h"
#include "constraints.h"
#include "commonFunctions.h"
#include "optCost.h"
//********************************************************************************

bool Feasable(double gain, double T);										  //**O(1)
void ReverseEdge(double T, int i, int j, bool pass = false);	
void InRouteOpt(double T, int i, int j);
void InSwapOpt(double T, int i, int j, bool pass = false);
void BetweenRoutesOpt(double T, int i, int j);
void BetweenSwap(double T, int i, int j, bool pass = false);
void BetweenDeleteAndInsert(double T, int i, int j, bool pass = false);
void InSwapNeighbour(int i, int j);
void InSwap(int i, int j);			 				  //**O(1)

void Between2DeleteAndInsert(double T, int i, int j, bool pass = false);


//********************************************************************************

#endif

