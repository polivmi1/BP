#ifndef _SIMULATED_ANNEALING_H_
#define _SIMULATED_ANNEALING_H_

#include "globals.h"
#include "constraints.h"
#include "commonFunctions.h"
#include "algorithmTabuSearch.h"
#include "optCost.h"
#include <omp.h>



//*****************************************************************************************
void AlgorithmSimulatedAnnealing(double fT, double initT, double eT, int numT = 100, int closest = 0, int prob = 100, int wL = 10000000);//**O(?)
//*****************************************************************************************

#endif
