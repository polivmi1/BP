#include "commonFunctions.h"

//********************************************************************************
void ComputeDistance(){
	for(int i = 0; i <= K; i++){
		for(int j = i; j <= K; j++){
			double d1 = fabs(x[i] - x[j]);
			double d2 = fabs(y[i] - y[j]);
			dist[i][j] = dist[j][i] = sqrt(d1*d1 + d2*d2);
		}
	}
}

//********************************************************************************
double SolutionDistance(){
	double ldist = 0.0;
	
	double routeDist = 0.0;
	double routeCapacity = 0.0;
	
	for(int i = 1; i <= K; i++){
		if(routeStart[i] != 0){
			routeDist = 0.0;
			routeCapacity = 0.0;
			
			int from = routeStart[i];
			int to = path[from].next;
			ldist += dist[0][from];
			routeDist += dist[0][from];
			routeCapacity += d[from];
			while(to != 0){
				ldist += dist[from][to];
				routeDist += dist[from][to] + DT;
				routeCapacity += d[to];
				from = to;
				to = path[to].next;	
			}
			ldist += dist[from][0];
			routeDist += dist[from][0] + DT;
			
				
			if(routeDist - EPS > MRT || !(routeDist < routeTime[i]+EPS && routeDist > routeTime[i]-EPS))
				cout << "TIME ERROR: " << routeDist << "   " << routeTime[i] << endl;
			if(routeCapacity - EPS > Q || !(routeCapacity < routeDemand[i]+EPS && routeCapacity > routeDemand[i]-EPS))
				cout << "CAPACITY ERROR: " << routeCapacity << "   " << Q << "   " << routeDemand[i] << endl;
			
		}
	}	
	double ldist2 = 0.0;

	for(int i = 1; i <= K; i++){
		ldist2+=routeLength[i];
	}
	
	if(!(ldist < ldist2+EPS && ldist > ldist2-EPS)){
		cout << "UNMATCH: " << ldist << "   " << ldist2 << endl;
		 PrintSolution();
		 system("PAUSE");
	}
	
	return ldist;	
} 

//********************************************************************************
double BestSolutionDistance(){
	double ldist = 0.0;
	
	double routeDist = 0.0;
	double routeCapacity = 0.0;
	
	for(int i = 1; i <= K; i++){
		if(BestRouteStart[i] != 0){
			routeDist = 0.0;
			routeCapacity = 0.0;
			
			int from = BestRouteStart[i];
			int to = BestPath[from].next;
			if(BestPath[from].route != BestPath[BestRouteStart[i]].route){
				cout << "ROUTE ERROR " << BestPath[from].route<< "  " << BestPath[BestRouteStart[i]].route << endl;system("PAUSE");
			}
			ldist += dist[0][from];
			routeDist += dist[0][from];
			routeCapacity += d[from];
			while(to != 0){
				if(BestPath[to].route != BestPath[BestRouteStart[i]].route){
					cout << "ROUTE ERROR2 " <<to<<"  "<< BestPath[to].route<< "  " << BestPath[BestRouteStart[i]].route<<"  "<<i << endl;system("PAUSE");
				}
				ldist += dist[from][to];
				routeDist += dist[from][to] + DT;
				routeCapacity += d[to];
				from = to;
				to = BestPath[to].next;	
			}
			ldist += dist[from][0];
			routeDist += dist[from][0] + DT;
			
				
			if(routeDist - EPS > MRT)
				cout << "TIME ERROR: " << routeDist << endl;
			if(routeCapacity - EPS > Q)
				cout << "CAPACITY ERROR: " << routeCapacity << "   " << Q << endl;
			
		}
	}	
		
	return ldist;	
} 

//********************************************************************************
void PrintSolution(){
	cout << "Solution for problem: " << problem_name << endl;

	int routeNum = 1;
	for(int i = 1; i <= K; i++){
		if(routeStart[i] != 0){
			int from = routeStart[i];
			int to = path[from].next;
			
			cout << "Route#" << routeNum++ << ": " << from;
			while(to != 0){
				cout << " " << to;
				from = to;
				to = path[to].next;	
			}
			cout << endl;
		}
	}
	cout << "cost " << cost << endl;
	
}

//********************************************************************************
void PrintBestSolution(){
	cout << "Best Solution for problem: " << problem_name << endl;

	int routeNum = 1;
	for(int i = 1; i <= K; i++){
		if(BestRouteStart[i] != 0){
			int from = BestRouteStart[i];
			int to = BestPath[from].next;
			
			cout << "Route#" << routeNum++ << ": " << from;
			while(to != 0){
				cout << " " << to;
				from = to;
				to = BestPath[to].next;	
			}
			cout << endl;
		}
	}
	cout << "cost " << BestScore << endl;
	
}


//********************************************************************************Apply strategy n = 2,3
void Strategy(int i, int j, double T){
	if(path[i].route == path[j].route){
		InRouteOpt(T,i,j);
	}
	else{
		BetweenRoutesOpt(T,i,j);
	}
	
}

//********************************************************************************Change the route for all following nodes in route starting with from
void ChangeRouteNumber(int from, int num){
	path[from].route = num;
	while(path[from].next){
		from = path[from].next;	
		path[from].route = num;
	}	
}

//********************************************************************************Copy path to bestpath
void CopyBestPath(){
	for(int i = 0; i <= K; i++){
		BestPath[i].next = path[i].next;
		BestPath[i].prev = path[i].prev;
		BestPath[i].route = path[i].route;	
		BestRouteStart[i] = routeStart[i];
		BestRouteDemand[i] = routeDemand[i];
		BestRouteTime[i] = routeTime[i];
		BestRouteLength[i] = routeLength[i];
	}
	
	BestScore = cost;
}
//********************************************************************************Copy Bestpath to path
void CopyRevBestPath(){
	for(int i = 0; i <= K; i++){
		path[i].next = BestPath[i].next;
		path[i].prev = BestPath[i].prev;
		path[i].route = BestPath[i].route;	
		routeStart[i] = BestRouteStart[i];
		routeDemand[i] = BestRouteDemand[i];
		routeTime[i] = BestRouteTime[i];
		routeLength[i] = BestRouteLength[i];
	}
	
	cost = BestScore;
}

//********************************************************************************
void InitClosestArray(int max_closest){
	max_closest = min(max_closest,K);
	cnode temp[MAX_C];			
	for(int i = 1; i <= K; i++){
		for(int j = 1; j <= K; j++){
			temp[j-1].c = dist[i][j];			
			temp[j-1].n = j;
			if(i == j)
				temp[j-1].c = INF;			
		}
		
		sort(temp, temp+K);
		for(int j = 0; j < max_closest; j++){
			cnof[i][j] = temp[j].n;			
		}	
	}
}

int GetJ(int i, int closest, int prob){
	int j = (rand() % K)+1;	
	if(closest){
		int tprob = rand() % prob;
		if(tprob >= 50){
			j = cnof[i][(rand() % (closest))];	
			while(j == i){
				j = cnof[i][(rand() % (closest))];	
			}
		}
		else{
			while(j == i){
				j = (rand() % K)+1;		
			}
		}
	}
	else{
		while(j == i){
			j = (rand() % K)+1;		
		}
	}
	
	return j;
}
