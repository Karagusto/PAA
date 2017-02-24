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
	
	//int missing = 0;


	if (tam > 2)
	{
		int novoTam = tam/2;
		vector<int> A2(novoTam), A3(novoTam);
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
		int r2 = A[1] - A[0];
		if (r2 != r)
		{
			cout <<  A[0] + r << endl;
		}else{
			cout << "não tem erro!" << endl;
		}
	}
}

int main (int argc, char* argv[]) {
    
    int N, T;
    vector<int> A(N);
    //cout << "tá entrando" << endl;
    cin >> T;
    while(T > 0){
    	cout << "entrouT" << endl;
    	cin >> N;
    
    		for(int i = 0; i <= N; ++i){
    			cout << "entrouN" << endl;
    			cin >> A[i]; 
    		}
    	/*for(int i = 0; i<N; ++i){
    	//cout << A[i] ;
		}*/

    	findAP(A,N);
    	T--;
    }
    return 0;


}