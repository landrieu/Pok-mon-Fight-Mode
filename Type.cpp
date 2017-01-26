#include "Type.hpp"
#include <string>

using namespace std;

Type::Type(){

}
Type::Type(string nom){

    this->nom=nom;
    this->setType(nom);
}

Type::~Type(){

//	cout <<"Destruction type"<<endl;

}
void Type::setType(string nom)
{
    if(nom==EAU)
    {
        this->faiblesse[0]=PLANTE;
        this->faiblesse[1]=ELECTRIQUE;

        this->resistance[0]=EAU;
        this->resistance[1]=FEU;
        this->resistance[2]=GLACE;
    }

    if(nom==FEU)
    {
        this->faiblesse[0]=EAU;
        this->faiblesse[1]=SOL;
        this->faiblesse[2]=ROCHE;

        this->resistance[0]=GLACE;
        this->resistance[1]=FEU;
        this->resistance[2]=PLANTE;
        this->resistance[3]=INSECTE;
        this->resistance[4]=ACIER;
        this->resistance[5]=FEE;
    }

    if(nom==PLANTE)
    {
        this->faiblesse[0]=FEU;
        this->faiblesse[1]=VOL;
        this->faiblesse[2]=POISON;
        this->faiblesse[3]=GLACE;
        this->faiblesse[4]=INSECTE;

        this->resistance[0]=PLANTE;
        this->resistance[1]=EAU;
        this->resistance[2]=PLANTE;
        this->resistance[3]=SOL;
        this->resistance[4]=ELECTRIQUE;
    }

    if (nom==SOL){

        this->faiblesse[0]=EAU;
        this->faiblesse[1]=PLANTE;
        this->faiblesse[2]=GLACE;

        this->resistance[0]=POISON;
        this->resistance[1]=ROCHE;

        this->immunite[0]=ELECTRIQUE;
    }

    if (nom==ROCHE){

        this->faiblesse[0]=EAU;
        this->faiblesse[1]=ACIER;
        this->faiblesse[2]=COMBAT;
        this->faiblesse[3]=SOL;
        this->faiblesse[4]=PLANTE;

        this->resistance[0]=POISON;
        this->resistance[1]=VOL;
        this->resistance[2]=FEU;
        this->resistance[3]=NORMAL;
    }

    if (nom==NORMAL){

        this->faiblesse[0]=COMBAT;

        this->immunite[0]=SPECTRE;
    }

    if (nom==VOL){

        this->faiblesse[0]=ROCHE;
        this->faiblesse[1]=ELECTRIQUE;
        this->faiblesse[2]=GLACE;

        this->resistance[0]=INSECTE;
        this->resistance[1]=COMBAT;
        this->resistance[2]=PLANTE;

        this->immunite[0]=SOL;
    }

    if (nom==ELECTRIQUE){

        this->faiblesse[0]=SOL;

        this->resistance[0]=ACIER;
        this->resistance[1]=VOL;
        this->resistance[2]=ELECTRIQUE;
    }

    if (nom==DRAGON){

        this->faiblesse[0]=FEE;
        this->faiblesse[1]=DRAGON;
        this->faiblesse[2]=GLACE;

        this->resistance[0]=EAU;
        this->resistance[1]=FEU;
        this->resistance[2]=ELECTRIQUE;
        this->resistance[3]=PLANTE;
    }

    if (nom==FEE){

        this->faiblesse[0]=ACIER;
        this->faiblesse[1]=POISON;

        this->resistance[0]=COMBAT;
        this->resistance[1]=TENEBRES;
        this->resistance[2]=INSECTE;

        this->immunite[0]=DRAGON;
    }

    if (nom==POISON){

        this->faiblesse[0]=PSY;
        this->faiblesse[1]=SOL;

        this->resistance[0]=COMBAT;
        this->resistance[1]=FEE;
        this->resistance[2]=INSECTE;
        this->resistance[3]=PLANTE;
        this->resistance[4]=POISON;
    }

    if (nom==PSY){

        this->faiblesse[0]=TENEBRES;
        this->faiblesse[1]=INSECTE;
        this->faiblesse[2]=SPECTRE;

        this->resistance[0]=PSY;
        this->resistance[1]=COMBAT;
    }

    if (nom==COMBAT){

        this->faiblesse[0]=PSY;
        this->faiblesse[1]=FEE;
        this->faiblesse[2]=VOL;

        this->resistance[0]=TENEBRES;
        this->resistance[1]=ROCHE;
        this->resistance[2]=INSECTE;
    }

    if (nom==GLACE){

        this->faiblesse[0]=FEU;
        this->faiblesse[1]=ACIER;
        this->faiblesse[2]=COMBAT;
        this->faiblesse[3]=ROCHE;

        this->resistance[0]=GLACE;
    }

    if (nom==INSECTE){

        this->faiblesse[0]=FEU;
        this->faiblesse[1]=VOL;
        this->faiblesse[2]=ROCHE;

        this->resistance[0]=PLANTE;
        this->resistance[1]=COMBAT;
        this->resistance[2]=SOL;
    }

    if (nom==SPECTRE){

        this->faiblesse[0]=SPECTRE;
        this->faiblesse[1]=TENEBRES;

        this->resistance[0]=INSECTE;
        this->resistance[1]=POISON;

        this->immunite[0]=NORMAL;
        this->immunite[1]=COMBAT;
    }

    if (nom==ACIER){

        this->faiblesse[0]=FEU;
        this->faiblesse[1]=SOL;
        this->faiblesse[2]=COMBAT;

        this->resistance[0]=PSY;
        this->resistance[1]=ACIER;
        this->resistance[2]=DRAGON;
        this->resistance[3]=NORMAL;
        this->resistance[4]=ROCHE;
        this->resistance[5]=FEE;
        this->resistance[6]=GLACE;
        this->resistance[7]=INSECTE;
        this->resistance[8]=PLANTE;
        this->resistance[9]=PSY;

        this->immunite[0]=POISON;

    }

    if (nom==TENEBRES){

        this->faiblesse[0]=COMBAT;
        this->faiblesse[1]=FEE;
        this->faiblesse[2]=INSECTE;

        this->resistance[0]=SPECTRE;
        this->resistance[1]=TENEBRES;

        this->immunite[0]=PSY;

    }

}

string Type::getNom(){

return this->nom;
}
string* Type::getFaiblesse()
{
return this->faiblesse;
}

string* Type::getResistance()
{

return this->resistance;
}

string* Type::getImmunite()
{

return this->immunite;
}

