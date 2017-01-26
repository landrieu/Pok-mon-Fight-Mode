#include "Menu.hpp"
#include "Jeu.hpp"
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

Menu::Menu(){

}

int Menu::choix()
{
    Jeu pokemon_bataille;
    int mouseX,mouseY;
    Image icone;

	string ModeJeu ="Menu";

    vector<Pokemon> allPokemon;
    allPokemon=Initialisation();

    Equipe team1;
	Equipe team2;

    Sprite EquipeP1[6];
    Sprite EquipeP2[6];

    Text textBoutton;
    string choixJ="Joueur 1";
    RectangleShape boutton(Vector2f(220,50));
    boutton.setFillColor(Color::Blue);
    boutton.setPosition(700,600);
    Sprite IPokemon;
    Texture tex;
    Sprite Ipo[allPokemon.size()];
    Texture Icone[allPokemon.size()];

    for (unsigned int i=0;i<(allPokemon.size());i++)
    {
       if (!Icone[i].loadFromFile(PATH_IMAGE+_ICONE+allPokemon[i].getNom()+EXTENSION_IMAGE))
			return -1;
       
		else{
			Icone[i].setSmooth(true);
			Ipo[i].setTexture(Icone[i]);
					
			Ipo[i].setPosition(10+(80*(i%15)),300+50*(i/15));

		}
    }

    Font police;

    Clock clk;                              //demarrer chrono

	create(VideoMode(1280,720),"POKEMON");      //on cree la fenetre

    sf::Text text,nomPoke,text1,text2;
    nomPoke.setFont(police);
	nomPoke.setCharacterSize(24);
    text1.setFont(police);
	text1.setCharacterSize(24);
	text2.setFont(police);
	text2.setCharacterSize(24);
	text.setFont(police);
	text.setCharacterSize(24); // exprimée en pixels, pas en points !

	// choix de la couleur du texte
	textBoutton.setColor(sf::Color::White);
	text1.setColor(sf::Color::Black);
    text2.setColor(sf::Color::Black);
	text.setColor(sf::Color::Black);
    nomPoke.setColor(sf::Color::Black);
	text.setPosition(100,160);
	text1.setPosition(100,580);
	text2.setPosition(100,650);
	nomPoke.setPosition(100,220);


	text1.setString("Pokemon du joueur 1");
	text2.setString("Pokemon du joueur 2");
    text.setString("Au joueur 1 de choisir ses Pokemon");
    setFramerateLimit(60);
                //limiter a 60 fps
    if (!police.loadFromFile("Image/calibri.ttf")){
                  cout <<"Erreur lors du chargement de la police"<<endl;
                     return -1;
                }

    if (!tex.loadFromFile("Image/pokemon.png"))
        return -1;
    else{

                tex.setSmooth(true);
                IPokemon.setTexture(tex);
                IPokemon.setPosition(450,10);

                IPokemon.setScale(1.8,1.8);

    }


    if (!icone.loadFromFile("Image/pokeball.png"))
        return -1;

    setIcon(32,32,icone.getPixelsPtr());


    while (this->isOpen()){                                         //boucle infinie

        sf::Event event;

        while (pollEvent(event)){                             //boucle des événements

          for (unsigned int t=0;t<(allPokemon.size());t++)
          {
            if(Ipo[t].getGlobalBounds().contains(Mouse::getPosition(*this).x,Mouse::getPosition(*this).y))
            {
                nomPoke.setString(allPokemon[t].getNom());
            }
          }
            switch (event.type){

                case Event::Closed:                                 //si on ferme la fenetre
                    close();

                    break;

                case Event::KeyPressed:                             //si on appuie sur une touche

                    if (event.key.code==Keyboard::Escape)
                       close();

                    break;

                case Event::MouseButtonPressed:
                     if (event.mouseButton.button==Mouse::Left){             //bouton gauche
                            mouseX=Mouse::getPosition(*this).x;            //on recupere la position de la souris
                            mouseY=Mouse::getPosition(*this).y;

                             if ((boutton.getGlobalBounds().contains(mouseX,mouseY))&& choixJ=="Fin")
                             {
                                text.setString("BOUTON");
								
								close();
								
                                pokemon_bataille.jouer(&team1,&team2);								
								
                                return EXIT_SUCCESS;
                             }

                            for (unsigned int k=0;k<(allPokemon.size());k++)
                            {
                                if (Ipo[k].getGlobalBounds().contains(mouseX,mouseY))
                                {
                                   if(choixJ=="Joueur 1")
                                   {

                                    if(findPokemon(team1,allPokemon[k])==false)
                                    {
                                        EquipeP1[team1.getListePokemon().size()]=Ipo[k];
                                        EquipeP1[team1.getListePokemon().size()].setPosition(400+(team1.getListePokemon().size()*40),580);
                                        team1.addPokemon(allPokemon[k]);

                                        text.setString("Pokemon Ajoute");
                                        
                                        if(team1.getListePokemon().size()==6)
                                        {
                                             text.setString("Votre equipe est complete \n Au joueur 2 de chosir");
                                             choixJ="Joueur 2";

                                        }
                                      }
                                        else
                                        {
                                          text.setString("Ce Pokemon existe deja");
                                        }
                                   }
                                   else
                                   {
                                       if(choixJ=="Joueur 2")
                                       {

                                         if(findPokemon(team2,allPokemon[k])==false)
                                        {
                                        EquipeP2[team2.getListePokemon().size()]=Ipo[k];
                                        EquipeP2[team2.getListePokemon().size()].setPosition(400+(team2.getListePokemon().size()*40),650);
                                        team2.addPokemon(allPokemon[k]);

                                        text.setString("Pokemon Ajoute");
                                        if(team2.getListePokemon().size()==6)
                                        {
                                             text.setString("Votre equipe est complete \n Appuyez sur le bouton pour lancer le combat");
                                             choixJ="Fin";
                                        }
                                        }
                                        else
                                        {
                                          text.setString("Ce Pokemon existe deja");
                                        }
                                    }
                                   }
                                }
                            }
                            }                       //si on clique
                     break;
                default:
                    break;
            }
        }
        /**************** Chargement et position Sprite **********/

         textBoutton.setString(" Passer au combat");
         textBoutton.setFont(police);
         textBoutton.setPosition(boutton.getPosition());

        clear(Color::White);               //affichages

        draw(text1);
        draw(text2);
        draw(nomPoke);
        draw(text);
        draw(IPokemon);
        
         if(choixJ=="Fin")
         {
           draw(boutton);
           draw(textBoutton);
         }

        for(unsigned int o=0;o<team1.getListePokemon().size();o++)
        {
        draw(EquipeP1[o]);
        }
        for(unsigned int r=0;r<team1.getListePokemon().size();r++)
        {
        draw(EquipeP2[r]);
        }



        for (unsigned int j=0;j<(allPokemon.size());j++)
        {
        draw(Ipo[j]);
        }



        display();

    }

return EXIT_SUCCESS;

}
bool Menu::findPokemon(Equipe e,Pokemon p)
{
    for(unsigned int i=0;i<e.getListePokemon().size();i++)
    {
        if(e.getListePokemon()[i].getNom()==p.getNom())
        {
            return true;
        }
    }
return false;
}

