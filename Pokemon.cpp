#include <iostream>
#include <string>
#include "Pokemon.hpp"
#include "Jeu.hpp"

using namespace std;

Pokemon::Pokemon(string nom,int pv,int attack,int defense,int speAttack,int speDefense,int vitesse,Type type, Type type2,Attaque* attaque){

	this->attack=attack;
	this->defense=defense;
	this->speDefense=speDefense;
	this->speAttack=speAttack;
	this->vitesse=vitesse;
	this->pv=pv;
	this->niveau=100;

	this->nom=nom;
	this->type=type;
    this->type2=type2;
	this->PVfixe=pv;
	this->attackFixe=attack;
	this->defenseFixe=defense;
	this->speAttackFixe=speAttack;
	this->speDefenseFixe=speDefense;
	this->vitesseFixe=vitesse;

    this->attaque[0]=attaque[0];
	this->attaque[1]=attaque[1];
	this->attaque[2]=attaque[2];
	this->attaque[3]=attaque[3];

    this->statut=OK;

    setPath();
  //  cout<<"Construction pokemon "<<this->getNom()<<endl;

}

Pokemon::Pokemon(string nom,int pv,int attack,int defense,int speAttack,int speDefense,int vitesse,Type type,Attaque* attaque){

	this->attack=attack;
	this->defense=defense;
	this->speDefense=speDefense;
	this->speAttack=speAttack;
	this->vitesse=vitesse;
	this->pv=pv;
	this->niveau=100;
	this->PVfixe=pv;
    this->attackFixe=attack;
	this->defenseFixe=defense;
	this->speAttackFixe=speAttack;
	this->speDefenseFixe=speDefense;
	this->vitesseFixe=vitesse;
	this->nom=nom;
	this->type=type;

	this->attaque[0]=attaque[0];
	this->attaque[1]=attaque[1];
	this->attaque[2]=attaque[2];
	this->attaque[3]=attaque[3];

	setPath();

    this->statut=OK;

    //cout<<"Construction pokemon "<<this->getNom()<<endl;

}

Pokemon::~Pokemon(){
    static int i=0;
        if (i<5000){

        i++;
        }
        else{
            i=0;
        //    cout << "Destruction pokemon "<<this->getNom()<<endl;
        }
}

Pokemon::Pokemon(string nom,int attack,int defense,int speDefense,int speAttack,int vitesse,int pv,int niveau,Type type){

	this->attack=attack;
	this->defense=defense;
	this->speDefense=speDefense;
	this->speAttack=speAttack;
	this->vitesse=vitesse;
	this->pv=pv;
	this->niveau=niveau;
	this->PVfixe=pv;
	this->nom=nom;
	this->type=type;
    setPath();
}


Pokemon::Pokemon(string nom){

	this->attack=10;
	this->defense=10;
	this->speDefense=10;
	this->speAttack=10;
	this->vitesse=10;
	this->pv=100;
	this->niveau=1;
	this->PVfixe=pv;

	this->nom=nom;

	this->attaque[0] = Attaque("attaque1");
	this->attaque[1] = Attaque("attaque2");
	this->attaque[2] = Attaque("attaque3");
	this->attaque[3] = Attaque("attaque4");

	this->type = Type("Eau");

	setPath();
}



Pokemon::Pokemon(){

	this->attack=10;
	this->defense=10;
	this->speDefense=10;
	this->speAttack=10;
	this->vitesse=10;
	this->pv=100;
	this->niveau=1;
	this->PVfixe=pv;

	this->nom="POKEMON";

	this->attaque[0] = Attaque("attaque1");
	this->attaque[1] = Attaque("attaque2");
	this->attaque[2] = Attaque("attaque3");
	this->attaque[3] = Attaque("attaque4");

	this->type = Type("Eau");
}

