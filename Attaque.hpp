#ifndef ATTAQUE_HPP
#define ATTAQUE_HPP
#include <string>
#include "Type.hpp"

using namespace std;

class Attaque{

	private:

		Type type;
		int puissance;
		bool physique;
		int pp;
		int ppFixe;
		string nom;
		int precision;


	public:

		Attaque();
		Attaque(string);
		Attaque(string ,Type,int);
        Attaque(string ,Type,int, int);
        Attaque(string , int , bool , Type ,int );
		Attaque(string , int , bool , Type ,int,int );
    	~Attaque();


		string getNom();
		int getPuissance();
		bool getPhysique();
		void toString();
		Type getType();
		int getPP();
		int getPPfixe();
		void setPP(int);
		void setPrecision(int);
		int getPrecision();

};
#endif
