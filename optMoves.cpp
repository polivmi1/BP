#include "optMoves.h"

//********************************************************************************
void InRouteOpt(double T, int i, int j){
	int r = rand() % 2;
	if(path[i].next == j || path[j].next == i)
		r = 0;
	switch(r){
		case 0:InSwapOpt(T,i,j);
			break;
		case 1:ReverseEdge(T,i,j);
			break;
	}
}

//********************************************************************************

void ReverseEdge(double T, int i, int j, bool pass){
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
	
	if(CReverseEdge(i,j))
		return;
			
	double score = dist[path[i].prev][i] + dist[j][path[j].next] - dist[path[i].prev][j] - dist[i][path[j].next];
	
	if(!(score - EPS > 0 || (T && Feasable(score, T)) || pass))
		return;

	routeLength[path[i].route] -= score;
	routeTime[path[i].route] -= score;
	
	if(path[j].prev == 0){
		routeStart[path[j].route] = i;
	}
	else if(path[i].prev == 0){
		routeStart[path[j].route] = j;
	}
	
	
	int a = i;
	int b = path[i].next;
	int c = path[b].next;

	while(1){
		path[b].next = a;
		path[b].prev = c;
					
		if(c == j)
			break;
			
		a = b;
		b = c;
		c = path[c].next;
	}
	
	int in = path[i].next;
	int ip = path[i].prev;
	
		
	path[i].prev = in;
	path[i].next = path[j].next;
	path[path[i].next].prev = i;
		
	path[j].prev = ip;
	path[j].next = b;
	path[path[j].prev].next = j;
	
	
	cost -= score;
	USED[1]++;
		
}
	
//********************************************************************************
	
void InSwapOpt(double T, int i, int j, bool pass){
	double oldS = dist[path[i].prev][i] + dist[i][path[i].next] + dist[path[j].prev][j] + dist[j][path[j].next];
	double newS;
	
	//Check if they are neighbours
	if(path[i].next == j)
		newS = dist[path[i].prev][j] + dist[i][j]*2.0 + dist[i][path[j].next];
	else if(path[j].next == i)
		newS = dist[path[j].prev][i] + dist[i][j]*2.0 + dist[j][path[i].next];
	else
		newS = dist[path[i].prev][j] + dist[j][path[i].next] + dist[path[j].prev][i] + dist[i][path[j].next];
		
	double score = oldS - newS;
	if(CInSwap(i, score))
		return;
		
	if(!(score - EPS > 0 || (T && Feasable(score, T)) || pass))
		return;
	
	if(path[i].next == j){
		InSwapNeighbour(i, j);
	}
	else if(path[j].next == i){
		InSwapNeighbour(j, i);
	}
	else{	
		InSwap(i,j);
	}
		
	
	if(routeStart[path[i].route] == i){
		routeStart[path[i].route] = j;	
	}
	else if(routeStart[path[j].route] == j){
		routeStart[path[j].route] = i;	
	}		

	routeLength[path[i].route] -= score;
	routeTime[path[i].route] -= score;

	cost -= score;	
	USED[0]++;
}

//********************************************************************************
void InSwapNeighbour(int i, int j){
	int ip = path[i].prev;
	int jn = path[j].next;
	
	
	int temp = path[i].prev;
	path[i].prev = j;
	path[j].prev = temp;
		
	temp = path[j].next;
	path[j].next = i;
	path[i].next = temp;
		
	path[ip].next = j;
	path[jn].prev = i;
	
	
}

//********************************************************************************
void InSwap(int i, int j){
	int ip = path[i].prev;
	int jp = path[j].prev;
	int in = path[i].next;
	int jn = path[j].next;
	int temp = path[i].prev;
		
	
	path[i].prev = path[j].prev;
		
	path[j].prev = temp;
			
	temp = path[j].next;
	path[j].next = path[i].next;
	path[i].next = temp;
	
	path[ip].next = j;
	path[jp].next = i;
		
	path[in].prev = j;
	path[jn].prev = i;
}

void BetweenRoutesOpt(double T, int i, int j){
	int r = rand() % 3;
	
	switch(r){
		case 0:BetweenSwap(T,i,j);
			break;
		case 1:BetweenDeleteAndInsert(T,i,j);
			break;
		case 2:Between2DeleteAndInsert(T,i,j);
			break;
	}	
}

