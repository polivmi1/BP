#include "algorithmLAHC.h"

void AlgorithmLAHC(int pL, int wL, int closest, int prob){
	
	if(closest)
		InitClosestArray(closest);
	
	int n = 0, w = 0;
	
	lastCosts = new double[pL];
	for(int i = 0; i<pL; i++){
		lastCosts[i] = cost;
	}
			
	int restarted = 1;
	
	double et, bt = omp_get_wtime();
	while(1){
		if(RandomSCHC(lastCosts[n%pL],closest,prob)){
			if(BestScore - EPS > cost){
				CopyBestPath();
#ifndef DEBUG
				o(BestScore);
#endif
				restarted = 1;
				w = 0;
			}
		}
		else w++;
		
		lastCosts[n%pL] = cost;
		
		if(w > wL){
			for(int i = 0; i<pL; i++){
				lastCosts[i] = lastCosts[i] + restarted*(rand()%(int)sqrt(cost));
			}
			CopyRevBestPath();
			restarted++;
			w = 0;
			et = omp_get_wtime();
			if(et - bt > MAX_RUNNING_TIME)
				break;
			if(restarted > 10)
				break;
		}
		
		n++;
	}
	
	delete lastCosts;
}