void Pokemon::affiche(){

	cout << "---------------------------------------"<<endl;
	cout << "nom: "<<this->nom<<endl;
    cout<< "PV: "<<this->getPV()<<"/"<<this->getPVmax()<<endl;
    cout<<"Attaque: "<<this->getAttack()<<endl;
    cout<<"Defense: "<<this->getDefense()<<endl;
    cout<<"Attaque spe: "<<this->getSpeAttack()<<endl;
    cout<<"Defense spe: "<<this->getSpeDefense()<<endl;
    cout<<"Vitesse: "<<this->getVitesse()<<endl;
	cout << "Attaque 1: "<<endl;
	this->attaque[0].toString();
	cout << "Attaque 2: "<<endl;
	this->attaque[1].toString();
	cout << "Attaque 3: "<<endl;
	this->attaque[2].toString();
	cout << "Attaque 4: "<<endl;
	this->attaque[3].toString();
}

void Pokemon::setAttack(int attack){

this->attack=attack;
}

void Pokemon::setSpeAttack(int speAttack){

this->speAttack=speAttack;
}

void Pokemon::setDefense(int defense){

this->defense=defense;
}

void Pokemon::setSpeDefense(int speDefense){

this->speDefense=speDefense;
}


void Pokemon::setStatut(string statut){
this->statut=statut;

}

string Pokemon::getStatut(){
return this->statut;
}

int Pokemon::getPV(){


	return this->pv;
}
int Pokemon::getAttack(){


	return this->attack;
}
int Pokemon::getSpeAttack(){


	return this->speAttack;
}
int Pokemon::getDefense(){


	return this->defense;
}
int Pokemon::getSpeDefense(){


	return this->speDefense;
}
int Pokemon::getPVmax(){


	return this->PVfixe;
}

int Pokemon::getAttackFixe(){


	return this->attackFixe;
}

int Pokemon::getDefenseFixe(){


	return this->defenseFixe;
}

int Pokemon::getSpeAttackFixe(){


	return this->speAttackFixe;
}
int Pokemon::getSpeDefenseFixe(){


	return this->speDefenseFixe;
}
int Pokemon::getVitesseFixe(){


	return this->vitesseFixe;
}


Type Pokemon::getType(){


	return this->type;
}

Type Pokemon::getType2(){


	return this->type2;
}

void Pokemon::setPV(int pv){

	this->pv=pv;
}

void Pokemon::setVitesse(int vitesse){
    this->vitesse=vitesse;
}


