#include "algorithmSCHC.h"

void AlgorithmSCHC(int pL, int wL, int closest, int prob){
	
	if(closest)
		InitClosestArray(closest);
	
	double B = cost;
	int n = 0, w = 0;
	
	int restarted = 1;
	
	int L = pL;
			
	double et, bt = omp_get_wtime();
	while(1){
		if(RandomSCHC(B,closest,prob)){
			n++;
			if(BestScore - EPS > cost){
				CopyBestPath();
				w = 0;
				restarted = 1;
#ifndef DEBUG
				o(BestScore);
#endif
			}
		}
		else w++;
		
		if(w > wL){
			
			B = B + restarted*(rand()%(int)sqrt(cost));
			CopyRevBestPath();
			restarted++;
			w = 0;
			L = pL*10;
			et = omp_get_wtime();
			if(et - bt > MAX_RUNNING_TIME)
				break;
			if(restarted > 10)
				break;
		}
		
		if(n > L){
			B = cost;
			n = 0;
		}
	}
}




bool RandomSCHC(double B, int closest, int prob){
	double bcost = -INF;
	double tcost;
	int alg = -1;
	int a,b;
	
	
	bool found = false;
	
	int i = (rand()%K)+1;
	
	int j = GetJ(i,closest,prob);	
			
		
	if(path[i].route == path[j].route){
		if(!CReverseEdge(i,j) && !(path[i].next == j || path[path[i].next].next == j || path[path[j].next].next == i || path[j].next == i)){
			tcost = CostReverseEdge(i,j);
			if(cost - tcost < B || cost - tcost < cost || (cost - tcost -EPS < cost && cost - tcost +EPS > cost)){
				bcost = tcost;
				alg = 1;
				a=i;b=j;
				found = true;
			}
		}
		else{
			tcost = CostInSwapOpt(i,j);
			if((cost - tcost < B || cost - tcost < cost || (cost - tcost -EPS < cost && cost - tcost +EPS > cost)) && !CInSwap(i, tcost)){
				bcost = tcost;
				alg = 0;
				a=i;b=j;
				found = true;
			}
		}
	}
	else{
		tcost = CostBetweenDeleteAndInsert(i,j);
		if((cost - tcost < B || cost - tcost < cost || (cost - tcost -EPS < cost && cost - tcost +EPS > cost))){
			bcost = tcost;
			alg = 2;
			a=i;b=j;
			found = true;
		}
		else if(!CBetweenSwap(i, j)){
			tcost = CostBetweenSwap(i,j);
			if(cost - tcost < B || cost - tcost < cost || (cost - tcost -EPS < cost && cost - tcost +EPS > cost)){
				bcost = tcost;
				alg = 3;
				a=i;b=j;
				found = true;
			}
		}
	}
	//if(alg != -1)o(B);o(bcost);//o(a);o(b);o(alg);//o(B);o((cost - tcost < B || cost - tcost < cost || (cost - tcost -EPS < cost && cost - tcost +EPS > cost)));}
	
	switch(alg){
		case -1:return false;
		case 0:InSwapOpt(0,a,b,true);
			break;
		case 1:ReverseEdge(0,a,b,true);
			break;
		case 2:BetweenDeleteAndInsert(0,a,b,true);
			break;
		case 3:BetweenSwap(0,a,b,true);
			break;
	}
	
	return true;
}
