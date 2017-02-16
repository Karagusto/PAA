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
/*
	int i, j; // tamanho das linhas e colunas

	if(i == 2 && j == 2){
		strassenMult(A, B, C);
	}
	else{
		for(int k; k > i; k--){
			for(int l; l > j; l--){
				C[k][l] = A[k/2][l/2];
			}
		}
	}
}*/

	// dividindo as matrizes em 4 submatrizes
	int novoTam = tam/2;
	vector<vector<int>> a11, a12, a21, a22, b11, b12, b21, b22;

	int i, j;
	while(novoTam > 2){
		for(i = 0; i < novoTam; i++){
			for(j = 0; j <novoTam; j++){
				a11[i][j] = A[i][j];
				a12[i][j] = A[i][j + novoTam];
				a21[i][j] = A[i + novoTam][j];
				a22[i][j] = A[i + novoTam][j + novoTam];

				b11[i][j] = b[i][j];
				b12[i][j] = b[i][j + novoTam];
				b21[i][j] = b[i + novoTam][j];
				b22[i][j] = b[i + novoTam][j + novoTam];
			}	
		}
novoTam = novoTam/2;
	}
}
void strassenMult(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C){


}

void matrixsize(vector<vector<int>> &D){

}






