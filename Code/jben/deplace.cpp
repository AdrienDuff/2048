#include <iostream>
#include <cmath>

//#include <cstdlib> //pour la fonction rand 
#include <time.h> 
#include <stdlib.h>

using namespace std; 

//test déplace
void deplace(int t[4]); 
void remplace(int *a, int *b); 

void remplace(int *a, int *b){
	int temp; 
	temp=*a; 
	*a= *b; 
	*b=temp; 
}


void deplace(int t[4]){
	//pour le déplacement à droite on changera le coef 
	int coef = -1; 
	bool ok=false;
	int *p1;
	int *p2;
	while(1){
		ok = false;
		p1 = t + 2; 
		p2 = t + 3; 
		for(int i=0; i<=3; i++){
			
			p1+=coef*i;
			p2+=coef*i; 
			if(*p1 != *p2){
				if(*p2==0){

					*p2=*p1;
					*p1=0; 
					ok=true; 
				}
			}
			else if(*p1==*p2 && *p1 != 0){

				(*p2)*=2;
				*p1=0; 
				ok=true;
			}
			
		}
		if(!ok){
			 break; 
		 }			 
		}
	}


// ---------- class définition ---------- 

class Matrice {
	// ---------- les instances ---------- 
		
	//variables static [] et initialisation   
	static const int n=4; 
	static const int N_MAX=16; 
	
	public : 
		int m[n][n]; 
	
	//---------- constructeurs & destructeurs ---------- 
	Matrice(); //vide 
	Matrice(int); //initialisation des cases avec un int 
	
	 
	//destructeur qui marche pas 
	//~Matrice(); 
	
	
	//---------- méthodes associés ---------- 
	
	//recupération d'un elem  
	int getElem(int, int); 
	int* getLine(int);
	//modification d'un elem
	void setElem(int, int, int);
	//affichage 
	void affiche();
	//initialiser la matrice lors du premier tour 
	void initialisation1(); 
	//génération d'une case aléatoire 
	void generation(); 
	
	//fonction qui servent à déplacer
	void deplaceD(Matrice); 
	 
	void deplaceH(Matrice); 
	void deplaceB(Matrice); 
	void deplaceG(Matrice);  

}; 


// ---------- définition des méthode de la classe ---------- 


//constructeurs 
Matrice::Matrice(int i){
	for(int l=0; l<n; l++){
		for(int j=0; j<n; j++){
			m[l][j]=i; 
		}
	}
}

//constructeur normal >>> tout les élément à 0
Matrice::Matrice(){
	for(int l=0; l<n; l++){
		for(int j=0; j<n; j++){
			m[l][j]=0; 
		}
	}
}

//fonction affichage 
void Matrice::affiche(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << m[i][j] << " ";
		}
		cout << "\n"; 
	}
}

//initialisation1 correspond au premier tour >> faire apparaitre un 2 dans une case random 
void Matrice::initialisation1(){
	//nb aléatoire en utilisant la lib cstdlib >> nb_al = rand() % MAX_VALUE 
	int nb1 = (rand() % 4); 
	int nb2 = (rand() % 4);
	m[nb1][nb2] = 2;
}

//génération d'une case aléatoirement 
void Matrice::generation() {
	
	//choisir une case aléatoirement 
	int nb1, nb2;
	//boucle qui tourne tant que une case vide n'est pas detecté
	while(1) {
		nb1 = (rand() % n); 
		nb2 = (rand() % n);
		if (m[nb1][nb2] == 0) {
			break;
		}
	}
	//on génère un 2 ou un 4 et on le mets dans une case vide 
	int nb_bis = (int) (((rand() % 2) +1)*2); 
	m[nb1][nb2] = nb_bis; 
	
}


//déplacement à droite 
/*
void Matrice::deplaceD(Matrice m){
	
}*/


//get 
int Matrice::getElem(int i, int j){
	return m[i][j]; 
}

int* Matrice::getLine(int i){
	int tabtemp[4]; 
	int *p=tabtemp; 
	for(int j=0; j<4; j++){
		tabtemp[j]=m[i][j]; 
	}
	return p;
}

//set 
void Matrice::setElem(int i, int j, int elem){
	m[i][j] = elem; 
}





// ---------- main class ----------  

int main() {
	//pour avoir un VRAI aléatoire 
	srand(time(NULL));

	Matrice mat1;
	Matrice mat2(1); 
	mat1.initialisation1(); 
	
	cout << " ---------- test sur la matrice ---------- " << endl;
	mat1.affiche();
	
	cout << " ---------- test de GENERATION sur la matrice ---------- " << endl;
	mat1.generation();
	mat1.generation();
	mat1.generation(); 
	mat1.affiche(); 
	
	
	cout << " ---------- test algo comparaison ---------- " << endl;

	int tab[4] = {0,2,0,2}; 
	//deplace(tab); 
	
	cout << " ---------- tab AVANT ---------- " << endl;

	for(int i=0; i<4; i++){
		cout << tab[i] << "\t"; 
	}
	

	cout << endl; 
	cout << " ---------- tab APRÈS ---------- " << endl;
	deplace(tab); 
	for(int i=0; i<4; i++){
		cout << tab[i] << "\t"; 
	}


	
	cout << "\n"; 
	cout << "c'est bon y'a pas de problème " << endl; 
	return 0; 
	
}