vector<Pokemon> Menu::Initialisation()
{
    vector<Pokemon> liste;
    Type Eau(EAU);
	Type Feu(FEU);
	Type Plante(PLANTE);
	Type Normal(NORMAL);
	Type Vol(VOL);
    Type Acier(ACIER);
    Type Roche(ROCHE);
    Type Sol(SOL);
    Type Psy(PSY);
	Type Poison(POISON);
	Type Dragon(DRAGON);
	Type Fee(FEE);
	Type Tenebres(TENEBRES);
	Type Glace(GLACE);
	Type Combat(COMBAT);
	Type Spectre(SPECTRE);
	Type Electrique(ELECTRIQUE);
	Type Insecte(INSECTE);

/******************************Déclaration des attaques offensives**************************************************/
    Attaque Surf("Surf",95,false,Eau,20,100);
	Attaque Hydrocanon("Hydrocanon",110,false,Eau,5,80);
	Attaque Charge("Charge",35,true,Normal,40,100);
	Attaque Deflagration("Deflagration",110,false,Feu,20,85);
	Attaque Lance_Flamme("Lance-Flammes",90,false,Feu,25,100);
	Attaque Tranchherbe("Tranch'herbe",55,false,Plante,25,95);
	Attaque Lance_Soleil("Lance-Soleil",120,false,Plante,10,100);
	Attaque Pistolet_a_o("Pistolet a o",40,true,Eau,25,100);
	Attaque Trempette("Trempette",0,true,Eau,40,100);
	Attaque Eboulement("Eboulement",75,true,Roche,10,90);
	Attaque Seisme("Seisme",100,true,Sol,15,100);
	Attaque Psyko("Psyko",90,false,Psy,15,100);
	Attaque Choc_Psy("Choc Psy",80,false,Psy,15,100);
	Attaque Colere("Colere",120,true,Dragon,10,100);
	Attaque Vitesse_Extreme("Vitesse extreme",85,true,Normal,15,100);
	Attaque Ball_Ombre("Ball'Ombre",80,false,Spectre,15,100);
	Attaque Bomb_Beurk("Bomb-Beurk",90,false,Poison,10,100);
	Attaque Lechouille("Lechouille",30,true,Spectre,30,100);
	Attaque Choc_Mental("Choc Mental",50,false,Psy,25,100);
	Attaque Aeroblast("Aeroblast",100,false,Vol,5,95);
    Attaque Cascade("Cascade",80,true,Eau,15,100);
    Attaque Morsure("Morsure",65,true,Tenebres,25,100);
    Attaque Poing_Meteor("Poing-Meteor",90,true,Acier,15,90);
    Attaque PsykoudBoul("Psykoud'Boul",80,true,Psy,15,90);
    Attaque Feu_Sacre("Feu Sacre",100,true,Feu,5,95);
    Attaque Megaphone("Megaphone",90,false,Fee,10,100);
	Attaque Exploforce("Exploforce",120,false,Combat,5,70);
	Attaque Tonnerre("Tonnerre",90,false,Electrique,15,100);
	Attaque OndeBoreale("Onde Boreale",65,false,Glace,20,100);
	Attaque Dracochoc("Dracochoc",85,false,Dragon,10,100);
	Attaque LaserGlace("Laser Glace",90,false,Glace,10,100);
	Attaque LameDeRoc("Lame de roc",100,true,Roche,5,80);
	Attaque Plaquage("Plaquage",85,true,Normal,15,100);
	Attaque TeteDeFer("Tete de fer",80,true,Acier,15,100);
	Attaque Fatal_Foudre("Fatal-Foudre",120,false,Electrique,10,70);
	Attaque Blizzard("Blizzard",120,false,Glace,5,70);
	Attaque Tornade("Tornade",40,false,Vol,35,100);
	Attaque Cru_Aile("Cru-Aile",60,true,Vol,35,100);
	Attaque Calinerie("Calinerie",90,true,Fee,10,90);
    Attaque Surpuissance("Surpuissance",120,true,Combat,5,100);
    Attaque Ultralaser("Ultralaser",150,false,Normal,5,90);
    Attaque Tranche("Tranche",70,true,Normal,20,100);
    
	
/******************************Déclaration des attaques non-offensives**************************************************/
	Attaque Poudre_Dodo("Poudre-Dodo",Plante,15,75);
	Attaque Danse_Draco("Danse-Draco",Dragon,25,100);
	Attaque Plenitude("Plenitude",Psy,25,100);
	Attaque Danse_Lames("Danse-Lames",Normal,30,100);
    Attaque Rugissement("Rugissement",Normal,35,100);
    Attaque Mimi_Queue("Mimi-Queue",Normal,35,100);
    Attaque Aterrissage("Aterrissage",Vol,30,100);
	Attaque Soin("Soin",Normal,10,100);
	Attaque Poliroche("Poliroche",Roche,15,100);
    Attaque Feu_Follet("Feu-Follet",Feu,20,85);
    Attaque Cage_Eclair("Cage-Eclair",Electrique,25,100);
    Attaque Gonflette("Gonflette",Combat,20,100);
    Attaque Toxik("Toxik",Poison,20,100);
   
    

    Attaque AttaqueTortank[4]={Surf,Hydrocanon,Charge,Mimi_Queue};
	Attaque AttaqueDracaufeu[4]={Charge,Deflagration,Lance_Flamme,Rugissement};
	Attaque AttaqueFlorizarre[4] = {Tranchherbe,Lance_Soleil,Poudre_Dodo,Charge};
	Attaque AttaquePsykokwkak[4] = {Trempette,Pistolet_a_o,Charge,Surf};
    Attaque AttaqueDemeteros[4] = {Charge,Rugissement,Eboulement,Seisme};
    Attaque	AttaqueMewtwo[4]={Psyko,Deflagration,Hydrocanon,Plenitude};
    Attaque AttaqueDracolosse[4]={Danse_Draco,Colere,Vitesse_Extreme,Aterrissage};
    Attaque AttaqueEctoplasma[4]={Surf,Bomb_Beurk,Ball_Ombre,Mimi_Queue};
    Attaque AttaqueAlakazam[4]={Choc_Mental,Soin,Psyko,Plenitude};
    Attaque AttaqueLugia[4]={Hydrocanon,Aeroblast,Rugissement,Psyko};
    Attaque AttaqueHeatran[4]={Deflagration,Rugissement,Soin,Lance_Flamme};
    Attaque AttaqueTyranocif[4]={Danse_Lames,Charge,Eboulement,Seisme};
    Attaque AttaqueCarchacrok[4]={Colere,Charge,Seisme,Danse_Lames};
    Attaque AttaqueLeviator[4]={Cascade,Hydrocanon,Morsure,Danse_Draco};
    Attaque AttaqueMetalosse[4]={Seisme,PsykoudBoul,Poing_Meteor,Poliroche};
    Attaque AttaqueMackogneur[4]={Charge,Seisme,Danse_Lames,Eboulement};
    Attaque AttaqueHoOh[4]={Deflagration,Feu_Sacre,Plenitude,Soin};
	Attaque AttaqueMew[4]={Psyko,Soin,Plenitude,Feu_Follet};
	Attaque AttaqueFlagadoss[4]={Surf,Hydrocanon,Soin,Plenitude};
	Attaque AttaqueEntei[4]={Feu_Sacre,Feu_Follet,Lance_Flamme,Plenitude};
	Attaque AttaqueGardevoir[4]={Psyko,Plenitude,Megaphone,Exploforce};
	Attaque AttaqueStaross[4]={Surf,Psyko,Soin,Hydrocanon};
	Attaque AttaqueNoacier[4]={Lance_Soleil,Poliroche,Tranchherbe,Tonnerre};
	Attaque AttaqueSuicune[4]={Plenitude,Surf,OndeBoreale,Hydrocanon};
	Attaque AttaqueLatios[4]={Soin,Danse_Draco,Dracochoc,Psyko};
	Attaque AttaqueLatias[4]={Soin,Danse_Draco,Dracochoc,Psyko};
	Attaque AttaqueKyogre[4]={Surf,Tonnerre,Plenitude,LaserGlace};
	Attaque AttaqueGroudon[4]={Lance_Soleil,Seisme,Deflagration,Eboulement};
	Attaque AttaqueRayquaza[4]={Danse_Draco,Dracochoc,Vitesse_Extreme,Colere};
	Attaque AttaqueBetochef[4]={Seisme,Gonflette,Eboulement,LameDeRoc};
	Attaque AttaqueArcanin[4]={Deflagration,Vitesse_Extreme,Lance_Flamme,Colere};
	Attaque AttaqueGenesect[4]={Tonnerre,Psyko,Lance_Flamme,LaserGlace};
	Attaque AttaqueRonflex[4]={Plaquage,Gonflette,PsykoudBoul,Charge};
	Attaque AttaqueFeunard[4]={Lance_Flamme,Deflagration,Feu_Follet,Charge};
	Attaque AttaqueMinotaupe[4]={Seisme,Eboulement,TeteDeFer,Danse_Lames};
	Attaque AttaqueLeuphorie[4]={Soin,Toxik,Lance_Flamme,Tonnerre};
	Attaque AttaqueSmogogo[4]={Bomb_Beurk,Charge,Toxik,Lance_Flamme};
	Attaque AttaquePikachu[4]={Tonnerre,Fatal_Foudre,Charge,Cage_Eclair};
	Attaque AttaqueArtikodin[4]={LaserGlace,Blizzard,Aterrissage,Tornade};
	Attaque AttaqueElecthor[4]={Tonnerre,Cage_Eclair,Aterrissage,Fatal_Foudre};
	Attaque AttaqueSulfura[4]={Lance_Flamme,Lance_Soleil,Aterrissage,Cru_Aile};
	Attaque AttaqueAzumarill[4]={Cascade,Charge,Calinerie,Surpuissance};
	Attaque AttaqueNymphali[4]={Megaphone,Plenitude,Ball_Ombre,Choc_Psy};
	Attaque AttaqueCizayox[4]={TeteDeFer,Danse_Lames,Tranche,Ultralaser};
	Attaque AttaqueOnix[4]={Charge,Poliroche,Seisme,LameDeRoc};
	Attaque AttaqueGrolem[4]={Seisme,TeteDeFer,LameDeRoc,Poliroche};
	Attaque AttaqueRhinoferos[4]={Seisme,Danse_Lames,Poliroche,LameDeRoc};
	Attaque AttaqueArceus[4]={Ultralaser,Vitesse_Extreme,Trempette,Charge};
	Attaque AttaqueRaikou[4]={Tonnerre,Fatal_Foudre,Cage_Eclair,Ball_Ombre};
	Attaque AttaqueTriopikeur[4]={Seisme,Charge,Rugissement,LameDeRoc};
	Attaque AttaqueTartard[4]={Plaquage,Cascade,Surpuissance,Seisme};
	
	Pokemon Tortank("Tortank",362,265,299,269,309,255,Eau,AttaqueTortank);                              //PV;attaque;defense;attaqueSpe;defspe;vitesse
	Pokemon Dracaufeu("Dracaufeu",360,267,255,317,269,299,Feu,Vol,AttaqueDracaufeu);
	Pokemon Florizarre("Florizarre",364,263,265,299,299,259,Plante,Poison,AttaqueFlorizarre);
	Pokemon Psykokwak("Psykokwak",304,203,195,229,199,209,Eau,AttaquePsykokwkak);
	Pokemon Demeteros("Demeteros",382,389,279,309,259,281,Vol,Sol,AttaqueDemeteros);
	Pokemon Mewtwo("Mewtwo",416,319,279,407,279,359,Psy,AttaqueMewtwo);
	Pokemon Dracolosse("Dracolosse",386,367,289,299,299,259,Dragon,Vol,AttaqueDracolosse);
    Pokemon Ectoplasma("Ectoplasma",324,229,219,359,249,319,Poison,Spectre,AttaqueEctoplasma);
    Pokemon Alakazam("Alakazam",314,199,189,369,289,339,Psy,AttaqueAlakazam);
    Pokemon Lugia("Lugia",416,279,359,279,407,319,Psy,Vol,AttaqueLugia);
    Pokemon Heatran("Heatran",386,279,311,359,311,253,Acier,Feu,AttaqueHeatran);
    Pokemon Tyranocif("Tyranocif",404,367,319,289,299,221,Tenebres,Roche,AttaqueTyranocif);
    Pokemon Carchacrok("Carchacrok",420,359,289,259,269,303,Dragon,Sol,AttaqueCarchacrok);
    Pokemon Leviator("Leviator",394,349,257,219,299,261,Eau,Vol,AttaqueLeviator);
    Pokemon Metalosse("Metalosse",364,369,359,289,279,239,Psy,Acier,AttaqueMetalosse);
    Pokemon Mackogneur("Mackogneur",384,359,259,229,269,209,Combat,AttaqueMackogneur);
    Pokemon Ho_Oh("Ho-Oh",416,359,279,319,407,279,Feu,Vol,AttaqueHoOh);
    Pokemon Mew("Mew",404,299,299,299,299,299,Psy,AttaqueMew);
    Pokemon Flagadoss("Flagadoss",394,249,319,299,259,159,Eau,AttaqueFlagadoss);
    Pokemon Entei("Entei", 434,329,269,279,249,299,Feu,AttaqueEntei);
    Pokemon Gardevoir("Gardevoir",340,229,229,349,329,259,Fee,Psy,AttaqueGardevoir);
    Pokemon Staross("Staross",324,249,269,299,269,329,Eau,Psy,AttaqueStaross);
    Pokemon Noacier("Noacier",352,287,361,207,331,139,Acier,Plante,AttaqueNoacier);
    Pokemon Suicune("Suicune",404,249,329,279,329,269,Eau,AttaqueSuicune);
    Pokemon Latios("Latios",364,279,259,359,319,319,Psy,Dragon,AttaqueLatios);
	Pokemon Latias("Latias",364,259,279,319,359,319,Psy,Dragon,AttaqueLatias);
	Pokemon Kyogre("Kyogre",404,299,279,399,379,279,Eau,AttaqueKyogre);
	Pokemon Groudon("Groudon",404,399,379,299,279,279,Sol,AttaqueGroudon);
	Pokemon Rayquaza("Rayquaza",414,399,279,399,279,289,Vol,Dragon,AttaqueRayquaza);
	Pokemon Betochef("Betochef",414,379,289,209,229,189,Combat,AttaqueBetochef);
	Pokemon Arcanin("Arcanin",384,319,259,299,259,289,Feu,AttaqueArcanin);
	Pokemon Genesect("Genesect",346,339,289,339,289,297,Insecte,Acier,AttaqueGenesect);
	Pokemon Ronflex("Ronflex",524,319,229,229,319,159,Normal,AttaqueRonflex);
	Pokemon Feunard("Feunard",350,251,249,261,299,299,Feu,AttaqueFeunard);
	Pokemon Minotaupe("Minotaupe",424,369,219,199,229,275,Acier,Sol,AttaqueMinotaupe);
	Pokemon Leuphorie("Leuphorie",714,119,119,249,369,209,Normal,AttaqueLeuphorie);
	Pokemon Smogogo("Smogogo",334,279,339,269,239,219,Poison,AttaqueSmogogo);
	Pokemon Pikachu("Pikachu",274,209,159,199,179,279,Electrique,AttaquePikachu);
	Pokemon Artikodin("Artikodin",384,269,299,289,349,269,Glace,Vol,AttaqueArtikodin);
	Pokemon Electhor("Electhor",384,279,269,349,279,299,Electrique,Vol,AttaqueElecthor);
	Pokemon Sulfura("Sulfura",384,299,279,349,269,279,Feu,Vol,AttaqueSulfura);
	Pokemon Azumarill("Azumarill",404,199,259,219,259,199,Fee,Eau,AttaqueAzumarill);
	Pokemon Nymphali("Nymphali",394,229,229,319,359,219,Fee,AttaqueNymphali);
	Pokemon Cizayox("Cizayox",344,359,299,209,259,229,Insecte,Acier,AttaqueCizayox);
	Pokemon Onix("Onix",274,189,419,159,189,239,Roche,Sol,AttaqueOnix);
	Pokemon Grolem("Grolem",364,319,359,209,229,189,Roche,Sol,AttaqueGrolem);
	Pokemon Rhinoferos("Rhinoferos",414,359,359,189,189,179,Roche,Sol,AttaqueRhinoferos);
	Pokemon Arceus("Arceus",444,339,339,339,339,339,Normal,AttaqueArceus);
	Pokemon Raikou("Raikou",384,269,249,329,299,329,Electrique,AttaqueRaikou);
	Pokemon Triopikeur("Triopikeur",274,259,199,199,239,339,Sol,AttaqueTriopikeur);
	Pokemon Tartard("Tartard",384,269,289,239,279,239,Eau,Combat,AttaqueTartard);
	liste.push_back(Tortank);
    liste.push_back(Dracaufeu);
    liste.push_back(Florizarre);
    liste.push_back(Pikachu);
    
    liste.push_back(Dracolosse);
    liste.push_back(Ectoplasma);
    liste.push_back(Alakazam);
    liste.push_back(Onix);
	liste.push_back(Grolem);
	liste.push_back(Rhinoferos);
	liste.push_back(Triopikeur);
    liste.push_back(Leviator);
    liste.push_back(Psykokwak);
    liste.push_back(Staross);
    liste.push_back(Tartard);
	liste.push_back(Ronflex);
	liste.push_back(Feunard);
    liste.push_back(Mackogneur);	
	liste.push_back(Arcanin);
    liste.push_back(Flagadoss);
	liste.push_back(Smogogo);
	liste.push_back(Artikodin);
	liste.push_back(Electhor);
	liste.push_back(Sulfura);
	liste.push_back(Mewtwo);
	liste.push_back(Mew);
	

    liste.push_back(Raikou);		
    liste.push_back(Entei);	
	liste.push_back(Suicune);	
    liste.push_back(Lugia);
    liste.push_back(Ho_Oh);
    liste.push_back(Tyranocif);
    liste.push_back(Azumarill);
	liste.push_back(Cizayox);
	liste.push_back(Leuphorie);
    
    liste.push_back(Carchacrok);
    liste.push_back(Metalosse);    
    liste.push_back(Heatran);    
    liste.push_back(Gardevoir);
	liste.push_back(Latios);
	liste.push_back(Latias);
	liste.push_back(Kyogre);
	liste.push_back(Groudon);
	liste.push_back(Rayquaza);
	liste.push_back(Betochef);
	liste.push_back(Genesect);
	liste.push_back(Minotaupe);
    liste.push_back(Noacier);
	liste.push_back(Nymphali);
	liste.push_back(Arceus);
	liste.push_back(Demeteros);
 
    return liste;
}

