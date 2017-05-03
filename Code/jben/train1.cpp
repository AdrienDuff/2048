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
	bool ok=false; 
	while(!ok){
		int *p1;
		int *p2;
	
	
		/*
		 * 
		 * for (p1 = t+3; p1 != t; p1--)
		 * {
		 * 		p2 = p1 - 1;
		 * 		while (*p2 != 0
		 * }
		 * 		
		 * 
		 * 	* 
			*/
			for(int i=0; i<4; i++){
				//t =pointeur obj sur le 1er elem du tab >>>> p1 = &t[i]
				p1 = t + 4; 
				for(int j=i+1; j<4; j++){
					p2 = t + j; 
					if(*p1==*p2){
						*p1=0; 
						//t[i]=0; 
						//t[j]*=2;
						(*p2) *= 2; 
					}
				}
			}
			 
			ok=true; 
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
	//modification d'un elem
	void setElem(int, int, int);
	//affichage 
	void affiche();
	//initialiser la matrice lors du premier tour 
	void initialisation1(); 
	//génération d'une case aléatoire 
	void generation(); 
	
	//fonction qui servent à déplacer 
	void deplaceH(Matrice m); 
	void deplaceB(Matrice m); 
	void deplaceD(Matrice m); 
	void deplaceG(Matrice m);  

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
	//srand(time(NULL));
	int nb2 = (rand() % 4);
	m[nb1][nb2] = 2;
}

//génération d'une case aléatoirement 
void Matrice::generation() {
	
	//choisir une case aléatoirement 
	int nb1, nb2;
	//boucle qui tourne tant que une case vide n'est pas detecté
	//srand(time(NULL)); 
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
void Matrice::deplaceD(Matrice mat){
	for(int i=0; i<n; i++){
		bool modif = true; 
		while(modif){
			int *p; 
			for(int j=1; j<n; j++){
				p = &m[i][j-1]; 
				//si p pointe sur 0
				if(*p==0){
					p = &m[i][j]; 
				}
				else if (p==&m[i][j]){
					m[i][j]=0; 
					(*p)*2; 
				}
				modif=false;
			}
		}
	}
}

//get 
int Matrice::getElem(int i, int j){
	return m[i][j]; 
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
