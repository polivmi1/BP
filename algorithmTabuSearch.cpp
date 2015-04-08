#include "algorithmTabuSearch.h"

//********************************************************************************SOLVE
void AlgorithmTabuSearch(int runs, int tabu, int wL){
	for(int i = 0; i <= K; i++)
		for(int j = 0; j <= K; j++){
			tabuList[i][j] = tabuListR[i][j] = tabuListS[i][j] = 0;
		}
	TabuTime = 0;
	TabuSec = tabu;
	int w = 0;
	double et, bt = omp_get_wtime();
	
	int test = runs;
	while(test--){
		//BestTabuCostOpt();
		FATabuCostOpt();		
		if(BestScore - EPS > cost){
			test = runs;
			CopyBestPath();
#ifndef DEBUG
			o(BestScore);
#endif
			w = 0;
		}
		
		TabuTime++;
		w++;
		if(w > wL){
			et = omp_get_wtime();
			if(et - bt > MAX_RUNNING_TIME)
				break;
		}
	}
	
}	



