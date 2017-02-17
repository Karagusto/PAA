#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>

using namespace std;
/*

	@author : Ricardo Fragoso

*/

/*Constructors*/

void read(string filename, vector<vector<int> > &A, vector<vector<int> > &B);
void strassen(vector<vector<int> > &A, vector<vector<int> > &B, vector<vector<int> > &C, int tam);
void multmatrix(vector<vector<int> > &A, vector<vector<int> > &B, vector<vector<int> > &C, int n);
void sum(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int tam);
void subtract(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int tam);
void printMatrix(vector< vector<int> > matrix, int n);

/*Functions*/

void read(string filename, vector<vector<int> > &A, vector<vector<int> > &B){
	string line;
	FILE* matrixfile = freopen(filename.c_str(), "r", stdin);

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
			B[i][j] = a;
			j++;
		}
		i++;

	}
	/*while(getline(cin, line)){
		istringstream iss(line);
		j = 0;
		while (iss >> a){
			B[i][j] = a;
			j++;
		}
		i++;
	}*/

	fclose(matrixfile);
}


void strassen(vector<vector<int> > &A, vector<vector<int> > &B, vector<vector<int> > &C, int tam){

/*
	if (tam <= 1) {
        multmatrix(A, B, C, tam);
        return;
    }

    // other cases are treated here:
    else {
        int newTam = tam/2;
        vector<int> inner (newTam);
        vector< vector<int> > 
            a11(newTam,inner), a12(newTam,inner), a21(newTam,inner), a22(newTam,inner),
            b11(newTam,inner), b12(newTam,inner), b21(newTam,inner), b22(newTam,inner),
              c11(newTam,inner), c12(newTam,inner), c21(newTam,inner), c22(newTam,inner),
            p1(newTam,inner), p2(newTam,inner), p3(newTam,inner), p4(newTam,inner), 
            p5(newTam,inner), p6(newTam,inner), p7(newTam,inner),
            aResult(newTam,inner), bResult(newTam,inner);

        int i, j;

        //dividing the matrices in 4 sub-matrices:
        for (i = 0; i < newTam; i++) {
            for (j = 0; j < newTam; j++) {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + newTam];
                a21[i][j] = A[i + newTam][j];
                a22[i][j] = A[i + newTam][j + newTam];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + newTam];
                b21[i][j] = B[i + newTam][j];
                b22[i][j] = B[i + newTam][j + newTam];
            }
        }

        // Calculating p1 to p7:

        sum(a11, a22, aResult, newTam); // a11 + a22
        sum(b11, b22, bResult, newTam); // b11 + b22
        strassen(aResult, bResult, p1, newTam); // p1 = (a11+a22) * (b11+b22)

        sum(a21, a22, aResult, newTam); // a21 + a22
        strassen(aResult, b11, p2, newTam); // p2 = (a21+a22) * (b11)

        subtract(b12, b22, bResult, newTam); // b12 - b22
        strassen(a11, bResult, p3, newTam); // p3 = (a11) * (b12 - b22)

        subtract(b21, b11, bResult, newTam); // b21 - b11
        strassen(a22, bResult, p4, newTam); // p4 = (a22) * (b21 - b11)

        sum(a11, a12, aResult, newTam); // a11 + a12
        strassen(aResult, b22, p5, newTam); // p5 = (a11+a12) * (b22)   

        subtract(a21, a11, aResult, newTam); // a21 - a11
        sum(b11, b12, bResult, newTam); // b11 + b12
        strassen(aResult, bResult, p6, newTam); // p6 = (a21-a11) * (b11+b12)

        subtract(a12, a22, aResult, newTam); // a12 - a22
        sum(b21, b22, bResult, newTam); // b21 + b22
        strassen(aResult, bResult, p7, newTam); // p7 = (a12-a22) * (b21+b22)

        // calculating c21, c21, c11 e c22:

        sum(p3, p5, c12, newTam); // c12 = p3 + p5
        sum(p2, p4, c21, newTam); // c21 = p2 + p4

        sum(p1, p4, aResult, newTam); // p1 + p4
        sum(aResult, p7, bResult, newTam); // p1 + p4 + p7
        subtract(bResult, p5, c11, newTam); // c11 = p1 + p4 - p5 + p7

        sum(p1, p3, aResult, newTam); // p1 + p3
        sum(aResult, p6, bResult, newTam); // p1 + p3 + p6
        subtract(bResult, p2, c22, newTam); // c22 = p1 + p3 - p2 + p6

        // Grouping the results obtained in a single matrix:
        for (i = 0; i < newTam ; i++) {
            for (j = 0 ; j < newTam ; j++) {
                C[i][j] = c11[i][j];
                C[i][j + newTam] = c12[i][j];
                C[i + newTam][j] = c21[i][j];
                C[i + newTam][j + newTam] = c22[i][j];
            }
        }
    }



}

	*/int i, j; // tamanho das linhas e colunas

	if(tam <= 1){
		multmatrix(A, B, C, tam);
		return;
	}

	else{
	// dividindo as matrizes em 4 submatrizes
	int novoTam = tam/2;
	vector<int> inner (novoTam);
	vector<vector<int> > a11(novoTam, inner), a12(novoTam, inner), a21(novoTam, inner), a22(novoTam, inner), b11(novoTam, inner), b12(novoTam, inner), 
	b21(novoTam, inner), b22(novoTam, inner), S1(novoTam, inner), S2(novoTam, inner), S3(novoTam, inner), S4(novoTam, inner), S5(novoTam, inner), 
	S6(novoTam, inner), S7(novoTam, inner), S8(novoTam, inner), S9(novoTam, inner), S10(novoTam, inner), P1(novoTam, inner), P2(novoTam, inner), 
	P3(novoTam, inner), P4(novoTam, inner), P5(novoTam, inner), P6(novoTam, inner), P7(novoTam, inner), c11(novoTam, inner), c12(novoTam, inner), 
	c21(novoTam, inner), c22(novoTam, inner), c11result(novoTam, inner), c11result2(novoTam, inner), c22result(novoTam, inner), c22result2(novoTam, inner);
/*
	vector<vector<int> > a11(novoTam), a12(novoTam), a21(novoTam), a22(novoTam), b11(novoTam), b12(novoTam), b21(novoTam), b22(novoTam), S1(novoTam), S2(novoTam), S3(novoTam), S4(novoTam), S5(novoTam), S6(novoTam), S7(novoTam), S8(novoTam), 
	S9(novoTam), S10(novoTam), P1(novoTam), P2(novoTam), P3(novoTam), P4(novoTam), P5(novoTam), P6(novoTam), P7(novoTam), c11(novoTam), c12(novoTam), 
	c21(novoTam), c22(novoTam), c11result(novoTam), c11result2(novoTam), c22result(novoTam), c22result2(novoTam);
	*/
	int i, j;
	
		for(i = 0; i < novoTam; i++){
			for(j = 0; j < novoTam; j++){
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

		subtract(b12, b22, S1, novoTam);
		sum(a11, a12, S2, novoTam);
		sum(a21, a22, S3, novoTam);
		subtract(b21, b11, S4, novoTam);
		sum(a11, a22, S5, novoTam);
		sum(b11, b22, S6, novoTam);
		subtract(a12, a22, S7, novoTam);
		sum(b21, b22, S8, novoTam);
		subtract(a11, a21, S9, novoTam);
		sum(b11, b12, S10, novoTam);

// Calculando P1 a P8

		strassen(a11, S1, P1, novoTam);
		strassen(S2, b22, P2, novoTam);
		strassen(S3, b11, P3, novoTam);
		strassen(a22, S4, P4, novoTam);
		strassen(S5, S6, P5, novoTam);
		strassen(S7, S8, P6, novoTam);
		strassen(S9, S10, P7, novoTam);

// Calculando os valores de C
		sum(P5, P4, c11result, novoTam); // c11 = P5 + P4
        subtract(c11result, P2, c11result2, novoTam); //c11 = P5 + P4 - P2
        sum(c11result2, P6, c11, novoTam); // c11 = P5 + P4 - P2 + P6

        sum(P1, P2, c12, novoTam); // c12 = P1 + P2

        sum(P3, P4, c21, novoTam); // c21 = P3 + P4
        
        sum(P1, P5, c22result, novoTam); // c22 =  P1 + P5
        subtract(c22result, P3, c22result2, novoTam); // c22 = P1 + P5 - P3
		subtract(c22result2, P7, c22, novoTam); // c22 = P1 + P5 - P3 - P7



// Colocando valores na  matriz resultado C por recursividade


		for (i = 0; i < novoTam ; i++) {
            for (j = 0 ; j < novoTam ; j++) {
                C[i][j] = c11[i][j];
                C[i][j + novoTam] = c12[i][j];
                C[i + novoTam][j] = c21[i][j];
                C[i + novoTam][j + novoTam] = c22[i][j];
            }
        }
		
}


void multmatrix(vector<vector<int> > &A, vector<vector<int> > &B, vector<vector<int> > &C, int n){
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void sum(vector< vector<int> > &A, 
         vector< vector<int> > &B, 
         vector< vector<int> > &C, int tam) {
    int i, j;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(vector< vector<int> > &A, 
              vector< vector<int> > &B, 
              vector< vector<int> > &C, int tam) {
    int i, j;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }   
}

void printMatrix(vector< vector<int> > matrix, int n) {
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            if (j != 0) {
                cout << "\t";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

int main (int argc, char* argv[]) {
string filename;
    if (argc < 3) {
        filename = "e.in";
    } else {
        filename = argv[2];
    }

   
    int n = 512;
    vector<int> inner (n);
    vector< vector<int> > A(n, inner), B(n, inner), C(n, inner);
    read (filename, A, B);
    strassen(A, B, C, n);
    printMatrix(C, n);
    
    return 0;


}