string Pokemon::lancerAttaque(Attaque a, Pokemon *p){

    double degat=0;
    double CE=getCE(p,a);
    int pourcent;
    string s;
    int proba;

    static int tourStatut=0;
    static bool effetPara=true;
    static bool effetBrule=true;

    srand(time(0));

    proba=(rand()%99+1);

        if(this->getStatut()==PARALYSE){
            if (effetPara){
                effetPara=false;
                this->setVitesse(this->getVitesse()/4);
            }
            if (proba<=25)
                s=this->getNom()+" est paralyse ! Il ne peut pas attaquer!\n";        //1 chance sur 4 de ne pas attaquer

         }else{
                if(this->getStatut()==ENDORMI){

                         if (tourStatut<2){
                            s=getNom()+" dort !\n";
                            tourStatut++;
                         }
                         else{
                            tourStatut=0;
                            this->setStatut(NORMAL);
                            s=getNom()+" se reveille !\n";
                         }

                }
                else{

                    if(this->getStatut()==GELE){
                         if (tourStatut<2){
                            s=getNom()+" est gele !\n";
                            tourStatut++;
                         }
                         else{
                            tourStatut=0;
                            this->setStatut(NORMAL);
                            s="\n"+getNom()+" est degele !\n";
                         }
                    }
                    else{
                            proba=(rand()%99+1);
                            s=this->getNom()+" lance "+a.getNom()+" !\n";

                            if (proba>a.getPrecision()){

                                s+=this->getNom()+" rate son attaque !\n";
                            }
                            else{

                                if (a.getPuissance()!=0){
                                degat=getDegat(a,p);
                                                                             //on recupere les degats faits par l'attaque
                                p->setPV(p->getPV()-degat);

                                if (stab(a)){
                                        if( (CE==3) || (CE==6) )
                                            s=s+"C'est super efficace!\n";
                                        else

                                        if( (CE==0.375) || (CE==0.75) )
                                            s=s+"Ce n'est pas tres efficace...\n";
                                   }
                                   else{
                                        if( (CE==2) || (CE==4) )
                                            s=s+"C'est super efficace!\n";
                                        else

                                        if( (CE==0.25) || (CE==0.5) )
                                            s=s+"Ce n'est pas tres efficace...\n";
                                   }

                                   if (CE==0)
                                     s=s+p->getNom()+" est immunise!\n";

                                pourcent=(int)(100*degat/p->getPVmax());

                                 if (pourcent>=100)
                                        pourcent=100;

                                s+=p->getNom()+" perd "+Pokemon::toString(pourcent)+"% de ses PV !\n";


                                if (p->estKO()){
                                    p->setPV(0);
                                    s+=p->getNom()+" est KO!\n ";
                                }

                            }
                            else{
                                s=attaqueBoost(a,p);
                            }

                        }

                    }

                }


                if (this->getStatut()==BRULE){
                        s+=this->getNom()+" souffre de sa brulure !\n";

                        if ((this->getPV()-this->getPVmax()*0.12)>0)
                            this->setPV(this->getPV()-this->getPVmax()*0.12);
                        else
                            this->setPV(0);

                        if (effetBrule){
                            this->setAttack(this->getAttack()/2);
                            effetBrule=false;
                        }
                    }

                    if(this->getStatut()==EMPOISONNE){

                        s+=this->getNom()+" souffre du poison !\n";

                        if ((this->getPV()-this->getPVmax()*0.12)>0)
                            this->setPV(this->getPV()-this->getPVmax()*0.12);
                        else
                            this->setPV(0);
                     }

        }

 return s;
}


bool Pokemon::stab(Attaque a){
    bool stab=false;

    if ((this->type.getNom()==a.getType().getNom()) || (this->type2.getNom()==a.getType().getNom()))
        stab=true;

 return stab;
}

