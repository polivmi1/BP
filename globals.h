#ifndef _GLOBALS_H_
#define _GLOBALS_H_
#define o(x) std::cout << #x" = " << x << std::endl

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <climits>
#include <map>
#include <iomanip>
#include <ctime>


#define MAX_C 1300
#define MAX_C_2 650
#define EPS 1E-4
#define INF 999999
#define MAX_RUNNING_TIME 300

#if defined MAIN
#define EXTERN
#else
#define EXTERN extern
#endif

using namespace std;

struct node{
	int next,prev,route;	
};


EXTERN double x[MAX_C];				//x-coordinates
EXTERN double y[MAX_C];				//y-coordinates
EXTERN int d[MAX_C];				//demand

EXTERN int cnof[MAX_C][MAX_C]; 		// closest neighbours of [i]

EXTERN int K;						//number of points to visit (0 is depot)
EXTERN int Q;						//capacity of each car
EXTERN int MRT;						//maximum time of one route
EXTERN int DT;						//drop time(the time spent attending the customer)

EXTERN string problem_name;			//problem name

EXTERN double dist[MAX_C][MAX_C];	//distance matrix(K^2)

EXTERN node path[MAX_C];			//path of the vehicles index is current node, 0 is the end, next, prev
EXTERN node BestPath[MAX_C];		//path of the vehicles index is current node, 0 is the end, next, prev

EXTERN int routeDemand[MAX_C];		//pathDemand[index] contains demand on the path with index being the starting node of the path
EXTERN int BestRouteDemand[MAX_C];		//pathDemand[index] contains demand on the path with index being the starting node of the path

EXTERN int routeStart[MAX_C];		//startingNode[index] contains starting node of the path, which contains index
EXTERN int BestRouteStart[MAX_C];	//startingNode[index] contains starting node of the path, which contains index

EXTERN double routeLength[MAX_C];	//pathLength[index] contains length of the path with index being the starting node of the path
EXTERN double BestRouteLength[MAX_C];//pathLength[index] contains length of the path with index being the starting node of the path

EXTERN double routeTime[MAX_C];		//pathLength[index] contains length of the path with index being the starting node of the path
EXTERN double BestRouteTime[MAX_C];	//pathLength[index] contains length of the path with index being the starting node of the path

EXTERN int tabuList[MAX_C][MAX_C];	//tabu list: if tabuList[i][j] - TabuTime > 0 ... node i with route j is tabu
EXTERN int tabuListR[MAX_C][MAX_C];	//tabu list: if tabuList[i][j] - TabuTime > 0 ... node i  j is tabu
EXTERN int tabuListS[MAX_C][MAX_C];	//tabu list: if tabuList[i][j] - TabuTime > 0 ... node i with route j is tabu
EXTERN int TabuSec;					//tabu time
EXTERN long long int TabuTime;		//Global time

EXTERN double cost;					//cost of the solution
EXTERN double BestScore;			//cost of the best solution
EXTERN double * lastCosts;			//in Late acceptance algorithm keeps the last n scores
struct cnode{						//temp sorting structure for the closest neighbour
	int n;
	double c;
    bool operator < (const cnode& a) const { return c < a.c; }	
};


EXTERN int USED[5];					//how many times used opt move

#endif
