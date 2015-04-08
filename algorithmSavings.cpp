#include "algorithmSavings.h"

//********************************************************************************CALCULATE SAVINGS
int CalculateSavings(double lambda){
	int it = 0;
	for(int i = 1; i <= K; i++){
		for(int j = i+1; j <= K; j++){
			savings[it].cost = dist[i][0] + dist[0][j] - lambda*dist[i][j];
			savings[it].i = i;
			savings[it].j = j;
			it++;
		}
	}
	return it;
}

//********************************************************************************SOLVE
void AlgorithmSavings(double lambda){
	
	for(int i = 0; i <= K; i++){
		path[i].next = 0;				
		path[i].prev = 0;				
		path[i].route = i;	
		
		routeStart[i] = i;			
		routeDemand[i] = d[i];	
		routeLength[i] = dist[0][i]*2.0;
		routeTime[i] = dist[0][i]*2.0 + DT;
		
		USED[i] = 0;
	}
	for(int i = 0; i < 5; i++){
		USED[i] = 0;
	}
	int length = CalculateSavings(lambda);
	sort(savings, savings+length);
	
	for(int i = 0; i < length; i++){
		int from = savings[i].i;
		int to = savings[i].j;
		int fromRoute = path[from].route;
		int toRoute = path[to].route;
		if(fromRoute == toRoute)
			continue;
			
			
		if(path[from].next == 0 && path[to].next == 0 && path[to].prev != 0){
			if(path[routeStart[toRoute]].next == to){
				InSwapOpt(0, routeStart[toRoute], to,true);
			}		
			else
				ReverseEdge(0, routeStart[toRoute], to,true);
		
		}
				
		if(path[from].next == 0 && path[to].prev == 0){
			double tlength = routeLength[fromRoute] + routeLength[toRoute] - dist[from][0] - dist[0][to] + dist[from][to];
			double ttime = routeTime[fromRoute] + routeTime[toRoute] - dist[from][0] - dist[0][to] + dist[from][to];
			
			if(CSavings(from, to, ttime))
				continue;
			routeLength[fromRoute] = tlength;
			routeTime[fromRoute] = ttime;
			
			path[to].prev = from;									//set previous to j
			path[from].next = to;									//route continues with the second one;
			
			routeLength[toRoute] = 0; 
			routeTime[toRoute] = 0; 
			
			ChangeRouteNumber(to, fromRoute);
			routeStart[toRoute] = 0;
		
			routeDemand[fromRoute] += routeDemand[toRoute];							//add path demands
			routeDemand[toRoute] = 0;
		}
		
	}
	
	cost = SolutionDistance();
	CopyBestPath();
}
