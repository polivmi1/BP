#include "tests.h"

void TestAllLi(int runs){
	
	double testc[12][5];
	for(int i = 0; i < 12; i++)
		for(int j = 0; j < 5; j++)
			testc[i][j] = INF;
	
	srand (time(NULL));
	for(int j = 0; j < 12; j++){
		string file = "../Benchmarks/Li/Li_";
		stringstream ss;
		ss << j+21;
		string filen = file + ss.str() + ".vrp";

		double optimal;
		LoadLi(filen, optimal);
		testc[j][4] = optimal;
		ComputeDistance();		

		srand (time(NULL));
		
		o(j);
		for(int i = 0; i < runs; i++){
			o(i);
			double lambda = (double)((rand()%20) + 1)/10;
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 250, (int)(10.0*log(K)));
			if(testc[j][3] > cost){
				testc[j][3] = cost;
				PlotFile(MakeFileForGnuplot("Li" + ss.str() + "CTS"));	
			}		
			PrintSolution();

		
		}
	}
	
	cout << "\n\n\nS - Savings\nHC - Hill Climb\nSA - Simulated Annealing\n" << endl;
	
	cout << "INST\tS\tHC\tTS\tCTS\tOPT" << endl;		
	for(int i = 0; i < 12; i++){
		cout << i+1;
		for(int j = 0; j < 5; j++){
			cout << "\t" << testc[i][j];
		}
		cout << endl;
	}
}


void TestPlot2Taillard(int runs){
	
		string file = "../Benchmarks/Taillard/1.dat";
		
		double optimal;
		LoadTaillard(file, optimal);

		ComputeDistance();		

		srand (time(NULL));
			
		for(int i = 0; i < runs; i++){
			stringstream ss;
			ss << i;
			string num = ss.str();
			double lambda = (double)((rand()%20) + 1)/10;
			AlgorithmSavings(lambda);
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 250, (int)(10.0*log(K)));
			PlotFile(MakeFileForGnuplot(num+"CTSTaillard"));
			PrintSolution();

			
			
		}
}
void TestAllTaillard(int runs){
	
	double testc[13][5];
	for(int i = 0; i < 13; i++)
		for(int j = 0; j < 5; j++)
			testc[i][j] = INF;
	
	srand (time(NULL));
	for(int j = 0; j < 13; j++){
		string file = "../Benchmarks/Taillard/";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".dat";

		double optimal;
		LoadTaillard(filen, optimal);
		testc[j][4] = optimal;
		ComputeDistance();		

		srand (time(NULL));
		
		o(j);
		for(int i = 0; i < runs; i++){
			o(i);
			double lambda = (double)((rand()%20) + 1)/10;
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 250, (int)(10.0*log(K)));
			if(testc[j][3] > cost){
				testc[j][3] = cost;
				PlotFile(MakeFileForGnuplot(ss.str() + "CTS"));	
			}
		
		}
	}
	
	cout << "\n\n\nS - Savings\nHC - Hill Climb\nSA - Simulated Annealing\n" << endl;
	
	cout << "INST\tS\tHC\tTS\tCTS\tOPT" << endl;		
	for(int i = 0; i < 13; i++){
		cout << i+1;
		for(int j = 0; j < 5; j++){
			cout << "\t" << testc[i][j];
		}
		cout << endl;
	}
}

void TestPlot12Kelly(int runs){
	
		string file = "../Benchmarks/kelly/kelly10.txt";
		
		double optimal;
		LoadKelly(file, optimal);

		ComputeDistance();		

		srand (time(NULL));
		
		for(int i = 0; i < runs; i++){
			double lambda = (double)((rand()%20) + 1)/10;
			stringstream ss;
			ss << i;
			string num = ss.str();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 250, (int)(10.0*log(K)));
			PlotFile(MakeFileForGnuplot(num+"CTSkelly10"));
			PrintSolution();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.0001, 350);
			PlotFile(MakeFileForGnuplot(num+"SAkelly10"));
			PrintSolution();

		}
}

void TestAllChrist(int runs){
	
	double testc[14][4];
	for(int i = 0; i < 14; i++)
		for(int j = 0; j < 4; j++)
			testc[i][j] = INF;
	
	srand (time(NULL));
	for(int j = 0; j < 14; j++){
		string file = "../Benchmarks/ChristofidesEilon/vrpnc";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".txt";

		LoadChristofidesEilon(filen);

		ComputeDistance();		

		srand (time(NULL));
		
		o(j);
		for(int i = 0; i < runs; i++){
			o(i);
			double lambda = (double)((rand()%20) + 1)/10;
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 250, (int)(10.0*log(K)));
			testc[j][3] = min(testc[j][3],cost);
			
			PlotFile(MakeFileForGnuplot(ss.str() + "CTS"));	
		}
	}
	
	cout << "\n\n\nS - Savings\nHC - Hill Climb\nSA - Simulated Annealing\n" << endl;
	
	cout << "INST\tS\tHC\tSA\tTS" << endl;		
	for(int i = 0; i < 14; i++){
		cout << i+1;
		for(int j = 0; j < 4; j++){
			cout << "\t" << testc[i][j];
		}
		cout << endl;
	}
}



