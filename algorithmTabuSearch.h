#ifndef _TABU_SEARCH_H_
#define _TABU_SEARCH_H_

#include "globals.h"
#include "constraints.h"
#include "commonFunctions.h"
#include "optCost.h"
#include "optCostFA.h"
#include "algorithmSimulatedAnnealing.h"
#include <omp.h>

//#include <Windows.h>

//*****************************************************************************************
void AlgorithmTabuSearch(int runs = 500, int tabu = 10, int wL = 500);//**O(?)
//void OptimizeRoutes(int i, int j);
//void OptimizeRoute(int i);
//*****************************************************************************************

#endif
