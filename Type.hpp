#ifndef TYPE_HPP
#define TYPE_HPP
#include <string>

using namespace std;

    const string EAU="Eau";
    const string FEU="Feu";
    const string SOL="Sol";
    const string ROCHE="Roche";
    const string NORMAL="Normal";
    const string COMBAT="Combat";
    const string GLACE="Glace";
    const string PSY="Psy";
    const string POISON="Poison";
    const string ELECTRIQUE="Electrique";
    const string VOL="Vol";
    const string ACIER="Acier";
    const string FEE="Fee";
    const string SPECTRE="Spectre";
    const string TENEBRES="Tenebres";
    const string PLANTE="Plante";
    const string INSECTE="Insecte";
    const string DRAGON="Dragon";

class Type{

	private:

		string nom;
		string faiblesse[10];
		string resistance[10];
		string immunite[10];

	public:

		Type();
		Type(string );

		~Type();

		string getNom();
		void setType(string nom);
		string* getFaiblesse();
		string* getResistance();
        string* getImmunite();
};
#endif