string Pokemon::attaqueBoost(Attaque a, Pokemon *p){

  const string s1=this->getNom()+" lance "+a.getNom()+" !\n";
  string s;

        if (a.getNom()==DANSE_LAMES){

            if (this->attack<=(4*this->getAttackFixe())){
                this->setAttack(this->getAttack()+this->getAttackFixe());               //on ne peut pas depasser x4 un boost ou /4 une baisse de stat
                s="L'attaque de "+this->getNom()+" monte beaucoup !\n";
            }
            else{
                s="L'attaque de "+this->getNom()+" n'ira pas plus haut !\n";
            }
        }

        if (a.getNom()==DANSE_DRACO){

            if (    this->getAttack() < (4*this->getAttackFixe())  ){
                this->setAttack(this->getAttack()+this->getAttackFixe()*0.5);
                this->setVitesse(this->getVitesse()+getVitesseFixe()*0.5);

                s="L'attaque de "+this->getNom()+" monte !\nLa vitesse de "+this->getNom()+" monte !\n";
            }
            else{
                s="L'attaque de "+this->getNom()+" n'ira pas plus haut !\nLa vitesse de "+this->getNom()+" n'ira pas plus haut !\n";            }
        }

        if (a.getNom()==PLENITUDE){

            if (this->getSpeAttack()<(4*getSpeAttackFixe())){
                this->setSpeAttack(this->getSpeAttack()+getSpeAttackFixe()*0.5);
                this->setSpeDefense(this->getSpeDefense()+getSpeDefenseFixe()*0.5);

                s="L'attaque spciale de "+this->getNom()+" monte !\nLa defense speciale de "+this->getNom()+" monte !\n";
            }
            else{
                s="L'attaque speciale de "+this->getNom()+" n'ira pas plus haut !\nLa defense speciale de "+this->getNom()+" n'ira pas plus haut !\n";            }
        }


        if (a.getNom()==ATERRISSAGE){

           if (this->getPV()<this->getPVmax()*0.5)
                this->setPV(getPV()+this->getPVmax()*0.5);
           else
                this->setPV(this->getPVmax());

           s=this->getNom()+" restaure son energie!";
        }

        if (a.getNom()=="Soin"){
           if (this->getPV()<this->getPVmax()*0.5)
                this->setPV(getPV()+this->getPVmax()*0.5);
           else
                this->setPV(this->getPVmax());

           s=this->getNom()+" restaure son energie!";
        }

        if (a.getNom()==RUGISSEMENT){

            if ( p->getAttack() > (p->getAttackFixe()*0.25) ){
                p->setAttack(p->getAttack()-p->getAttackFixe()*0.25);
                s="L'attaque de "+p->getNom()+" baisse !\n";
            }
            else
                s="L'attaque de "+p->getNom()+" n'ira pas plus bas !\n";
        }

        if (a.getNom()=="Mimi-Queue"){

            if (p->getDefense()>(p->getDefenseFixe()*0.25)){
                p->setDefense(p->getDefense()-p->getDefenseFixe()*0.25);
                s="La defense de "+p->getNom()+" baisse !\n";
            }
            else
                s="La defense de "+p->getNom()+" n'ira pas plus bas !\n";
        }

        if (a.getNom()=="Poudre-Dodo"){
           s=p->getNom()+" s'endort !";
           p->setStatut(ENDORMI);
        }

        if (a.getNom()==TREMPETTE){
          s="\nMOTHER OF GOD !!!!!!!!!!!!! DAT POWA !!";
        }

        if (a.getNom()==POLIROCHE){

            if (this->vitesse<(4*getVitesseFixe())){
                this->setVitesse(this->getVitesse()+getVitesseFixe());
                s="La vitesse de "+this->getNom()+" monte beaucoup !\n";
            }
            else{
                s="La vitesse de "+this->getNom()+" n'ira pas plus haut !\n";
            }
        }

        if (a.getNom()==CAGE_ECLAIR){

           if (p->getStatut()!=PARALYSE){

                if (p->getType().getNom()!=ELECTRIQUE){

                    s=p->getNom()+" est paralyse! Il peut ne plus attaquer !\n";
                    p->setStatut(PARALYSE);
                }
                else
                    s=p->getNom()+" est immunise !\n";
           }
           else
            s=p->getNom()+" est deja paralyse !\n";
        }

        if (a.getNom()==FEU_FOLLET){

            if (p->getStatut()!=BRULE){

                if (p->getType().getNom()!=FEU){
                    s=p->getNom()+" est brule!\n";
                    p->setStatut(BRULE);
                }
                else
                    s=p->getNom()+" est immunise !\n";
            }
            else
                s=p->getNom()+" est deja brule !\n";

        }
        
        if (a.getNom()=="Gonflette"){

            if (    this->getAttack() < (4*this->getAttackFixe())  ){
                this->setAttack(this->getAttack()+this->getAttackFixe()*0.5);
                this->setDefense(this->getDefense()+getDefenseFixe()*0.5);

                s="L'attaque de "+this->getNom()+" monte !\nLa defense de "+this->getNom()+" monte !\n";
            }
            else{
                s="L'attaque de "+this->getNom()+" n'ira pas plus haut !\nLa defense de "+this->getNom()+" n'ira pas plus haut !\n";            }
        }
        
        
        if (a.getNom()=="Toxik"){

            if (p->getStatut()!=EMPOISONNE){

                if (p->getType().getNom()!=POISON){
                    s=p->getNom()+" est empoisonne!\n";
                    p->setStatut(EMPOISONNE);
                }
                else
                    s=p->getNom()+" est immunise !\n";
            }
            else
                s=p->getNom()+" est deja empoisonne !\n";

        }

    return (s1+s);
}

