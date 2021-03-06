#ifndef _TESTS_H_
#define _TESTS_H_

#include "globals.h"
#include "load.h"
#include "commonFunctions.h"
#include "algorithmSavings.h"
#include "algorithmHillClimb.h"
#include "algorithmSimulatedAnnealing.h"
#include "algorithmTabuSearch.h"
#include "plot.h"
#include "algorithmSCHC.h"
#include "algorithmLAHC.h"

#include <omp.h>

//********************************************************************************
void Test1_ChristofidesEilon_1to5(int runs);							  	  
void Test2_ChristofidesEilon_1to5(int runs);  	  							  
void Test0(int runs);
void TestBasic(int runs);
void Test1_ChristofidesEilon_1to14(int runs);
void Test2_ChristofidesEilon_1to14(int runs);
void Test_Kelly(int runs);
void TestBestFit(int runs);
void TestAllChrist(int runs);
void TestAllKelly(int runs);
void TestPlot12Kelly(int runs);
void TestAllTaillard(int runs);
void TestPlot2Taillard(int runs);
void TestAllLi(int runs);
void FullTest_Christ(int runs);
void TabuTest_Christ(int runs);


/**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**********************************************************************Final benchmarking Tests used in Thesis*************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/


void FinalChrist(int runs, int f, int t); 
void FinalLi(int runs, int f, int t); 
void FinalUchoa(int runs, int f, int t); 
void TUchoa(int runs, int f, int t);


void FinalKelly(int runs, int f, int t); 
void FinalTaillard(int runs, int f, int t); 
void FinalUSA(int runs, int f, int t); 



//********************************************************************************


#endif
