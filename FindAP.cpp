/*

Find missing number in the Arithmetic Progression

*/

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
void findAP(vector<int> &A, int tam);

/*Functions*/
void findAP(vector<int> &A, int tam){

	//razão da PA
	int r = (A[tam] - A[0])/tam;
	int missing = 0;


	if (tam > 2)
	{
		int novoTam = tam/2;
		for (int i = 0; i < novoTam; ++i){
			A2[i] = A[i];
		}
		for (int i = 0; i <= novoTam; ++i){
			A3[i] = A[novoTam + i];
		}
		findAP(A2,novoTam);
		findAP(A3,novoTam);
	}
	else{
		r2 = A[1] - A[0];
		if (r2 == r)
		{
			return true;
		}
		else{
			return false
			missing = A[0] + r;
		}
	}
}
