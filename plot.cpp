#include "plot.h"

//********************************************************************************
void PlotFile(string file){
	//to keep the window open
	//string call = "C:\\\"Program Files (x86)\"\\gnuplot\\bin\\gnuplot.exe -persist info\\" + file;
	string call = "C:\\\"Program Files (x86)\"\\gnuplot\\bin\\gnuplot.exe info\\" + file;
	system(call.c_str());
	
	
}


string MakeFileForGnuplot(string name){
	
	
	ofstream out;
	
	
	string dfile = "dat\\" + name + ".dat";
	out.open(dfile.c_str());
	
	int routes = 0;
	for(int i = 1; i <= K; i++){
		if(BestRouteStart[i] != 0){
			routes++;
			int from = BestRouteStart[i];
			int to = BestPath[from].next;
			
			//out << "#Route#" << routeNum++ << ": " << from;
			/*
			while(to != 0){
				out << " " << to;
				from = to;
				to = path[to].next;	
			}
			out << endl;
			*/
			
			from = BestRouteStart[i];
			to = BestPath[from].next;
			out << "#X Y"<<endl;
			out << x[0] << " " << y[0] << endl;
			out << x[from] << " " << y[from] << endl;
			
			while(to != 0){
				out << x[to] << " " << y[to] << endl;
				from = to;
				to = BestPath[to].next;	
			}
			
			out << x[0] << " " << y[0] << endl;
			
			out << endl<<endl;
			
			
			
			
		}
	}
	out.close();
     
     
	string file = "info\\" + name + ".info";
	out.open(file.c_str());
	out << "set terminal png size 1280,960\nset output 'png\\" << name << ".png'"<<endl;
	for(int i = 0; i < routes; i++){
		out << "set style line " << i+1 << " lc rgb '#" << rand()%10<<rand()%10<<rand()%10<<rand()%10<<rand()%10<<rand()%10<< "' lt 1 lw 2 pt 7 ps 1.5" << endl;
	}
	out << "plot 'dat\\" << name << ".dat' index 0 with linespoints ls 1";
	for(int i = 1; i < routes; i++){
		out << ", '' index "<< i <<" with linespoints ls " << i+1;
	}
	out << endl;
	
	 
	out.close();
	
	
	
	return name + ".info";
}
