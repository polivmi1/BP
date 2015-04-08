#include "optCostFA.h"


//********************************************************************************
void FATabuCostOpt(){
	double bcost = INF;
	double tcost = INF;
	int alg = -1;
	int a = -1;
	int b = -1;
	
	double oldCost = cost;
	
	
	int after = 0;
	int iafter = 0;
	int jafter = 0;
	
	bool through = false;
	int tiafter = 0;
	int tjafter = 0;
	int dtiafter = 0;
	int dtjafter = 0;
	double ticost = 0.0;
	double tjcost = 0.0;
	int pa,pb;
	if(!through){
		//insert i to the best place in route j
		for(int i = 1; i <= K; i++){
			if(through)
				break;
			double olcost = tcost = cost;
			int pi = path[i].route;
			int previ = path[i].prev;
			CDelete(i,dtiafter);		//delete i and in dtiafter save a place after which was i
			tcost -= cost;
			for(int j = 1; j <= K; j++){
				if(routeStart[j] == 0)
					continue;
				int add = d[i];
				if(j == pi)
					add = 0;
				if((routeDemand[j] + add <= Q)){
					int pj = j;
					if(CTryInsert(i, pj, tiafter, ticost)){
						if((tiafter == previ) && (j == pi)){
							continue;
							}
						if(- tcost + ticost < bcost - EPS){
							if((!isTabu(i,j) && !isTabu(i,pi)) || (olcost - tcost + ticost < BestScore - EPS)){
								bcost = - tcost + ticost;
								alg = 0;
								a=i;b=j;
								pa = pi;
								pb = pj;
								iafter = tiafter;
								if(bcost < 0){
									through = true;
									break;
								}
							}
						}
					}
				}
			}
			CInsert(i, pi, dtiafter);
		}
	}
	
	if(!through){
		//delete i and j and insert in opposite route
		for(int i = 1; i <= K; i++){
			if(through)
				break;
			for(int j = 1; j <= K; j++){
				if(path[i].route != path[j].route){
					if((routeDemand[path[i].route] + d[j] - d[i] <= Q) && (routeDemand[path[j].route] + d[i] - d[j] <= Q)){
					
						tcost = cost;
						double olcost = cost;
						int pi = path[i].route;
						int pj = path[j].route;
						
						CDelete(i,dtiafter);		//delete i and in dtiafter save a place after which was i
						CDelete(j,dtjafter);
						tcost -= cost;				//saved cost after deleting
						if(CTryInsert(i, pj, tiafter, ticost) && CTryInsert(j, pi, tjafter, tjcost)){
							if(- tcost + ticost + tjcost < bcost - EPS){
								if((!isTabu(i,path[j].route) && !isTabu(j,path[i].route) && !isTabu(i,path[i].route) && !isTabu(j,path[j].route)) || (olcost - tcost + ticost + tjcost < BestScore - EPS)){
									bcost = - tcost + ticost + tjcost;
									alg = 1;
									a=i;b=j;
									pa = pi;
									pb = pj;
									iafter = tiafter;
									jafter = tjafter;
									if(bcost < 0){
										through = true;
										CInsert(i, pi, dtiafter);
										CInsert(j, pj, dtjafter);
										break;
									}
								}
							}
						}
						CInsert(i, pi, dtiafter);
						CInsert(j, pj, dtjafter);
					}
				}
			}
		}
	}
	
	/*
	if(!through){
		//2opt
		for(int i = 1; i <= K; i++){
			if(through)
				break;
			for(int j = i+1; j <= K; j++){
				if((path[i].route == path[j].route) && !(path[i].next == j) && !(path[j].next == i)){
					tcost = -1.0 * CostReverseEdge(i,j);
					if(!(tcost + EPS > 0 && tcost - EPS < 0) && (tcost < bcost - EPS) && !CReverseEdge(i,j)){
						if((!isTabuR(j,path[j].route) && !isTabuR(i,path[i].route)) || (cost + tcost < BestScore - EPS)){
							bcost = tcost;
							alg = 4;
							a=i;b=j;
							if(bcost < 0){
								through = true;
								break;
							}
						}
					}
				}
			}
		}
	}*/
	
	int tafter = 0;
		/*
	if(!through){
		
		//insert i to the best place in route OLD VERSION
		for(int i = 1; i <= K; i++){
			if(through)
				break;
			for(int j = 1; j <= K; j++){
				if(routeStart[j] == 0)
					continue;
				if(path[i].route != j){
					if(CTabuDeleteAndInsert(i, j, tafter, tcost)){
						if(- tcost < bcost - EPS){
							if((!isTabu(i,j) && !isTabu(i,path[i].route)) || (cost - tcost < BestScore - EPS)){
								bcost = -tcost;
								alg = 0;
								a=i;b=j;
								after = tafter;
								if(bcost < 0){
									through = true;
									break;
								}
							}
						}
					}
				}
			}
		}
	}
		*/

	/*
	if(!through){
		
		//swap two nodes
		for(int i = 1; i <= K; i++){
			if(through)
				break;
			for(int j = i + 1; j <= K; j++){
				if(path[i].route == path[j].route){
					tcost = -1.0 * CostInSwapOpt(i,j);
					if((tcost < bcost - EPS) && !CInSwap(i,-tcost)){
						if(!isTabuR(i,j) || (cost + tcost < BestScore - EPS)){
							bcost = tcost;
							alg = 2;
							a=i;b=j;
							if(bcost < 0){
								through = true;
								break;
							}
						}
					}
				}
				else{
					tcost = -1.0 * CostBetweenSwap(i,j);
					if((tcost < bcost - EPS) && !CBetweenSwap(i,j)){
						if((!isTabuS(i,path[j].route) && !isTabuS(j,path[i].route) && !isTabuS(i,path[i].route) && !isTabuS(j,path[j].route)) || (cost + tcost < BestScore - EPS)){
							bcost = tcost;
							alg = 3;
							a=i;b=j;
							if(bcost < 0){
								through = true;
								break;
							}
						}
					}
				}
			}
		}
		
	}*/
	
	
	
	
	
	
	
	//o(alg);
	//o(bcost);

	if(alg == -1){
		cout << "NO POSSIBLE MOVE" << endl;
	}

//o(after);

	int null;
	switch(alg){
		case 0:
			tabuList[a][pb] = TabuTime + TabuSec + (rand()%5);
			tabuList[a][pa] = TabuTime + TabuSec + (rand()%5);
			CDelete(a,null);
			CInsert(a, b, iafter);
			break;
		case 1:
			tabuList[a][pb] = TabuTime + TabuSec + (rand()%5);
			tabuList[b][pa] = TabuTime + TabuSec + (rand()%5);
			tabuList[a][pa] = TabuTime + TabuSec + (rand()%5);
			tabuList[b][pb] = TabuTime + TabuSec + (rand()%5);
			CDelete(a,null);
			CDelete(b,null);
			CInsert(a, pb, iafter);
			CInsert(b, pa, jafter);
			break;
		case 2:
			tabuListR[a][b] = TabuTime + TabuSec + (rand()%5);
			tabuListR[b][a] = TabuTime + TabuSec + (rand()%5);
			InSwapOpt(0,a,b,true);
			break;
		case 3:
			tabuListS[a][path[b].route] = TabuTime + TabuSec + (rand()%5);
			tabuListS[b][path[a].route] = TabuTime + TabuSec + (rand()%5);
			tabuListS[a][path[a].route] = TabuTime + TabuSec + (rand()%5);
			tabuListS[b][path[b].route] = TabuTime + TabuSec + (rand()%5);
			BetweenSwap(0,a,b,true);
			BestSolutionDistance();
			break;
		case 4:
			tabuListR[a][path[b].route] = TabuTime + TabuSec + (rand()%5);
			tabuListR[b][path[a].route] = TabuTime + TabuSec + (rand()%5);
			ReverseEdge(0,a,b,true);
			break;
			
	}
	
}

