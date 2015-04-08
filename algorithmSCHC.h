#ifndef _ALGORITHM_SCHC_H_
#define _ALGORITHM_SCHC_H_

#include "globals.h"
#include "commonFunctions.h"
#include "constraints.h"
#include <omp.h>

//********************************************************************************
void AlgorithmSCHC(int pL, int wL, int closest = 0, int prob = 100);									  
bool RandomSCHC(double B, int closest, int prob);
//********************************************************************************

#endif
