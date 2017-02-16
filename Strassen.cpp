#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
/*

	@author : Ricardo Fragoso

*/

/*Constructors*/

void read(string filename, vector<vector<int>> &A, vector<vector<int>> &B);
void soma(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int tam);
void sub(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int tam);
void strassen(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int tam);
void matrixsize(string filename);
void printmatrix(vector< vector<int> > matrix, int n));

/*Functions*/

void read(string filename, vector<vector<int>> &A, vector<vector<int>> &B){
	string line;
	FILE* matrixfile = fopen(filename.c_str(), "r", stdin);

	if(matrixfile == 0){
			cerr << "Could not read file" << filename << endl;
			return;
	}

	int i = 0, j, a;
	while (getline(cin, line) && !line.empty()){
		istringstream iss(line);
		j = 0;
		while(iss >> a){
			A[i][j] = a;
			j++;
		}
		i++;

	}
	while(getline(cin, line)){
		istringstream iss(line);
		j = 0;
		while (iss >> a){
			B[i][j] = a;
			j++;
		}
		i++;
	}

	fclose(matrixfile);
}

void soma(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int tam){
	int i, j;
	for(i = 0; i<tam; i++)
		for(j = 0; j < tam; j++){
			C[i][j] = A[i][j] + B[i][j];
		}
}

void sub(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int tam){
	int i, j;
	for(i = 0; i<tam; i++){
		for(j = 0; j < tam; j++){
			C[i][j] = A[i][j] - B[i][j];
		}
	}
}

void strassen(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int tam){

	int i, j; // tamanho das linhas e colunas

	for(int k; k > i; k--){
		for(int l; l > j; l--){
			C[k][l] = A[k/2][l/2];
		}

	}














}

void matrixsize(vector<vector<int>> &D){

}
