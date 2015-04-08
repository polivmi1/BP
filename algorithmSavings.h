#ifndef _ALGORITHM_SAVINGS_H_
#define _ALGORITHM_SAVINGS_H_

#include "globals.h"
#include "commonFunctions.h"
#include "constraints.h"

#if defined MAIN
#define EXTERN
#else
#define EXTERN extern
#endif

struct save{				//structure for the savings algorithm
	int i,j;
	double cost;
    bool operator < (const save& a) const { return cost > a.cost; }	
};

EXTERN save savings[MAX_C*MAX_C_2];

//********************************************************************************
int CalculateSavings(double lambda);										  //**O((K^2)/2)
void AlgorithmSavings(double lambda = 1);									  //**O((K^2)/2 + K)
//********************************************************************************

#endif