void TestAllKelly(int runs){
	
	double testc[20][5];
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 5; j++)
			testc[i][j] = INF;
	
	srand (time(NULL));
	for(int j = 0; j < 20; j++){
		string file = "../Benchmarks/kelly/kelly";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".txt";

		double optimal;
		LoadKelly(filen, optimal);
		testc[j][4] = optimal;
		ComputeDistance();		

		srand (time(NULL));
		
		o(j);
		for(int i = 0; i < runs; i++){
			o(i);
			double lambda = (double)((rand()%20) + 1)/10;
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 250, (int)(10.0*log(K)));
			if(testc[j][3] > cost){
				testc[j][3] = cost;
				PlotFile(MakeFileForGnuplot(ss.str() + "CTS"));	
			}
		
		}
	}
	
	cout << "\n\n\nS - Savings\nHC - Hill Climb\nSA - Simulated Annealing\n" << endl;
	
	cout << "INST\tS\tHC\tTS\tCTS\tOPT" << endl;		
	for(int i = 0; i < 20; i++){
		cout << i+1;
		for(int j = 0; j < 5; j++){
			cout << "\t" << testc[i][j];
		}
		cout << endl;
	}
}

//Tests BEST FIT SEARCH
void TestBestFit(int runs){
	double testc[20][4];
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 4; j++)
			testc[i][j] = INF;
	
	srand (time(NULL));
	for(int j = 0; j < 20; j++){
		string file = "../Benchmarks/kelly/kelly";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".txt";

		double optimal;
		LoadKelly(filen, optimal);
		testc[j][3] = optimal;
		ComputeDistance();
		

		srand (time(NULL));
		double lambda = (double)((rand()%20) + 1)/10;
		AlgorithmSavings(lambda);
	//	testc[j][0] = min(testc[j][0],cost);
		//AlgorithmHillClimb(100);
		//testc[j][2] = min(testc[j][2],cost);
		o(j);
		for(int i = 0; i < runs; i++){
			o(i);
			//PrintSolution();
			//AlgorithmHillClimb(100);
			AlgorithmTabuSearch();
			testc[j][1] = min(testc[j][1],cost);
			PrintSolution();
		}
	}
	
	cout << "\n\n\nS - Savings\nHC - Hill Climb\nSA - Simulated Annealing\n" << endl;
	
	cout << "INST\tS\tHC\tSA" << endl;		
	for(int i = 0; i < 20; i++){
		cout << i+1;
		for(int j = 0; j < 4; j++){
			cout << "\t" << testc[i][j];
		}
		cout << endl;
	}
 }
 
 
 //Tests of my instances 
void TestBasic(int runs){
	double testc;
	testc = INF;
			
	string file = "../Benchmarks/My/vrpn1.txt";
	LoadChristofidesEilon(file);

	ComputeDistance();
	srand (time(NULL));
	for(int i = 0; i < runs; i++){
		AlgorithmSavings();	
		AlgorithmTabuSearch();
		testc = min(testc,cost);
	}
	
	PrintSolution();
 }
 
 //Tests of KELLY / GOLDEN instances
void Test_Kelly(int runs){
		
	double testc[20][4];
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 4; j++)
			testc[i][j] = INF;
	
	srand (time(NULL));
	for(int j = 0; j < 20; j++){
		string file = "../Benchmarks/kelly/kelly";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".txt";

		double optimal;
		LoadKelly(filen, optimal);
		testc[j][3] = optimal;
		ComputeDistance();
		

		srand (time(NULL));
		o(j);
		for(int i = 0; i < runs; i++){
			o(i);
			double lambda = (double)((rand()%20) + 1)/10;
			AlgorithmSavings(lambda);
			testc[j][0] = min(testc[j][0],cost);
			
			AlgorithmSimulatedAnnealing(0.9999, 5.0, 0.0001, 150);
			testc[j][2] = min(testc[j][2],cost);
			
			AlgorithmSavings(lambda);
			AlgorithmTabuSearch();
			testc[j][1] = min(testc[j][1],cost);
			//PrintSolution();
		}
	}
	
	cout << "\n\n\nS - Savings\nHC - Hill Climb\nSA - Simulated Annealing\n" << endl;
	
	cout << "INST\tS\tHC\tSA" << endl;		
	for(int i = 0; i < 20; i++){
		cout << i+1;
		for(int j = 0; j < 4; j++){
			cout << "\t" << testc[i][j];
		}
		cout << endl;
	}
	
	
 }

//Tests all 3 algorithms on 14 first instances with Tabu search
void Test2_ChristofidesEilon_1to14(int runs){
	double testc[14][3];
	for(int i = 0; i < 14; i++)
		for(int j = 0; j < 3; j++)
			testc[i][j] = INF;
	
	srand (time(NULL));
	for(int j = 0; j < 14; j++){
		string file = "../Benchmarks/ChristofidesEilon/vrpnc";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".txt";
		LoadChristofidesEilon(filen);
		ComputeDistance();
		
		AlgorithmSavings();
		
		for(int i = 0; i < runs; i++){
			o(i);
			AlgorithmTabuSearch();
			testc[j][2] = min(testc[j][2],cost);
			PrintSolution();
		}
	}
	
	cout << "\n\n\nS - Savings\nHC - Hill Climb\nSA - Simulated Annealing\n" << endl;
	
	cout << "INST\tS\tHC\tSA" << endl;		
	for(int i = 0; i < 14; i++){
		cout << i+1;
		for(int j = 0; j < 3; j++){
			cout << "\t" << testc[i][j];
		}
		cout << endl;
	}
 }


