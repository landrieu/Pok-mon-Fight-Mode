#ifndef EQUIPE_HPP
#define EQUIPE_HPP
#include <string>
#include "Pokemon.hpp"
#include <vector>

using namespace std;

class Equipe{
        private:
            vector<Pokemon> equipe;                                         //liste de 6 Pokémon

		public:
			Equipe();
			Equipe(Pokemon);
			Equipe(Pokemon, Pokemon);
			Equipe(Pokemon,Pokemon,Pokemon);
			Equipe(Pokemon,Pokemon,Pokemon,Pokemon,Pokemon,Pokemon);

			vector<Pokemon> getListePokemon();
			void affiche();
			void removePokemon(int);
			void addPokemon(Pokemon);
            void insertPokemon(Pokemon, int);
            bool estVide();
};
#endif
