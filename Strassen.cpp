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