//Tests all 3 algorithms on 14 first instances
void Test1_ChristofidesEilon_1to14(int runs){
	double testc[14][3];
	for(int i = 0; i < 14; i++)
		for(int j = 0; j < 3; j++)
			testc[i][j] = INF;
	
	srand (time(NULL));
	for(int j = 0; j < 14; j++){
		string file = "../Benchmarks/ChristofidesEilon/vrpnc";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".txt";
		LoadChristofidesEilon(filen);
		ComputeDistance();

		
		for(int i = 0; i < runs; i++){
			o(i);
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 1.0, 0.0001, 200);
			testc[j][2] = min(testc[j][2],cost);
			PrintSolution();
		}
	}
	
	cout << "\n\n\nS - Savings\nHC - Hill Climb\nSA - Simulated Annealing\n" << endl;
	
	cout << "INST\tS\tHC\tSA" << endl;		
	for(int i = 0; i < 14; i++){
		cout << i+1;
		for(int j = 0; j < 3; j++){
			cout << "\t" << testc[i][j];
		}
		cout << endl;
	}
 }


//Tests of my instances
void Test0(int runs){
	double testc[5];
	for(int i = 0; i < 5; i++)
		testc[i] = INF;
			
	for(int j = 0; j < 5; j++){
		string file = "../Benchmarks/My/vrpn";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".txt";
		LoadChristofidesEilon(filen);
		ComputeDistance();
		srand (time(NULL));
		for(int i = 0; i < runs; i++){
			double lambda = (double)((rand()%20) + 1)/10;
			cout << "lamda: " << lambda << endl;
			AlgorithmSavings(lambda);		
			PrintSolution();	
			AlgorithmSimulatedAnnealing(0.9999, 1.0, 0.00001, 10);
			cout << "run: "<<i<<", file "<<j<<" : "<<cost << endl;
			testc[j] = min(testc[j],cost);
			PrintSolution();
		}
	}
	
	cout << "\n\n\nSA - Simulated Annealing\n" << endl;
	
	cout << "INST\tSA" << endl;		
	for(int i = 0; i < 5; i++){
		cout << i+1 << "\t" << testc[i] << endl;
	}
 }



//Tests all 3 algorithms on 5 first instances
void Test1_ChristofidesEilon_1to5(int runs){
	double testc[5][3];
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 3; j++)
			testc[i][j] = INF;
			
	for(int j = 0; j < 5; j++){
		string file = "../Benchmarks/ChristofidesEilon/vrpnc";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".txt";
		LoadChristofidesEilon(filen);
		ComputeDistance();
		for(int i = 0; i < runs; i++){
			AlgorithmSavings();
			testc[j][0] = min(testc[j][0],cost);
			
			AlgorithmHillClimb();
			testc[j][1] = min(testc[j][1],cost);
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.9999, 1.0, 0.0001, 100);
			testc[j][2] = min(testc[j][2],cost);
		}
	}
	
	cout << "\n\n\nS - Savings\nHC - Hill Climb\nSA - Simulated Annealing\n" << endl;
	
	cout << "INST\tS\tHC\tSA" << endl;		
	for(int i = 0; i < 5; i++){
		cout << i+1;
		for(int j = 0; j < 3; j++){
			cout << "\t" << testc[i][j];
		}
		cout << endl;
	}
 }


//Tests Simulated Annealing after random parametrized basic savings solution
void Test2_ChristofidesEilon_1to5(int runs){
	double testc[5];
	for(int i = 0; i < 5; i++)
		testc[i] = INF;
			
	for(int j = 0; j < 5; j++){
		string file = "../Benchmarks/ChristofidesEilon/vrpnc";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".txt";
		LoadChristofidesEilon(filen);
		ComputeDistance();
		srand (time(NULL));
		for(int i = 0; i < runs; i++){
			double lambda = (double)((rand()%20) + 1)/10;
			cout << "lamda: " << lambda << endl;
			AlgorithmSavings(lambda);
			AlgorithmSimulatedAnnealing(0.9999, 1.0, 0.000001, 100);
			cout << "run: "<<i<<", file "<<j<<" : "<<cost << endl;
			testc[j] = min(testc[j],cost);
		}
	}
	
	cout << "\n\n\nSA - Simulated Annealing\n" << endl;
	
	cout << "INST\tSA" << endl;		
	for(int i = 0; i < 5; i++){
		cout << i+1 << "\t" << testc[i] << endl;
	}
 }




