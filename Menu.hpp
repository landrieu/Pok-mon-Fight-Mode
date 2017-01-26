#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Equipe.hpp"

using namespace sf;
using namespace std;

class Menu:RenderWindow{

	public:
     Menu();
     int choix();
     bool findPokemon(Equipe,Pokemon);
     vector<Pokemon> Initialisation();
};


const string _BACK="_back";
const string _ICONE="icone_";
//const string EXTENSION_CRI=".ogg";


#endif
