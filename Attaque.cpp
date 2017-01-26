
#include "Attaque.hpp"
#include <iostream>
#include <string>

#include <stdlib.h>

using namespace std;

Attaque::Attaque(){

}

Attaque::Attaque(string nom){
		this->nom=nom;
		this->physique=false;
		this->puissance=30;
		this->type=Type("Eau");
		this->pp=15;

}
Attaque::Attaque(string nom,Type type,int pp){

		this->nom=nom;
		this->physique=false;
		this->puissance=0;
		this->type=type;
		this->pp=pp;
		this->ppFixe=pp;
        this->precision=100;
}
Attaque::Attaque(string nom, int puissance, bool physique, Type type,int pp, int precision){

		this->nom=nom;
		this->physique=physique;
		this->puissance=puissance;
		this->pp=pp;
		this->type = type;
		this->ppFixe=pp;
		this->precision=precision;

}
Attaque::Attaque(string nom, int puissance, bool physique, Type type,int pp){

		this->nom=nom;
		this->physique=physique;
		this->puissance=puissance;
		this->pp=pp;
		this->type = type;
		this->ppFixe=pp;
		this->precision=100;

}

Attaque::Attaque(string nom, Type type,int pp, int precision){

		this->nom=nom;
		this->physique=physique;
		this->puissance=puissance;
		this->pp=pp;
		this->type = type;
		this->ppFixe=pp;
		this->precision=precision;

}

Attaque::~Attaque(){

	//	cout <<"Destruction attaque"<<endl;

}

void Attaque::setPP(int pp){
    this->pp=pp;
}

int Attaque::getPPfixe(){
return this->ppFixe;
}

int Attaque::getPP(){
return this->pp;
}

string Attaque::getNom(){

return this->nom;
}

void Attaque::setPrecision(int precision){

    this->precision=precision;
}

int Attaque::getPrecision(){

return this->precision;
}

void Attaque::toString(){

    cout<<"Nom "<<this->nom;
    cout<<" Puissance "<<this->puissance;
    cout<<" Physique "<<this->physique;
    cout<<" Type "<<this->type.getNom();
    cout<<" PP "<<this->pp<<endl;

}

int Attaque::getPuissance(){

    return this->puissance;
}

bool Attaque::getPhysique(){

    return this->physique;
}

Type Attaque::getType(){

    return this->type;

}

