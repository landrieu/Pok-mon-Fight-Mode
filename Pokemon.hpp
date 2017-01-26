#ifndef POKEMON_HPP
#define POKEMON_HPP
#include <string>
#include "Attaque.hpp"

using namespace std;

class Pokemon{

	private:
		int attack;
		int defense;
		int speAttack;
		int speDefense;
		int vitesse;
		int pv;
		int niveau;
		int PVfixe;
		int attackFixe;
		int defenseFixe;
		int speAttackFixe;
		int speDefenseFixe;
		int vitesseFixe;

		string pathFront;
		string pathBack;

        string pathCri;

		string nom;

		string statut;

		Attaque attaque[4];

		Type type;
		Type type2;


		public:

			Pokemon();
			Pokemon(string);
			Pokemon(string,int,int,int,int,int,int,int,Type);
			Pokemon(string,int,int,int,int,int,int,Type,Attaque*);
            Pokemon(string,int,int,int,int,int,int,Type,Type,Attaque*);

			~Pokemon();


		void affiche(void);
		string lancerAttaque(Attaque, Pokemon*);
		void setPV(int);
		void setVitesse(int);
		void setAttack(int);
		void setSpeAttack(int);
		void setSpeDefense(int);
        void setDefense(int);
        void setStatut(string);
        string getStatut();

		double getCE(Pokemon *, Attaque);
		int getPV();
		int getPVmax();
		int getDegat(Attaque,Pokemon*);
		int getAttack();
		int getSpeAttack();
        int getDefense();
		int getSpeDefense();
		Type getType();
        int getVitesse();
		Type getType2();
		string getNom();
		Attaque* getAttaque();
		bool estKO();
        string attaqueBoost(Attaque);
        string attaqueBoost(Attaque,Pokemon*);
        bool stab(Attaque);
        void setPath();
		string getPath(bool);
		string getPathCri();
		int getVitesseFixe();
		int getAttackFixe();
		int getDefenseFixe();
		int getSpeAttackFixe();
		int getSpeDefenseFixe();

		static string itoa(double,int);
		static string toString(double);
		static string itoa(int,int);
		static string toString(int);


Pokemon & operator=(Pokemon const & other){
    this->pv=other.pv;
    this->attack=other.attack;;
    this->defense=other.defense;
    this->speDefense=other.speDefense;
    this->speAttack=other.speAttack;
    this->vitesse=other.vitesse;
    this->niveau=other.niveau;

    this->nom=other.nom;
    this->type=other.type;
    this->type2=other.type2;

    this->attaque[0]=other.attaque[0];
    this->attaque[1]=other.attaque[1];
    this->attaque[2]=other.attaque[2];
    this->attaque[3]=other.attaque[3];

    this->pathFront=other.pathFront;
    this->pathBack=other.pathBack;

    this->pathCri=other.pathCri;
    this->PVfixe=other.PVfixe;
    this->attackFixe=other.attackFixe;
    this->defenseFixe=other.defenseFixe;
    this->speAttackFixe=other.speAttackFixe;
    this->speDefenseFixe=other.speDefenseFixe;
    this->vitesseFixe=other.vitesseFixe;
    this->statut=other.statut;

    return*this;
}

};
#endif