//Tests 
void FullTest_Christ(int runs){
	double testc[14][5];
	double testt[14][5];
	double testu[14][5][5];
	for(int i = 0; i < 14; i++)
		for(int j = 0; j < 5; j++){
			testc[i][j] = INF;
			testt[i][j] = INF;
			for(int k = 0; k < 5; k++)
				testu[i][j][k] = 0;
		}
	
	srand (time(NULL));
	for(int j = 0; j < 1; j++){
/*		string file = "../Benchmarks/ChristofidesEilon/vrpnc";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".txt";

		LoadChristofidesEilon(filen);
*/
/*
string file = "../Benchmarks/usa-n500-k20.vrp";
 //file = "../Benchmarks/Augerat/A-n38-k5.vrp";

LoadAugerat(file);
stringstream ss;
		ss << j+1;

		
*/		
		string file = "../Benchmarks/Li/Li_";
		stringstream ss;
		ss << j+21;
		string filen = file + ss.str() + ".vrp";

		double optimal;
		LoadLi(filen, optimal);
		testc[j][4] = optimal;

		ComputeDistance();		

		srand (time(NULL));
		double lambda = 0.0;
		double bt,et;
		o(j);
		
		//	AlgorithmSavings();
		//	AlgorithmSimulatedAnnealing(0.9999, 5.0, 0.00001, 250);
		for(int i = 0; i < runs; i++){
			o(i);
			lambda = (double)((rand()%20) + 1)/10;
			/*
			bt = omp_get_wtime();
			AlgorithmSavings(lambda);
			et = omp_get_wtime();
			if(testc[j][0] > cost){
				testc[j][0] = cost;	
				testt[j][0] = et-bt;	
				PlotFile(MakeFileForGnuplot("S" + ss.str()));	
			}
			PrintBestSolution();
			PrintSolution();
			
			bt = omp_get_wtime();
			AlgorithmHillClimb(333);
			et = omp_get_wtime();
			PrintBestSolution();
			PrintSolution();

			if(testc[j][1] > cost){
				testc[j][1] = cost;	
				testt[j][1] = et-bt;
				PlotFile(MakeFileForGnuplot("HC" + ss.str()));	
			}
			*/
		
				
			bt = omp_get_wtime();
			AlgorithmSavings();
			//PlotFile(MakeFileForGnuplot("SA" + ss.str()));	
			
			//AlgorithmSCHC(1000, 10000000);
			//CopyRevBestPath();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 150);
			//AlgorithmLAHC(10000, 10000000);
			
			//AlgorithmTabuSearch((100.0/(double)K)*5000,sqrt(K));//CHANGE TO TIME
			//BestSolutionDistance();
			//PrintBestSolution();system("PAUSE");
			et = omp_get_wtime();
			testc[j][1] += BestScore;
			if(testc[j][2] > BestScore){
				testc[j][2] = BestScore;	
				testt[j][2] = et-bt;
				for(int k = 0; k < 5; k++)
					testu[j][2][k] = USED[k];
				PlotFile(MakeFileForGnuplot("SA" + ss.str()));	
			}
			
			
			
			
			/*
			bt = omp_get_wtime();
			AlgorithmSavings(lambda);
			AlgorithmClosestSearch(0.9999, 5.0, 0.00001, 250);
			AlgorithmTabuSearch(10);
			PrintBestSolution();
			PrintSolution();
			et = omp_get_wtime();
			if(testc[j][3] > cost){
				testc[j][3] = cost;	
				testt[j][3] = et-bt;
				PlotFile(MakeFileForGnuplot("TS" + ss.str()));	
			}
			*/
		
		/*
			bt = omp_get_wtime();
			AlgorithmClosestSearch(0.9999, 20.0, 0.00001, 250);
			PrintBestSolution();
			et = omp_get_wtime();
			testc[j][3] += BestScore;
			if(testc[j][4] > BestScore){
				testc[j][4] = BestScore;	
				testt[j][4] = et-bt;
				for(int k = 0; k < 5; k++)
					testu[j][4][k] = USED[k];
				PlotFile(MakeFileForGnuplot("CTS" + ss.str()));	
		}*/
			}
			testc[j][1] /= runs;
			testc[j][3] /= runs;
	}
	
	cout << "\n\n\nS - Savings\nHC - Hill Climb\nSA - Simulated Annealing\nTS - Tabu Search\nCTS - Closest Tabu Search\n" << endl;
	
	cout << "INST\tS\tHC\tSA\tTS\tCTS\t\t" << endl;		
	for(int i = 0; i < 14; i++){
		cout << i+1;
		for(int j = 0; j < 5; j++){
			cout << "\t" << testc[i][j];
		}
		cout << "\t\t";
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++)
				cout << "\t" << testu[i][j][k];
			cout << " --- ";
		}
		
		cout << "\n" << i+1;

		for(int j = 0; j < 5; j++){
			cout << "\t" << testt[i][j];
		}
		cout << "\n" << endl;
	}
 }





void TabuTest_Christ(int runs){
	double testc[14][5];
	double testt[14][5];
	for(int i = 0; i < 14; i++)
		for(int j = 0; j < 5; j++){
			testc[i][j] = INF;
			testt[i][j] = INF;
		}
	
	srand (time(NULL));
	for(int j = 0; j < 14; j++){
		string file = "../Benchmarks/ChristofidesEilon/vrpnc";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".txt";

		LoadChristofidesEilon(filen);

		ComputeDistance();		

		srand (time(NULL));
		double lambda = 0.0;
		double bt,et;
		o(j);
		for(int i = 0; i < runs; i++){
			o(i);
			//lambda = (double)((rand()%20) + 1)/10;

			bt = omp_get_wtime();
			AlgorithmSavings();//lambda);
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 250, (int)(10.0*log(K)));
			o(cost);
					
			
			AlgorithmTabuSearch(20);
			
			et = omp_get_wtime();
			if(testc[j][3] > cost){
				testc[j][3] = cost;	
				testt[j][3] = et-bt;
				PlotFile(MakeFileForGnuplot("TS" + ss.str()));	
			}
		
		}
	}
	
	cout << "\n\n\nS - Savings\nHC - Hill Climb\nSA - Simulated Annealing\nTS - Tabu Search\nCTS - Closest Tabu Search\n" << endl;
	
	cout << "INST\tS\tHC\tSA\tTS\tCTS" << endl;		
	for(int i = 0; i < 14; i++){
		cout << i+1;
		for(int j = 0; j < 5; j++){
			cout << "\t" << testc[i][j];
		}
		
		cout << "\n" << i+1;

		for(int j = 0; j < 5; j++){
			cout << "\t" << testt[i][j];
		}
		cout << "\n" << endl;
	}
 }
 
 
 
 
 
 
 
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**********************************************************************Final benchmarking Tests used in Thesis*************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/
 /**************************************************************************************************************************************************************/

