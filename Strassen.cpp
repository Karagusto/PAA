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
void strassen(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int tam);
void Multmatrix(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C);


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


void strassen(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int tam){

	int i, j; // tamanho das linhas e colunas

	if(tam <= 2){
		Multmatrix(A, B, C);
	}

	else{
	// dividindo as matrizes em 4 submatrizes
	int novoTam = tam/2;
	vector<vector<int>> a11, a12, a21, a22, b11, b12, b21, b22, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, P1, P2, P3, P4, P5, P6, P7;

	int i, j;
	
		for(i = 0; i < novoTam; i++){
			for(j = 0; j <novoTam; j++){
				a11[i][j] = A[i][j];
				a12[i][j] = A[i][j + novoTam];
				a21[i][j] = A[i + novoTam][j];
				a22[i][j] = A[i + novoTam][j + novoTam];

				b11[i][j] = B[i][j];
				b12[i][j] = B[i][j + novoTam];
				b21[i][j] = B[i + novoTam][j];
				b22[i][j] = B[i + novoTam][j + novoTam];
			}	
		}

// Calculando S1 a S10

		S1 = b12 - b22;
		S2 = a11 + a12;
		S3 = a21 + a22;
		S4 = b21 - b11;
		S5 = a11 + a22;
		S6 = b11 + b22;
		S7 = a12 - a22;
		S8 = b21 + b22;
		S9 = a11 - a21;
		S10 = b11 + b12;

// Calculando P1 a P8

		strassen(a11, S1, P1, novoTam);
		strassen(S2, b22, P2, novoTam);
		strassen(S3, b11, P3, novoTam);
		strassen(a22, S4, P4, novoTam);
		strassen(S5, S6, P5, novoTam);
		strassen(S7, S8, P6, novoTam);
		strassen(S9, S10, P7, novoTam);
// Colocando valores na  matriz resultado C

		C[0][0] = P5 + P4 - P2 + P6;
		C[1][0] = P1 + P2;
		C[0][1] = P3 + P4;
		C[1][1] = P5 + P1 - P3 - P7;
}
void Multmatrix(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C){

}









