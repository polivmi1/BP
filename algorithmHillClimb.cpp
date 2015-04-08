#include "algorithmHillClimb.h"

//********************************************************************************SOLVE
void AlgorithmHillClimb(){

	while(1){
		BestCostOpt();
		if(BestScore - EPS > cost){
			CopyBestPath();
#ifndef DEBUG
			o(BestScore);
#endif
		}
		else
			break;
	}
	
	cost = SolutionDistance();
}		