void FinalChrist(int runs, int f, int t){

	double testB[14][14];
	double testA[14][14];
	double testW[14][14];
	
	
	
	for(int i = 0; i < 14; i++)
		for(int j = 0; j < 14; j++){
			testB[i][j] = INF;
			testA[i][j] = 0.0;
			testW[i][j] = -INF;
		}
	
	srand (time(NULL));
	for(int j = f; j < t; j++){
		string file = "../Benchmarks/ChristofidesEilon/vrpnc";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".txt";

		LoadChristofidesEilon(filen);	
		ComputeDistance();		

		srand (time(NULL));
		//double lambda = 0.0;
		double bt,et;
		
		cout << "Loading file: " << filen << endl;
		
		for(int i = 0; i < runs; i++){
			stringstream srun;
			srun << i+1;
			cout << "Run n. " << i+1 << "/" << runs << endl;
			//lambda = (double)((rand()%20) + 1)/10;
			
			AlgorithmSavings();
			if(testB[j][0] > BestScore){
				testB[j][0] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SAVINGS"));	
			}
			if(testW[j][0] < BestScore){
				testW[j][0] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SAVINGS"));	
			}
			testA[j][0] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmHillClimb();
			if(testB[j][1] > BestScore){
				testB[j][1] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_HILLCLIMB"));	
			}
			if(testW[j][1] < BestScore){
				testW[j][1] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_HILLCLIMB"));	
			}
			testA[j][1] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmLAHC(10000, 10000000);
			if(testB[j][2] > BestScore){
				testB[j][2] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_LAHC0"));	
			}
			if(testW[j][2] < BestScore){
				testW[j][2] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_LAHC0"));	
			}
			testA[j][2] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmLAHC(10000, 10000000, (int)(10.0*log(K)));
			if(testB[j][3] > BestScore){
				testB[j][3] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_LAHC50"));	
			}
			if(testW[j][3] < BestScore){
				testW[j][3] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_LAHC50"));	
			}
			testA[j][3] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmLAHC(10000, 10000000, (int)(10.0*log(K)), 200);
			if(testB[j][4] > BestScore){
				testB[j][4] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_LAHC75"));	
			}
			if(testW[j][4] < BestScore){
				testW[j][4] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_LAHC75"));	
			}
			testA[j][4] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmLAHC(10000, 10000000, (int)(10.0*log(K)), INF);
			if(testB[j][5] > BestScore){
				testB[j][5] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_LAHC99"));	
			}
			if(testW[j][5] < BestScore){
				testW[j][5] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_LAHC99"));	
			}
			testA[j][5] += BestScore;
			PrintBestSolution();
			
						
			AlgorithmSavings();
			AlgorithmSCHC(10000, 10000000);
			if(testB[j][6] > BestScore){
				testB[j][6] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SCHC0"));	
			}
			if(testW[j][6] < BestScore){
				testW[j][6] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SCHC0"));	
			}
			testA[j][6] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmSCHC(10000, 10000000, (int)(10.0*log(K)));
			if(testB[j][7] > BestScore){
				testB[j][7] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SCHC50"));	
			}
			if(testW[j][7] < BestScore){
				testW[j][7] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SCHC50"));	
			}
			testA[j][7] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmSCHC(10000, 10000000, (int)(10.0*log(K)), 200);
			if(testB[j][8] > BestScore){
				testB[j][8] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SCHC75"));	
			}
			if(testW[j][8] < BestScore){
				testW[j][8] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SCHC75"));	
			}
			testA[j][8] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmSCHC(10000, 10000000, (int)(10.0*log(K)), INF);
			if(testB[j][9] > BestScore){
				testB[j][9] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SCHC99"));	
			}
			if(testW[j][9] < BestScore){
				testW[j][9] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SCHC99"));	
			}
			testA[j][9] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 150);
			if(testB[j][10] > BestScore){
				testB[j][10] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SIMANN0"));	
			}
			if(testW[j][10] < BestScore){
				testW[j][10] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SIMANN0"));	
			}
			testA[j][10] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 150, (int)(10.0*log(K)));
			if(testB[j][11] > BestScore){
				testB[j][11] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SIMANN50"));	
			}
			if(testW[j][11] < BestScore){
				testW[j][11] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SIMANN50"));	
			}
			testA[j][11] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 150, (int)(10.0*log(K)), 200);
			if(testB[j][12] > BestScore){
				testB[j][12] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SIMANN75"));	
			}
			if(testW[j][12] < BestScore){
				testW[j][12] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SIMANN75"));	
			}
			testA[j][12] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 150, (int)(10.0*log(K)), INF);
			if(testB[j][13] > BestScore){
				testB[j][13] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SIMANN99"));	
			}
			if(testW[j][13] < BestScore){
				testW[j][13] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SIMANN99"));	
			}
			testA[j][13] += BestScore;
			PrintBestSolution();
		}
		testA[j][0] = testA[j][0]/(double)runs;
		testA[j][1] = testA[j][1]/(double)runs;
		testA[j][2] = testA[j][2]/(double)runs;
		testA[j][3] = testA[j][3]/(double)runs;
		testA[j][4] = testA[j][4]/(double)runs;
		testA[j][5] = testA[j][5]/(double)runs;
		testA[j][6] = testA[j][6]/(double)runs;
		testA[j][7] = testA[j][7]/(double)runs;
		testA[j][8] = testA[j][8]/(double)runs;
		testA[j][9] = testA[j][9]/(double)runs;
		testA[j][10] = testA[j][10]/(double)runs;
		testA[j][11] = testA[j][11]/(double)runs;
		testA[j][12] = testA[j][12]/(double)runs;
		testA[j][13] = testA[j][13]/(double)runs;
		
	}
	
	cout << "\n\n\nS - Savings"<<
		"\nHC - Hill Climb"
		<<
		"\nSA - Simulated Annealing"
		<<
		"\nLA - Late Acceptance"
		<<
		"\nSC - Step Counting\n" << endl;
	
	cout << "INST\tS\tHC\tLA0\tLA50\tLA75\tLA99\tSC0\tSC50\tSC75\tSC99\tSA0\tSA50\tSA75\tSA99" << endl;		
	for(int i = 0; i < 14; i++){
		cout << i+1;
		for(int j = 0; j < 14; j++){
			cout << "\t" << testB[i][j];
		}		
		cout << "\n" << i+1;
		for(int j = 0; j < 14; j++){
			cout << "\t" << testA[i][j];
		}
		cout << "\n" << i+1;
		for(int j = 0; j < 14; j++){
			cout << "\t" << testW[i][j];
		}
		cout << "\n" << endl;
	}
}


