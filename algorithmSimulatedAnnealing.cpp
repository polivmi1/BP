#include "algorithmSimulatedAnnealing.h"

//********************************************************************************SOLVE
void AlgorithmSimulatedAnnealing(double fT, double initT, double eT, int numT, int closest, int prob, int wL){
	srand (time(NULL));
	double T = initT;
	int i,j,w = 0;
	
	double et, bt = omp_get_wtime();
	
	if(closest)
		InitClosestArray(closest);
	
	
	while(T > eT){
		int times = numT;
		while(times--){
			i = (rand() % K) + 1;
			j = GetJ(i,closest,prob);	
				
			Strategy(i,j,T);
			if(BestScore - EPS > cost){
				CopyBestPath();
#ifndef DEBUG
				o(BestScore);
#endif
				w = 0;
			}			
		}
		T *= fT;
		w++;
		if(w > wL){
			et = omp_get_wtime();
			if(et - bt > MAX_RUNNING_TIME)
				break;
		}
	}
	
	cost = SolutionDistance();
		
}		