//********************************************************************************
void BetweenSwap(double T, int i, int j, bool pass){
	if(CBetweenSwap(i, j))
		return;
		
	double oldS = dist[path[i].prev][i] + dist[i][path[i].next] + dist[path[j].prev][j] + dist[j][path[j].next];
	double newS = dist[path[i].prev][j] + dist[j][path[i].next] + dist[path[j].prev][i] + dist[i][path[j].next];
		
	double score = oldS - newS;	
		
	if(!(score - EPS > 0 || (T && Feasable(score, T)) || pass))
		return;
	routeLength[path[i].route] += dist[path[i].prev][j] + dist[j][path[i].next] - dist[path[i].prev][i] - dist[i][path[i].next];
	routeLength[path[j].route] += dist[path[j].prev][i] + dist[i][path[j].next] - dist[path[j].prev][j] - dist[j][path[j].next];
	routeTime[path[i].route] += dist[path[i].prev][j] + dist[j][path[i].next] - dist[path[i].prev][i] - dist[i][path[i].next];
	routeTime[path[j].route] += dist[path[j].prev][i] + dist[i][path[j].next] - dist[path[j].prev][j] - dist[j][path[j].next];

	InSwap(i,j);
	
	if(routeStart[path[i].route] == i){
		routeStart[path[i].route] = j;	
	}
	if(routeStart[path[j].route] == j){
		routeStart[path[j].route] = i;	
	}		
	
	routeDemand[path[i].route] += d[j] - d[i];
	routeDemand[path[j].route] += d[i] - d[j];
	
	
	int temp = path[i].route;
	path[i].route = path[j].route;
	path[j].route = temp;	
	
	cost -= score;
	USED[2]++;
	
}

// insert i after j	
void BetweenDeleteAndInsert(double T, int i, int j, bool pass){

	if(CDeleteAndInsert(i,j))
		return;
				
	double score = dist[path[i].prev][i] + dist[i][path[i].next] + dist[j][path[j].next] - dist[j][i] - dist[path[i].prev][path[i].next] - dist[i][path[j].next];
	if(!(score - EPS > 0 || (T && Feasable(score, T)) || pass))
		return;	
	
	
	path[path[i].prev].next = path[i].next;
	path[path[i].next].prev = path[i].prev;
	
	routeDemand[path[i].route] -= d[i];
	routeDemand[path[j].route] += d[i];
	routeLength[path[i].route] += dist[path[i].prev][path[i].next] - dist[path[i].prev][i] - dist[i][path[i].next];
	routeLength[path[j].route] += dist[j][i] + dist[i][path[j].next] - dist[j][path[j].next];
	routeTime[path[i].route] += dist[path[i].prev][path[i].next] - dist[path[i].prev][i] - dist[i][path[i].next] - DT;  
	routeTime[path[j].route] += DT - dist[j][path[j].next] + dist[j][i] + dist[i][path[j].next];
		
	if(path[i].prev == 0){
		routeStart[path[i].route] = path[i].next;
	}
	
		
	path[i].route = path[j].route;
	
	path[i].next = path[j].next;
	path[i].prev = j;
	path[j].next = i;
	path[path[i].next].prev = i;
			
	cost -= score;	
	USED[3]++;
}	




void Between2DeleteAndInsert(double T, int i, int j, bool pass){
	int tiafter = 0;
	int tjafter = 0;
	int dtiafter = 0;
	int dtjafter = 0;
	double ticost = 0;
	double tjcost = 0;
	double bcost = INF;
	bool ok = false;
	int pi,pj;
	if(!isTabu(i,path[j].route) && !isTabu(j,path[i].route) && (routeDemand[path[i].route] + d[j] - d[i] <= Q) && (routeDemand[path[j].route] + d[i] - d[j] <= Q)){	
		
	double tcost;
		tcost = cost;
		pi = path[i].route;
		pj = path[j].route;
					
		CDelete(i,dtiafter);		//delete i and in dtiafter save a place after which was i
		CDelete(j,dtjafter);
		tcost -= cost;				//saved cost after deleting
		if(CTryInsert(i, pj, tiafter, ticost) && CTryInsert(j, pi, tjafter, tjcost)){
			bcost = - tcost + ticost + tjcost;
			ok = true;
		}
		CInsert(i, pi, dtiafter);
		CInsert(j, pj, dtjafter);
	}
	else return;
		
	if(!ok)
		return;
	double score = -bcost;
	if(!(score - EPS > 0 || (T && Feasable(score, T)) || pass))
		return;	
		
	int null;
	CDelete(i,null);
	CDelete(j,null);
	CInsert(i, pj, tiafter);
	CInsert(j, pi, tjafter);
	USED[4]++;
	
	//cost -= score;	
}		

//********************************************************************************
bool Feasable(double gain, double T){
	double random = (double)((rand() % 100)+1)/100;
	double aprob = exp(gain/T);
	
	if(random < aprob)
		return true;
	return false;	
}