/*******************************************************************************************************************************************************/

		

void FinalLi(int runs, int f, int t){

	double testB[14][14];
	double testA[14][14];
	double testW[14][14];
	
	
	
	for(int i = 0; i < 14; i++)
		for(int j = 0; j < 14; j++){
			testB[i][j] = INF;
			testA[i][j] = 0.0;
			testW[i][j] = -INF;
		}
	
	srand (time(NULL));
	for(int j = f; j < t; j++){
		string file = "../Benchmarks/Li/Li_";
		stringstream ss;
		ss << j+21;
		string filen = file + ss.str() + ".vrp";

		double optimal;
		LoadLi(filen, optimal);

		ComputeDistance();		

		srand (time(NULL));
		//double lambda = 0.0;
		double bt,et;
		
		cout << "Loading file: " << filen << endl;
		
		for(int i = 0; i < runs; i++){
			stringstream srun;
			srun << i+1;
			cout << "Run n. " << i+1 << "/" << runs << endl;
			//lambda = (double)((rand()%20) + 1)/10;
			
			AlgorithmSavings();
			if(testB[j][0] > BestScore){
				testB[j][0] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SAVINGS"));	
			}
			if(testW[j][0] < BestScore){
				testW[j][0] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SAVINGS"));	
			}
			testA[j][0] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmHillClimb();
			if(testB[j][1] > BestScore){
				testB[j][1] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_HILLCLIMB"));	
			}
			if(testW[j][1] < BestScore){
				testW[j][1] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_HILLCLIMB"));	
			}
			testA[j][1] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmLAHC(10000, 10000000);
			if(testB[j][2] > BestScore){
				testB[j][2] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_LAHC0"));	
			}
			if(testW[j][2] < BestScore){
				testW[j][2] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_LAHC0"));	
			}
			testA[j][2] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmLAHC(10000, 10000000, (int)(10.0*log(K)));
			if(testB[j][3] > BestScore){
				testB[j][3] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_LAHC50"));	
			}
			if(testW[j][3] < BestScore){
				testW[j][3] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_LAHC50"));	
			}
			testA[j][3] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmLAHC(10000, 10000000, (int)(10.0*log(K)), 200);
			if(testB[j][4] > BestScore){
				testB[j][4] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_LAHC75"));	
			}
			if(testW[j][4] < BestScore){
				testW[j][4] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_LAHC75"));	
			}
			testA[j][4] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmLAHC(10000, 10000000, (int)(10.0*log(K)), INF);
			if(testB[j][5] > BestScore){
				testB[j][5] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_LAHC99"));	
			}
			if(testW[j][5] < BestScore){
				testW[j][5] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_LAHC99"));	
			}
			testA[j][5] += BestScore;
			PrintBestSolution();
			
						
			AlgorithmSavings();
			AlgorithmSCHC(10000, 10000000);
			if(testB[j][6] > BestScore){
				testB[j][6] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SCHC0"));	
			}
			if(testW[j][6] < BestScore){
				testW[j][6] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SCHC0"));	
			}
			testA[j][6] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmSCHC(10000, 10000000, (int)(10.0*log(K)));
			if(testB[j][7] > BestScore){
				testB[j][7] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SCHC50"));	
			}
			if(testW[j][7] < BestScore){
				testW[j][7] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SCHC50"));	
			}
			testA[j][7] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmSCHC(10000, 10000000, (int)(10.0*log(K)), 200);
			if(testB[j][8] > BestScore){
				testB[j][8] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SCHC75"));	
			}
			if(testW[j][8] < BestScore){
				testW[j][8] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SCHC75"));	
			}
			testA[j][8] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmSCHC(10000, 10000000, (int)(10.0*log(K)), INF);
			if(testB[j][9] > BestScore){
				testB[j][9] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SCHC99"));	
			}
			if(testW[j][9] < BestScore){
				testW[j][9] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SCHC99"));	
			}
			testA[j][9] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 150);
			if(testB[j][10] > BestScore){
				testB[j][10] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SIMANN0"));	
			}
			if(testW[j][10] < BestScore){
				testW[j][10] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SIMANN0"));	
			}
			testA[j][10] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 150, (int)(10.0*log(K)));
			if(testB[j][11] > BestScore){
				testB[j][11] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SIMANN50"));	
			}
			if(testW[j][11] < BestScore){
				testW[j][11] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SIMANN50"));	
			}
			testA[j][11] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 150, (int)(10.0*log(K)), 200);
			if(testB[j][12] > BestScore){
				testB[j][12] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SIMANN75"));	
			}
			if(testW[j][12] < BestScore){
				testW[j][12] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SIMANN75"));	
			}
			testA[j][12] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 150, (int)(10.0*log(K)), INF);
			if(testB[j][13] > BestScore){
				testB[j][13] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SIMANN99"));	
			}
			if(testW[j][13] < BestScore){
				testW[j][13] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SIMANN99"));	
			}
			testA[j][13] += BestScore;
			PrintBestSolution();
		}
		testA[j][0] = testA[j][0]/(double)runs;
		testA[j][1] = testA[j][1]/(double)runs;
		testA[j][2] = testA[j][2]/(double)runs;
		testA[j][3] = testA[j][3]/(double)runs;
		testA[j][4] = testA[j][4]/(double)runs;
		testA[j][5] = testA[j][5]/(double)runs;
		testA[j][6] = testA[j][6]/(double)runs;
		testA[j][7] = testA[j][7]/(double)runs;
		testA[j][8] = testA[j][8]/(double)runs;
		testA[j][9] = testA[j][9]/(double)runs;
		testA[j][10] = testA[j][10]/(double)runs;
		testA[j][11] = testA[j][11]/(double)runs;
		testA[j][12] = testA[j][12]/(double)runs;
		testA[j][13] = testA[j][13]/(double)runs;
		
	}
	
	cout << "\n\n\nS - Savings"<<
		"\nHC - Hill Climb"
		<<
		"\nSA - Simulated Annealing"
		<<
		"\nLA - Late Acceptance"
		<<
		"\nSC - Step Counting\n" << endl;
	
	cout << "INST\tS\tHC\tLA0\tLA50\tLA75\tLA99\tSC0\tSC50\tSC75\tSC99\tSA0\tSA50\tSA75\tSA99" << endl;		
	for(int i = 0; i < 14; i++){
		cout << i+1;
		for(int j = 0; j < 14; j++){
			cout << "\t" << testB[i][j];
		}		
		cout << "\n" << i+1;
		for(int j = 0; j < 14; j++){
			cout << "\t" << testA[i][j];
		}
		cout << "\n" << i+1;
		for(int j = 0; j < 14; j++){
			cout << "\t" << testW[i][j];
		}
		cout << "\n" << endl;
	}
}



