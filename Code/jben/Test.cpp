//
//  Test.cpp
//  
//
//  Created by Benjamin DALLARD on 21/01/2017.
//
//

#include "Test.hpp"
#include <iostream>
#include <vector>

//#definde N 4 


using namespace std;

class Matrix
{
private:
vector< vector<int> > Mat;
//constructeur normal 
Matrix() {};

public:
//constructeur 
Matrix(vector< vector<int> > mat): Mat(mat) {cout << "constructeuur" << endl;};


//construction d'un obj matrice qui pointe vers la case mémoire de l'obj de base 
//constructeur copie? 
// *** CONST methode de lecture seul  ?? pas compris *** 
Matrix(const Matrix &rhs);

//get & set 
int getnum(int r, int c)const {return Mat[r][c];};
int getrow()const {return (Mat.size());};
int getcol()const {return (Mat[0].size());};

//surcharge op
Matrix Matrix::operator+(const Matrix &rhs);


};    
    
    
// ?? surcharge qui marche pas ??     
    
Matrix Matrix::operator+(const Matrix &rhs) {
	//def d'une matrice temporaire 
vector< vector<int> > temp(getrow(), vector<int>(getcol(), 0));
Matrix Temp(temp);

//conditions
if((getrow() != rhs.getrow()) || (getcol() != rhs.getcol()))
{
    cout << "on peut pas add ces deux la" << endl;
    exit(1);
}

for(int i=0; i < Temp.getrow(); i++){
    for(int j=0; j < Temp.getcol(); j++){
        Temp.Mat[i][j] = getnum(i, j) + rhs.getnum(i, j);
	}
}
return Temp;
}

    



int main()
{
	//changer ligne et colone 
	int dim=4; 
	vector< vector<int> > vect; 
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			vect[i].push_back(0); 
		}
	}
	
	
    cout << "Hello world!" << endl;
    return 0;
}
