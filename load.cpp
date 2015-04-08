#include "load.h"

//********************************************************************************
void LoadChristofidesEilon(const string &file){
	ifstream is;
	problem_name = file;
	
	is.open(file.c_str());
	is >> K >> Q >> MRT >> DT;
	is >> x[0] >> y[0]; d[0] = 0;
	for(int i = 1; i <= K; i++){
		is >> x[i] >> y[i] >> d[i];
	}
}

//********************************************************************************
void LoadKelly(const string &file, double & optimal){
	ifstream is;
	problem_name = file;
	is.open(file.c_str());
	is >> K >> Q >> MRT >> DT >> optimal;
	
	for(int i = 0; i <= K; i++){
		is >> x[i] >> y[i] >> d[i];
	}
}
//********************************************************************************
void LoadTaillard(const string &file, double & optimal){
	ifstream is;
	problem_name = file;
	is.open(file.c_str());
	is >> K >> optimal >> Q;
	MRT = INF; DT = 0;
	is >> x[0] >> y[0];d[0] = 0;
	int num;
	for(int i = 1; i <= K; i++){
		is >> num >> x[i] >> y[i] >> d[i];
		if(num != i)
			cout << "FILE ERROR" <<endl;
	}
}

//********************************************************************************
void LoadSolomon(const string &file){
	ifstream is;
	string empty;
	int lnum;
	int null;
	problem_name = file;
	MRT = INF; DT = 0;
	
	is.open(file.c_str());
	is >> empty;
	getline(is,empty);
	getline(is,empty);
	getline(is,empty);
	getline(is,empty);
	is >> K >> Q;
	getline(is,empty);
	getline(is,empty);
	getline(is,empty);
	getline(is,empty);
	for(int i = 0; i <= K; i++){
		is >> lnum >> x[lnum] >> y[lnum] >> d[lnum] >> null >> null >> null;
		if(lnum != i)
			cout << "ERROR IN INPUT FILE" << endl;
	}
}

//********************************************************************************
void LoadAugerat(const string &file){
	ifstream is;
	string empty;
	int lnum;
	problem_name = file;
	MRT = INF; DT = 0;
	
	is.open(file.c_str());
	is >> empty >> empty >> empty;
	getline(is,empty);
	getline(is,empty);
	getline(is,empty);
	is >> empty >> empty >> K;
	getline(is,empty);
	getline(is,empty);
	is >> empty >> empty >> Q;
	getline(is,empty);
	getline(is,empty);
	
	for(int i = 0; i < K; i++){
		is >> lnum;
		lnum--;
		is >> x[lnum] >> y[lnum];
		if(lnum != i)
			cout << "ERROR IN INPUT FILE" << endl;
	}
	getline(is,empty);
	getline(is,empty);
	for(int i = 0; i < K; i++){
		is >> lnum;
		lnum--;
		is >> d[lnum];
		if(lnum != i)
			cout << "ERROR IN INPUT FILE" << endl;
	}
	getline(is,empty);
	getline(is,empty);
	int ldepot1, ldepot2;
	K--;
	is >> ldepot1 >> ldepot2;
	if(!((ldepot1 == 1) && (ldepot2 == -1)))
		cout << "DEPOT ERROR IN INPUT FILE" << endl;
}
//********************************************************************************
void LoadLi(const string &file, double & best){
	ifstream is;
	string empty;
	int lnum;
	problem_name = file;
	
	is.open(file.c_str());
	getline(is,empty);
	is >> empty >> best;
	getline(is,empty);
	getline(is,empty);
	is >> empty >>  K;K--;
	is >> empty >>  Q;
	is >> empty >>  MRT;
	DT = 0;
	getline(is,empty);
	getline(is,empty);
	getline(is,empty);
	getline(is,empty);
	getline(is,empty);
	for(int i = 1; i <= K; i++){
		is >> lnum;
		is >> x[lnum] >> y[lnum];
		if(lnum != i)
			cout << "ERROR IN INPUT FILE" << endl;
	}
	getline(is,empty);
	getline(is,empty);
	for(int i = 1; i <= K; i++){
		is >> lnum;
		is >> d[lnum];
		if(lnum != i)
			cout << "ERROR IN INPUT FILE" << endl;
	}
	getline(is,empty);
	getline(is,empty);
	is >> x[0] >> y[0];
	d[0] = 0;
	int ldepot1;
	
	is >> ldepot1;
	if(ldepot1 != -1)
		cout << "DEPOT ERROR IN INPUT FILE" << endl;
}