/*******************************************************************************************************************************************************/

		

void FinalUchoa(int runs, int f, int t){

	double testB[100][14];
	double testA[100][14];
	double testW[100][14];
	
	
	
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 14; j++){
			testB[i][j] = INF;
			testA[i][j] = 0.0;
			testW[i][j] = -INF;
		}
	
	srand (time(NULL));
	for(int j = f; j < t; j++){
		string file = "../Benchmarks/Uchoa/b/";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".vrp";

		LoadAugerat(filen);

		ComputeDistance();		

		srand (time(NULL));
		//double lambda = 0.0;
		double bt,et;
		
		cout << "Loading file: " << filen << endl;
		
		for(int i = 0; i < runs; i++){
			stringstream srun;
			srun << i+1;
			cout << "Run n. " << i+1 << "/" << runs << endl;
			//lambda = (double)((rand()%20) + 1)/10;
			
			AlgorithmSavings();
			if(testB[j][0] > BestScore){
				testB[j][0] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SAVINGS"));	
			}
			if(testW[j][0] < BestScore){
				testW[j][0] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SAVINGS"));	
			}
			testA[j][0] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmHillClimb();
			if(testB[j][1] > BestScore){
				testB[j][1] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_HILLCLIMB"));	
			}
			if(testW[j][1] < BestScore){
				testW[j][1] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_HILLCLIMB"));	
			}
			testA[j][1] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmLAHC(10000, 10000000);
			if(testB[j][2] > BestScore){
				testB[j][2] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_LAHC0"));	
			}
			if(testW[j][2] < BestScore){
				testW[j][2] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_LAHC0"));	
			}
			testA[j][2] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmLAHC(10000, 10000000, (int)(10.0*log(K)));
			if(testB[j][3] > BestScore){
				testB[j][3] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_LAHC50"));	
			}
			if(testW[j][3] < BestScore){
				testW[j][3] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_LAHC50"));	
			}
			testA[j][3] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmLAHC(10000, 10000000, (int)(10.0*log(K)), 200);
			if(testB[j][4] > BestScore){
				testB[j][4] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_LAHC75"));	
			}
			if(testW[j][4] < BestScore){
				testW[j][4] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_LAHC75"));	
			}
			testA[j][4] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmLAHC(10000, 10000000, (int)(10.0*log(K)), INF);
			if(testB[j][5] > BestScore){
				testB[j][5] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_LAHC99"));	
			}
			if(testW[j][5] < BestScore){
				testW[j][5] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_LAHC99"));	
			}
			testA[j][5] += BestScore;
			PrintBestSolution();
			
						
			AlgorithmSavings();
			AlgorithmSCHC(10000, 10000000);
			if(testB[j][6] > BestScore){
				testB[j][6] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SCHC0"));	
			}
			if(testW[j][6] < BestScore){
				testW[j][6] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SCHC0"));	
			}
			testA[j][6] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmSCHC(10000, 10000000, (int)(10.0*log(K)));
			if(testB[j][7] > BestScore){
				testB[j][7] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SCHC50"));	
			}
			if(testW[j][7] < BestScore){
				testW[j][7] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SCHC50"));	
			}
			testA[j][7] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmSCHC(10000, 10000000, (int)(10.0*log(K)), 200);
			if(testB[j][8] > BestScore){
				testB[j][8] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SCHC75"));	
			}
			if(testW[j][8] < BestScore){
				testW[j][8] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SCHC75"));	
			}
			testA[j][8] += BestScore;
			PrintBestSolution();
			
			
			AlgorithmSavings();
			AlgorithmSCHC(10000, 10000000, (int)(10.0*log(K)), INF);
			if(testB[j][9] > BestScore){
				testB[j][9] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SCHC99"));	
			}
			if(testW[j][9] < BestScore){
				testW[j][9] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SCHC99"));	
			}
			testA[j][9] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 150);
			if(testB[j][10] > BestScore){
				testB[j][10] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SIMANN0"));	
			}
			if(testW[j][10] < BestScore){
				testW[j][10] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SIMANN0"));	
			}
			testA[j][10] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 150, (int)(10.0*log(K)));
			if(testB[j][11] > BestScore){
				testB[j][11] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SIMANN50"));	
			}
			if(testW[j][11] < BestScore){
				testW[j][11] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SIMANN50"));	
			}
			testA[j][11] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 150, (int)(10.0*log(K)), 200);
			if(testB[j][12] > BestScore){
				testB[j][12] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SIMANN75"));	
			}
			if(testW[j][12] < BestScore){
				testW[j][12] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SIMANN75"));	
			}
			testA[j][12] += BestScore;
			PrintBestSolution();
			
			AlgorithmSavings();
			AlgorithmSimulatedAnnealing(0.99999, 5.0, 0.00001, 150, (int)(10.0*log(K)), INF);
			if(testB[j][13] > BestScore){
				testB[j][13] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_B_SIMANN99"));	
			}
			if(testW[j][13] < BestScore){
				testW[j][13] = BestScore;	
				PlotFile(MakeFileForGnuplot(ss.str() + "_" + srun.str() + "_W_SIMANN99"));	
			}
			testA[j][13] += BestScore;
			PrintBestSolution();
		}
		testA[j][0] = testA[j][0]/(double)runs;
		testA[j][1] = testA[j][1]/(double)runs;
		testA[j][2] = testA[j][2]/(double)runs;
		testA[j][3] = testA[j][3]/(double)runs;
		testA[j][4] = testA[j][4]/(double)runs;
		testA[j][5] = testA[j][5]/(double)runs;
		testA[j][6] = testA[j][6]/(double)runs;
		testA[j][7] = testA[j][7]/(double)runs;
		testA[j][8] = testA[j][8]/(double)runs;
		testA[j][9] = testA[j][9]/(double)runs;
		testA[j][10] = testA[j][10]/(double)runs;
		testA[j][11] = testA[j][11]/(double)runs;
		testA[j][12] = testA[j][12]/(double)runs;
		testA[j][13] = testA[j][13]/(double)runs;
		
	}
	
	cout << "\n\n\nS - Savings"<<
		"\nHC - Hill Climb"
		<<
		"\nSA - Simulated Annealing"
		<<
		"\nLA - Late Acceptance"
		<<
		"\nSC - Step Counting\n" << endl;
	
	cout << "INST\tS\tHC\tLA0\tLA50\tLA75\tLA99\tSC0\tSC50\tSC75\tSC99\tSA0\tSA50\tSA75\tSA99" << endl;		
	for(int i = 0; i < 100; i++){
		cout << i+1;
		for(int j = 0; j < 14; j++){
			cout << "\t" << testB[i][j];
		}		
		cout << "\n" << i+1;
		for(int j = 0; j < 14; j++){
			cout << "\t" << testA[i][j];
		}
		cout << "\n" << i+1;
		for(int j = 0; j < 14; j++){
			cout << "\t" << testW[i][j];
		}
		cout << "\n" << endl;
	}
}

