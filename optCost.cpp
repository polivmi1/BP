#include "optCost.h"

bool isTabu(int i, int route){
	return tabuList[i][route] - TabuTime > 0;
}

bool isTabuR(int i, int j){
	return tabuListR[i][j] - TabuTime > 0;
}

bool isTabuS(int i, int route){
	return tabuListS[i][route] - TabuTime > 0;
}

//********************************************************************************
void BestTabuCostOpt(){
	double bcost = INF;
	double tcost = INF;
	int alg = -1;
	int a = -1;
	int b = -1;
	
	double oldCost = cost;
	
	
	int after = 0;
	int iafter = 0;
	int jafter = 0;
	
	
	//2opt
	for(int i = 1; i <= K; i++){
		for(int j = i+1; j <= K; j++){
			if((path[i].route == path[j].route) && !(path[i].next == j) && !(path[j].next == i)){
				tcost = -1.0 * CostReverseEdge(i,j);
				if(!(tcost + EPS > 0 && tcost - EPS < 0) && (tcost < bcost - EPS) && !CReverseEdge(i,j)){
					if((!isTabuR(j,path[j].route) && !isTabuR(i,path[i].route)) || (cost + tcost < BestScore - EPS)){
						bcost = tcost;
						alg = 4;
						a=i;b=j;
					}
				}
			}
		}
	}
	
	
	int tafter = 0;
	
	/*
	//insert i to the best place in route OLD VERSION
	for(int i = 1; i <= K; i++){
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
						}
					}
				}
			}
		}
	}
	*/

	/*
	//swap two nodes
	for(int i = 1; i <= K; i++){
		for(int j = i + 1; j <= K; j++){
			if(path[i].route == path[j].route){
				tcost = -1.0 * CostInSwapOpt(i,j);
				if((tcost < bcost - EPS) && !CInSwap(i,-tcost)){
					if(!isTabuR(i,j) || (cost + tcost < BestScore - EPS)){
						bcost = tcost;
						alg = 2;
						a=i;b=j;
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
					}
				}
			}
		}
	}
	*/
	
	//delete i and j and insert in opposite route
	int tiafter = 0;
	int tjafter = 0;
	int dtiafter = 0;
	int dtjafter = 0;
	double ticost = 0.0;
	double tjcost = 0.0;
	
	int pa,pb;
	
	for(int i = 1; i <= K; i++){
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
							}
						}
					}
					CInsert(i, pi, dtiafter);
					CInsert(j, pj, dtjafter);
				}
			}
		}
	}
	
	
	//insert i to the best place in route j
	for(int i = 1; i <= K; i++){
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
						}
					}
				}
			}
		}
		CInsert(i, pi, dtiafter);
	}
	//o(alg);o(bcost);

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

// insert i into route j without deleting	
bool CTryInsert(int i, int route, int&after, double& tcost){//tcost is - old + new
	int beg = routeStart[route];
	double diff = dist[0][beg] - dist[0][i] - dist[i][beg];
	
	after = 0;
	
	while(beg != 0){
		if(diff < dist[beg][path[beg].next] - dist[beg][i] - dist[i][path[beg].next]){
			diff = dist[beg][path[beg].next] - dist[beg][i] - dist[i][path[beg].next];
			after = beg;
		}
		beg = path[beg].next;
	}
	
	if(routeTime[route] + DT - diff > MRT)
		return false;
	
	tcost = - diff;				
	return true;
}	


// Delete i from its route and remember where it was	
void CDelete(int i, int&after){
	
	double tcost = dist[path[i].prev][path[i].next] - dist[path[i].prev][i] - dist[i][path[i].next];
	
	after = path[i].prev;
	
	path[path[i].prev].next = path[i].next;
	path[path[i].next].prev = path[i].prev;
	
	routeDemand[path[i].route] -= d[i];
		
	routeLength[path[i].route] += dist[path[i].prev][path[i].next] - dist[path[i].prev][i] - dist[i][path[i].next];
	routeTime[path[i].route] += dist[path[i].prev][path[i].next] - dist[path[i].prev][i] - dist[i][path[i].next] - DT;  
	
	if(path[i].prev == 0){
		routeStart[path[i].route] = path[i].next;
	}
	
	cost += tcost;
}	

