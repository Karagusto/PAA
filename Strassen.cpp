#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Set LEAF_SIZE to 1 if you want to the pure strassen algorithm
// otherwise, the ikj-algorithm will be applied when the split
// matrices are as small as LEAF_SIZE x LEAF_SIZE
int leafsize;

using namespace std;

/*
 * Implementation of the strassen algorithm, similar to 
 * http://en.wikipedia.org/w/index.php?title=Strassen_algorithm&oldid=498910018#Source_code_of_the_Strassen_algorithm_in_C_language
 */

/*Constructors*/

void read(string filename, vector<vector<int>> &A, vector<vector<int>> &B);
void soma(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int tam);
void sub(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int tam);
void divConq(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int n);
void strassenR(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int tam);
void strassen(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, unsigned int tam);
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
	for(i = 0; i<tam; i++)
		for(j = 0; j < tam; j++){
			C[i][j] = A[i][j] - B[i][j];
}

void divConq(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int n){

}
