#ifndef JEU_HPP
#define JEU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Equipe.hpp"
using namespace sf;
using namespace std;


class Jeu:RenderWindow{

	public:
       Jeu();
       int jouer(Equipe*,Equipe*);
};

    const string PATH_IMAGE="Image/";
    const string BACK="_back";
    const string ICONE="icone_";
    const string EXTENSION_IMAGE=".png";
    const string PATH_CRI="Son/";
    const string EXTENSION_CRI=".ogg";

    const string ENDORMI="Endormi";
    const string OK="OK";
    const string PARALYSE="Paralyse";
    const string EMPOISONNE="Empoisonne";
    const string BRULE="Brule";
    const string GELE="Gele";
	
	const string RUGISSEMENT="Rugissement";
	const string CAGE_ECLAIR="Cage-Eclair";
	const string POLIROCHE="Poliroche";
	const string TREMPETTE="Trempette";
	const string ATERRISSAGE="Aterrissage";
	const string FEU_FOLLET="Feu-Follet";
	const string PLENITUDE="Plenitude";
	const string DANSE_LAMES="Danse-Lames";
	const string DANSE_DRACO="Danse-Draco";		
	/*const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";		
	const string DANSE_DRACO="Danse-Draco";
		
*/
#endif