// Add i to its route
void CInsert(int i, int route, int after){
	
	routeDemand[route] += d[i];
		
	if(after == 0){
		routeLength[route] += dist[0][i] + dist[i][routeStart[route]] - dist[0][routeStart[route]];					
		routeTime[route] += DT - dist[0][routeStart[route]] + dist[0][i] + dist[i][routeStart[route]];
	}
	else{
		routeLength[route] += dist[after][i] + dist[i][path[after].next] - dist[after][path[after].next];
		routeTime[route] += DT - dist[after][path[after].next] + dist[after][i] + dist[i][path[after].next];
	}	
	
	path[i].route = route;
	
	if(after == 0){
		path[i].next = routeStart[route];
		routeStart[route] = i;
	}
	else
		path[i].next = path[after].next;
	
	path[i].prev = after;
	path[after].next = i;//cant hurt if after == 0 
	path[path[i].next].prev = i;
					
	double tcost = dist[path[i].prev][i] + dist[i][path[i].next] - dist[path[i].prev][path[i].next];
			
	cost += tcost;	
}	

// insert i into route j	
bool CTabuDeleteAndInsert(int i, int route, int&after, double& tcost){//old - new
	int beg = routeStart[route];
	double diff = dist[0][beg] - dist[0][i] - dist[i][beg];
	
	after = 0;
	
	if(routeDemand[route] + d[i] > Q)
		return false;
	
	while(beg != 0){
		if(diff < dist[beg][path[beg].next] - dist[beg][i]- dist[i][path[beg].next]){
			diff = dist[beg][path[beg].next] - dist[beg][i]- dist[i][path[beg].next];
			after = beg;
		}
		beg = path[beg].next;
	}
	
	if(routeTime[route] + DT - diff > MRT)
		return false;
	
	tcost = dist[path[i].prev][i] + dist[i][path[i].next] - dist[path[i].prev][path[i].next] + diff;				
	return true;
}	


//********************************************************************************
void BestCostOpt(){
	double bcost = -INF;
	double tcost;
	int alg = 0;
	int a,b;

	for(int i = 1; i <= K; i++){
		for(int j = i + 1; j <= K; j++){
			if(path[i].route == path[j].route){
				tcost = CostInSwapOpt(i,j);
				if(tcost - EPS > bcost && !CInSwap(i, tcost)){
					bcost = tcost;
					alg = 0;
					a=i;b=j;
				}
				tcost = CostReverseEdge(i,j);
				if(tcost - EPS > bcost && !CReverseEdge(i,j)){
					bcost = tcost;
					alg = 1;
					a=i;b=j;
				}
			}
			else{
				tcost = CostBetweenDeleteAndInsert(i,j);
				if(tcost - EPS > bcost){
					bcost = tcost;
					alg = 2;
					a=i;b=j;
				}
				tcost = CostBetweenSwap(i,j);
				if(tcost - EPS > bcost && !CBetweenSwap(i, j)){
					bcost = tcost;
					alg = 3;
					a=i;b=j;
				}
			}
		}
	}
	
	switch(alg){
		case 0:InSwapOpt(0,a,b);
			break;
		case 1:ReverseEdge(0,a,b);
			break;
		case 2:BetweenDeleteAndInsert(0,a,b);
			break;
		case 3:BetweenSwap(0,a,b);
			break;
	}
}
	

//********************************************************************************

double CostReverseEdge(int i, int j){
	//check if i is before j, otherwise change
	int t = path[i].next;
	bool bef = true;
	while(!(t == j)){
		if(t == 0){
			bef = false;
			break;	
		}
		t = path[t].next;	
	}
	if(!bef){
		t = i;
		i = j;
		j = t;	
	}
				
	return dist[path[i].prev][i] + dist[j][path[j].next] - dist[path[i].prev][j] - dist[i][path[j].next];	
}
	
//********************************************************************************
	
double CostInSwapOpt(int i, int j){
	double oldS = dist[path[i].prev][i] + dist[i][path[i].next] + dist[path[j].prev][j] + dist[j][path[j].next];
	double newS;
	
	//Check if they are neighbours
	if(path[i].next == j)
		newS = dist[path[i].prev][j] + dist[i][j]*2.0 + dist[i][path[j].next];
	else if(path[j].next == i)
		newS = dist[path[j].prev][i] + dist[i][j]*2.0 + dist[j][path[i].next];
	else
		newS = dist[path[i].prev][j] + dist[j][path[i].next] + dist[path[j].prev][i] + dist[i][path[j].next];
		
	return oldS - newS;
}

//********************************************************************************
double CostBetweenSwap(int i, int j){

	
		
	double oldS = dist[path[i].prev][i] + dist[i][path[i].next] + dist[path[j].prev][j] + dist[j][path[j].next];
	double newS = dist[path[i].prev][j] + dist[j][path[i].next] + dist[path[j].prev][i] + dist[i][path[j].next];
		
	return oldS - newS;	
}

// insert i after j	
double CostBetweenDeleteAndInsert(int i, int j){

	if(CDeleteAndInsert(i,j))
		return - INF;
				
	return dist[path[i].prev][i] + dist[i][path[i].next] + dist[j][path[j].next] - dist[j][i] - dist[path[i].prev][path[i].next] - dist[i][path[j].next];
}		

