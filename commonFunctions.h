#ifndef _COMMON_FUNCTIONS_H_
#define _COMMON_FUNCTIONS_H_

#include "globals.h"
#include "constraints.h"
#include "optMoves.h"

//********************************************************************************
void ComputeDistance();														  //O((K^2)/2)
double SolutionDistance();													  //O(K)
void PrintSolution();														  //O(K)
void Strategy(int i, int j, double T = 0);				 						  //O(50)
void ChangeRouteNumber(int from, int num);									  //O(K)
void PrintBestSolution();
void CopyBestPath();	
void CopyRevBestPath();	
double BestSolutionDistance();
void InitClosestArray(int max_closest);
int GetJ(int i, int closest, int prob);
//********************************************************************************


#endif
