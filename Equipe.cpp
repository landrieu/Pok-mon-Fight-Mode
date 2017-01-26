#include "Equipe.hpp"
#include "Pokemon.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Equipe::Equipe()
{

}
Equipe::Equipe(Pokemon pkmn)
{
	equipe.push_back(pkmn);

}
Equipe::Equipe(Pokemon pkmn1, Pokemon pkmn2)
{
	equipe.push_back(pkmn1);
	equipe.push_back(pkmn2);

}
Equipe::Equipe(Pokemon pkmn1, Pokemon pkmn2,Pokemon pkmn3)
{
	equipe.push_back(pkmn1);
	equipe.push_back(pkmn2);
	equipe.push_back(pkmn3);

}
Equipe::Equipe(Pokemon p1,Pokemon p2,Pokemon p3,Pokemon p4,Pokemon p5,Pokemon p6)//p⁵
{

	equipe.push_back(p1);
	equipe.push_back(p2);
	equipe.push_back(p3);
	equipe.push_back(p4);
	equipe.push_back(p5);
	equipe.push_back(p6);

}

void Equipe::affiche(){

unsigned int i;

    for (i=0;i<this->getListePokemon().size();i++){

        cout<<"Pokemon "<<i+1<<" : "<<this->getListePokemon()[i].getNom()<<endl;

    }
}

bool Equipe::estVide(){
    bool vide=false;

    if (this->getListePokemon().empty())
        vide=true;

return vide;
}

vector<Pokemon> Equipe::getListePokemon(){

	return this->equipe;

}

void Equipe::removePokemon(int n)
{
	this->equipe.erase(this->equipe.begin()+n);

}


void Equipe::addPokemon(Pokemon p){

this->equipe.push_back(p);
}

void Equipe::insertPokemon(Pokemon p, int n){

   this->equipe.insert(this->equipe.begin()+n,p);
}