/*******************************************************************************************************************************************************/

		

void TUchoa(int runs, int f, int t){

	double testB[100][14];
	double testA[100][14];
	double testW[100][14];
	
	
	
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 14; j++){
			testB[i][j] = INF;
			testA[i][j] = 0.0;
			testW[i][j] = -INF;
		}
	
	srand (time(NULL));
	for(int j = f; j < t; j++){
		string file = "../Benchmarks/Uchoa/b/";
		stringstream ss;
		ss << j+1;
		string filen = file + ss.str() + ".vrp";

		LoadAugerat(filen);

		ComputeDistance();		

		srand (time(NULL));
		double bt,et;
		
		cout << "Loading file: " << filen << endl;
		
		for(int i = 0; i < runs; i++){
			stringstream srun;
			srun << i+1;
			cout << "Run n. " << i+1 << "/" << runs << endl;
				
			AlgorithmSavings();
			AlgorithmSCHC(333333, 10000000000, (int)(20.0*log(K)), 9999);
			PrintBestSolution();
		}

		
	}
	
	cout << "\n\n\nS - Savings"<<
		"\nHC - Hill Climb"
		<<
		"\nSA - Simulated Annealing"
		<<
		"\nLA - Late Acceptance"
		<<
		"\nSC - Step Counting\n" << endl;
	
	cout << "INST\tS\tHC\tLA0\tLA50\tLA75\tLA99\tSC0\tSC50\tSC75\tSC99\tSA0\tSA50\tSA75\tSA99" << endl;		
	for(int i = 0; i < 100; i++){
		cout << i+1;
		for(int j = 0; j < 14; j++){
			cout << "\t" << testB[i][j];
		}		
		cout << "\n" << i+1;
		for(int j = 0; j < 14; j++){
			cout << "\t" << testA[i][j];
		}
		cout << "\n" << i+1;
		for(int j = 0; j < 14; j++){
			cout << "\t" << testW[i][j];
		}
		cout << "\n" << endl;
	}
}

void FinalKelly(int runs){}
void FinalTaillard(int runs){}
void FinalUSA(int runs){}
