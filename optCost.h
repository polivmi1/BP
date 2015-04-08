#ifndef _OPT_COST_H_
#define _OPT_COST_H_

#include "globals.h"
#include "constraints.h"
#include "optMoves.h"
#include "plot.h"


//********************************************************************************
double CostReverseEdge(int i, int j);
double CostInSwapOpt(int i, int j);
double CostBetweenSwap(int i, int j);
double CostBetweenDeleteAndInsert(int i, int j);
void BestCostOpt();
void BestTabuCostOpt();

bool isTabu(int i, int route);
bool isTabuS(int i, int route);
bool isTabuR(int i, int j);

bool CTabuDeleteAndInsert(int i, int route, int&after, double& tcost);

bool CTryInsert(int i, int route, int&after, double& tcost);
void CDelete(int i, int&after);
void CInsert(int i, int route, int after);
//********************************************************************************

#endif

