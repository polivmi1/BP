#include "constraints.h"

//****************************************Both constraints
bool CSavings(int from, int to, double ttime){	
	int fromRoute = path[from].route;
	int toRoute = path[to].route;
		
	if(routeDemand[fromRoute] + routeDemand[toRoute] > Q)
		return true;		
	if(ttime > MRT)
		return true;		
	return false;
}

//****************************************Demand stays, so the only constraint is the path length
bool CInSwap(int from, double score){	
	if(routeTime[path[from].route] - score > MRT)
		return true;		
	return false;
}

//****************************************
bool CBetweenSwap(int from, int to){	
	if((routeDemand[path[from].route] - d[from] + d[to] > Q) || (routeDemand[path[to].route] + d[from] - d[to]> Q))
		return true;		
	if(routeTime[path[from].route]
	- (dist[path[from].prev][from] + dist[from][path[from].next])
	+ (dist[path[from].prev][to] + dist[to][path[from].next])
	> MRT ||
	routeTime[path[to].route]
	- (dist[path[to].prev][to] + dist[to][path[to].next])
	+ ( dist[path[to].prev][from] + dist[from][path[to].next])
	> MRT)
		return true;		
	return false;
}

//****************************************
bool CDeleteAndInsert(int from, int to){	
	if(routeDemand[path[to].route] + d[from] > Q)
		return true;		
	if(routeTime[path[to].route] + DT - dist[to][path[to].next] + dist[to][from] + dist[from][path[to].next] > MRT)
		return true;		
		
	return false;
}


//****************************************CHECK CONSTRAINT
bool CReverseEdge(int from, int to){	
	if(routeTime[path[from].route] - dist[path[from].prev][from] + dist[from][path[to].next]
	 - dist[to][path[to].next] + dist[path[from].prev][to] > MRT)
		return true;		
	return false;
}