string Pokemon::attaqueBoost(Attaque a){
    string s="";
    s=attaqueBoost(a,this);

    return s;
}



bool Pokemon::estKO(){
	if (this->pv<=0)
        return true;


		else
            return false;
}

string Pokemon::getPath(bool front){

	if(front)
	{
	return pathFront;
	}
	else
	{
	return pathBack;
	}
}

string Pokemon::getPathCri(){

return this->pathCri;
}

void Pokemon::setPath(){

    pathBack=PATH_IMAGE+this->getNom()+BACK+EXTENSION_IMAGE;
    pathFront=PATH_IMAGE+this->getNom()+EXTENSION_IMAGE;
    pathCri=PATH_CRI+this->getNom()+EXTENSION_CRI;

}

int Pokemon::getDegat(Attaque a,Pokemon *p){

        double degat;
        double CE=getCE(p,a);

        if(a.getPhysique()==true)                                       //attaque physique: les statistiques d'attaque et défense sont prises en compte
        {
            degat = (((((this->niveau*0.4)+2)*this->attack*a.getPuissance())/(p->defense*50))+2)*CE;
        }
        else
        {                                                               //attaque spéciale: les statistiques d'attaque et défense spé sont prises en compte
            degat = (((((this->niveau*0.4)+2)*this->speAttack*a.getPuissance())/(p->speDefense*50))+2)*CE;
        }

return (int)degat;
}

double Pokemon::getCE(Pokemon *p, Attaque a){

    double CE=1;

    for(int i=0;i<10;i++){                                                  //on teste sur tous les types

        if((p->getType().getImmunite()[i]==a.getType().getNom())||(p->getType2().getImmunite()[i]==a.getType().getNom())){
            CE=0;
        }
        if((p->getType().getFaiblesse()[i]==a.getType().getNom())||(p->getType2().getFaiblesse()[i]==a.getType().getNom()))        //si le type de l'attaque est une faiblesse: x2
        {
            CE = CE*2;
        }

        if((p->getType().getResistance()[i]==a.getType().getNom())||(p->getType2().getResistance()[i]==a.getType().getNom()))        //si le type de l'attaque est une résistance: /2
        {
            CE = CE*0.5;

        }
    }

    if (a.getType().getNom()==this->getType().getNom()||(a.getType().getNom()==this->getType2().getNom()))                 //si le pokemon lance une attaque de son type: x1,5
	{
	    CE = CE*1.5;
	}

	if (a.getPuissance()==0){
		CE=0;
	}

return CE;
}

string Pokemon::getNom(){
	return nom;
}

Attaque* Pokemon::getAttaque(){
	return this->attaque;
}
int Pokemon::getVitesse(){
	return vitesse;
}

string Pokemon::toString(int n){
    return itoa(n,10);
}


string Pokemon::itoa(int value, int base) {

        std::string buf;

        // check that the base if valid
        if (base < 2 || base > 16) return buf;

        enum { kMaxDigits = 35 };
        buf.reserve( kMaxDigits ); // Pre-allocate enough space.


        int quotient = value;

        // Translating number to string with base:
        do {
            buf += "0123456789abcdef"[ std::abs( quotient % base ) ];
            quotient /= base;
        } while ( quotient );

        // Append the negative sign
        if ( value < 0) buf += '-';

        std::reverse( buf.begin(), buf.end() );
    return buf;
}


string Pokemon::toString(double n){
    return itoa(n,10);
}


string Pokemon::itoa(double value, int base) {

        std::string buf;

        // check that the base if valid
        if (base < 2 || base > 16) return buf;

        enum { kMaxDigits = 35 };
        buf.reserve( kMaxDigits ); // Pre-allocate enough space.


        int quotient = value;

        // Translating number to string with base:
        do {
            buf += "0123456789abcdef"[ std::abs( quotient % base ) ];
            quotient /= base;
        } while ( quotient );

        // Append the negative sign
        if ( value < 0) buf += '-';

        std::reverse( buf.begin(), buf.end() );
        return buf;
}
