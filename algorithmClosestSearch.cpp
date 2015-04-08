#include "algorithmClosestSearch.h"

//********************************************************************************SOLVE
void AlgorithmClosestSearch(double fT, double initT, double eT, int numT, int wL, int closest, int prob){

	int w = 0;
	
	if(closest)
		InitClosestArray(closest);
	
	srand (time(NULL));
	double T = initT, et, bt = omp_get_wtime();
	int i,j,times;
	while(T > eT){
		times = numT;
		double tcost = cost;
		while(times--){
			i = (rand() % K) + 1;
			j = GetJ(i,closest,prob);	
				
			Strategy(i,j,T);
			if(BestScore - EPS > cost){
				CopyBestPath();
#ifdef DEBUG
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
	cout << "BEST solution found: " << BestScore << "  vs  " << cost << endl;
	
}		
