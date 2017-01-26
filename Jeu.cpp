#include "Jeu.hpp"
#include "Equipe.hpp"

#include <iostream>
#include <string>
#include <stdio.h>

using namespace sf;
using namespace std;


Jeu::Jeu(){

}


int Jeu::jouer(Equipe* team1,Equipe* team2){

	int mouseX,mouseY;
	int nbTour=1;
	int randAtt;
	int randPoke;
	bool riposter=false;


	Pokemon J1;                 //les 2 pokemon en combat
	Pokemon J2;


    Font police;

    Text nomLanceur, nomEnnemi, nomAttaque1,nomAttaque2,nomAttaque3,nomAttaque4,pvLanceur,pvEnnemi;

    Text type1,type2,type3,type4;

    Texture fond,t1,t2,t3,t4,t5;

    Sprite lanceur;
    Sprite ennemi;

	Sprite iPokemon[6];
	RectangleShape PokemonSwitch[6];

	Texture textIcone[6];

    Image icone;

    RectangleShape fond_ecran;

    RectangleShape barreVieLanceur(Vector2f(200,20));
    RectangleShape barreVieEnnemi(Vector2f(200,20));

    RectangleShape barreVieLanceurBord(Vector2f(204,24));
    RectangleShape barreVieEnnemiBord(Vector2f(204,24));

    RectangleShape attaque1(Vector2f(150,50));
    RectangleShape attaque2(Vector2f(150,50));
    RectangleShape attaque3(Vector2f(150,50));
    RectangleShape attaque4(Vector2f(150,50));

	RectangleShape afficheText(Vector2f(800,200));

	Text nomIcone[6];

    Text text;

    Text tour;
    
    Text statut1,statut2;

    string script="";

    Music musique;

    SoundBuffer buffer1,buffer2;

    Sound criLanceur,criEnnemi;

    Clock clk;                              //demarrer chrono

    Event event;

    srand(time(0));

	create(VideoMode(1280,720),"POKEMON");      //on cree la fenetre

    attaque1.setFillColor(Color::Blue);
    attaque2.setFillColor(Color::Blue);
    attaque3.setFillColor(Color::Blue);
    attaque4.setFillColor(Color::Blue);
    afficheText.setFillColor(Color::White);

    attaque1.setPosition(0,getSize().y-50);
    attaque2.setPosition(200,getSize().y-50);
    attaque3.setPosition(400,getSize().y-50);
    attaque4.setPosition(600,getSize().y-50);

    afficheText.setPosition(0,getSize().y-280);


    PokemonSwitch[0].setPosition(900,getSize().y-170);
    PokemonSwitch[1].setPosition(1100,getSize().y-170);
    PokemonSwitch[2].setPosition(900,getSize().y-110);
    PokemonSwitch[3].setPosition(1100,getSize().y-110);
	PokemonSwitch[4].setPosition(900,getSize().y-50);
    PokemonSwitch[5].setPosition(1100,getSize().y-50);

    for (int i=0;i<6;i++){
        nomIcone[i].setPosition(PokemonSwitch[i].getPosition().x+50,PokemonSwitch[i].getPosition().y);
    }

   	text.setFont(police);

	tour.setFont(police);
	tour.setPosition(0,0);

	text.setColor(sf::Color::Black);

	text.setPosition(5,getSize().y-260);
	text.setCharacterSize(15);

	J1=team1->getListePokemon()[0];
	J2=team2->getListePokemon()[0];

	script=("BATTLE\nJ1 envoie "+J1.getNom()+" !\nJ2 envoie "+J2.getNom()+" !\n");

    setFramerateLimit(60);                //limiter a 60 fps

    if (!buffer1.loadFromFile(J1.getPathCri()))
        return -1;

    if (!buffer2.loadFromFile(J2.getPathCri()))
        return -1;

    criLanceur.setBuffer(buffer1);
    criEnnemi.setBuffer(buffer2);

    if (!musique.openFromFile("Son/musique.ogg"))
            return -1; // erreur

    musique.setVolume(40);                          //lire la musique en boucle
    musique.setLoop(true);
    musique.play();


    if (!icone.loadFromFile("Image/pokeball.png"))
        return -1;

    if (!fond.loadFromFile("Image/landscape.jpeg"))
        return -1;

    if (!police.loadFromFile("Image/calibri.ttf"))
             return -1;

    fond_ecran.setSize(Vector2f(getSize().x,getSize().y));
    fond_ecran.setTexture(&fond);
    fond_ecran.setPosition(0,0);

    setIcon(32,32,icone.getPixelsPtr());                 //modifier l'icone de la fenetre


 while(this->isOpen()){                                         //boucle infinie
        randAtt=rand()%4;

        while (pollEvent(event)){                             //boucle des événements

            switch (event.type){

                case Event::Closed:                                 //si on ferme la fenetre
                    close();

                    break;

                case Event::KeyPressed:                             //si on appuie sur une touche

                    if (event.key.code==Keyboard::Escape)
                        close();

                    break;

/****************************************Gestion du clic sur les boutons***************************************************/

                case Event::MouseButtonPressed:                        //si on clique

                    if (event.mouseButton.button==Mouse::Left){             //bouton gauche
                       mouseX=Mouse::getPosition(*this).x;            //on recupere la position de la souris
                       mouseY=Mouse::getPosition(*this).y;

                        if (!J1.estKO()){
                    /***********************************Attaques ***************************/
                            if (attaque1.getGlobalBounds().contains(mouseX,mouseY)){        //si on clique sur les boutons d'attaque
							
		                     if (J1.getAttaque()[0].getPP()>0){ 					
                                if (J1.getVitesse()>=J2.getVitesse()){                  //celui qui la la+grande vitesse attaque en 1er

                                    script=J1.lancerAttaque(J1.getAttaque()[0],&J2);

                                    if (!J2.estKO())
                                        script+=J2.lancerAttaque(J2.getAttaque()[randAtt],&J1);
                                }
                                else{
                                    script=J2.lancerAttaque(J2.getAttaque()[randAtt],&J1);

                                    if (!J1.estKO())
                                        script+=J1.lancerAttaque(J1.getAttaque()[0],&J2);
                                 }

                              
                                    J1.getAttaque()[0].setPP(J1.getAttaque()[0].getPP()-1);		//on diminue les PP
                                    J2.getAttaque()[randAtt].setPP(J2.getAttaque()[randAtt].getPP()-1);
                                
                                    nbTour++; 
                                }
                                else{
                                    J1.getAttaque()[0].setPP(0);
                                    script="Plus de PP !";
                                }
                                                      //on augmente le nombre de tours
                            }

                            if (attaque2.getGlobalBounds().contains(mouseX,mouseY)){

                             if (J1.getAttaque()[1].getPP()>0){
                            
                              if (J1.getVitesse()>=J2.getVitesse()){

                                    script=J1.lancerAttaque(J1.getAttaque()[1],&J2)+"\n";

                                    if (!J2.estKO())
                                        script+=J2.lancerAttaque(J2.getAttaque()[randAtt],&J1)+"\n";
                                }
                                else{
                                    script=J2.lancerAttaque(J2.getAttaque()[randAtt],&J1)+"\n";

                                    if (!J1.estKO())
                                        script+=J1.lancerAttaque(J1.getAttaque()[1],&J2)+"\n";
                                 }

                                    J1.getAttaque()[1].setPP(J1.getAttaque()[1].getPP()-1);
                                    J2.getAttaque()[randAtt].setPP(J2.getAttaque()[randAtt].getPP()-1);
                                
                                  nbTour++;
                                }
                                else{
                                    J1.getAttaque()[1].setPP(0);
                                    script=("Plus de PP !");
                                }
                            }

                            if (attaque3.getGlobalBounds().contains(mouseX,mouseY)){
                              
                              if (J1.getAttaque()[2].getPP()>0){
                              
                                if (J1.getVitesse()>=J2.getVitesse()){

                                    script=J1.lancerAttaque(J1.getAttaque()[2],&J2)+"\n";

                                    if (!J2.estKO())
                                        script+=J2.lancerAttaque(J2.getAttaque()[randAtt],&J1)+"\n";
                                }
                                else{
                                    script=J2.lancerAttaque(J2.getAttaque()[randAtt],&J1)+"\n";

                                    if (!J1.estKO())
                                        script+=J1.lancerAttaque(J1.getAttaque()[2],&J2)+"\n";
                                 }


                                    J1.getAttaque()[2].setPP(J1.getAttaque()[2].getPP()-1);
                                    J2.getAttaque()[randAtt].setPP(J2.getAttaque()[randAtt].getPP()-1);
                                
                                nbTour++;
                                }
                                else{
                                    J1.getAttaque()[2].setPP(0);
                                    script=("Plus de PP !");
                                }
                            }

                            if (attaque4.getGlobalBounds().contains(mouseX,mouseY)){
              
                             if (J1.getAttaque()[3].getPP()>0){
                                if (J1.getVitesse()>=J2.getVitesse()){

                                    script=J1.lancerAttaque(J1.getAttaque()[3],&J2)+"\n";

                                    if (!J2.estKO())
                                        script+=J2.lancerAttaque(J2.getAttaque()[randAtt],&J1)+"\n";
                                }
                                else{
                                    script=J2.lancerAttaque(J2.getAttaque()[randAtt],&J1)+"\n";

                                    if (!J1.estKO())
                                        script+=J1.lancerAttaque(J1.getAttaque()[3],&J2)+"\n";
                                 }


                                    J1.getAttaque()[3].setPP(J1.getAttaque()[3].getPP()-1);
                                    J2.getAttaque()[randAtt].setPP(J2.getAttaque()[randAtt].getPP()-1);
                              
                              nbTour++;
                              
                               }
                                else{
                                    J1.getAttaque()[3].setPP(0);
                                    script="Plus de PP !";
                                }
                            }

                            if (lanceur.getGlobalBounds().contains(mouseX,mouseY)){             //si on clique sur le pokemon

                                criLanceur.play();                                              //on joue le cri
                            }

                            if (ennemi.getGlobalBounds().contains(mouseX,mouseY)){

                               criEnnemi.play();
                            }
                        }
                        else{
                            script=J1.getNom()+" est KO !";
                        }

/*******************************************Gestion du Switch******************************************************/

						for (unsigned int i=0;i<team1->getListePokemon().size();i++){            //on teste sur toute la liste

							if (PokemonSwitch[i].getGlobalBounds().contains(mouseX,mouseY)){    //si on clique sur le bouton de switch

                                if (!J1.estKO())  
                                    riposter=true;

                                if (team1->getListePokemon()[i].getNom()==J1.getNom()){               //on ne peut pas switcher sur le pokemon déjà en combat
                                    script=J1.getNom()+" est deja au combat!\n";
                                }
                                else{
                                    script=J1.getNom()+" est retire par J1!\n";
                                    script+="J1 envoie "+team1->getListePokemon()[i].getNom()+" !\n";

                                    for(unsigned int j=0;j<team1->getListePokemon().size();j++){
                                        if (team1->getListePokemon()[j].getNom()==J1.getNom()){      //on cherche l'ancien pokémon dans la liste
                                            team1->removePokemon(j);                                 //on le supprime
                                            team1->insertPokemon(J1,j);                              //on met à jour le pokémon avant le switch
                                        }
                                    }
                                    J1=team1->getListePokemon()[i];                                  //on récupère le nouveau pokémon à switcher

                                    if (!t1.loadFromFile(J1.getPath(true)))
                                        return -1;

                                    if (!buffer1.loadFromFile(J1.getPathCri()))
                                            return -1;

                                    lanceur.setScale(1,1);
                                    barreVieLanceur.setScale(1,1);
                                    barreVieLanceurBord.setScale(1,1);
                                    pvLanceur.setScale(1,1);
                                    nomLanceur.setScale(1,1);
                                    statut1.setScale(1,1);
									statut2.setScale(1,1);


                                    criLanceur.play();

                                    if (riposter){                                                  //si on switche sans etre KO, l'ennemi attaque quand meme
                                        riposter=false;
                                        script+=J2.lancerAttaque(J2.getAttaque()[randAtt],&J1)+"\n";
                                        J2.getAttaque()[randAtt].setPP(J2.getAttaque()[randAtt].getPP()-1);
                                        nbTour++;
                                    }
                                }
                            }
                     }
                }

                break;
                default:
                break;
            }

        }

    /****************************************Gestion des KO****************************************************************************/
        /*********************************Joueur 2******************************/

        if (J2.estKO()){

            if (team2->estVide()){
                ennemi.setScale(0,0);
                barreVieEnnemi.setScale(0,0);
                barreVieEnnemiBord.setScale(0,0);
                pvEnnemi.setScale(0,0);
                nomEnnemi.setScale(0,0);
                statut2.setScale(0,0);
                                                            //s'il n'y a plus de pokemon dans l'equipe, le joueur a perdu
               script="\nJ2 a perdu !\n";
               musique.stop();
            }
            else{                                                               //si le pokemon est KO
                for(unsigned int i=0;i<team2->getListePokemon().size();i++){     //on parcourt la liste pour trouver son emplacement

                    if (team2->getListePokemon()[i].getNom()==J2.getNom()){
                        team2->removePokemon(i);                                 //et on le supprime de la liste
                    }
                }

                 for(unsigned int i=0;i<team2->getListePokemon().size();i++){        //on reparcourt la liste qui a été diminuée

                    randPoke=rand()%(team2->getListePokemon().size());               //on envoie un pokémon aléatoirement parmi ceux qu restent

                    J2=team2->getListePokemon()[randPoke];

                   if (!buffer2.loadFromFile(J2.getPathCri()))
                        return -1;

                    criEnnemi.play();
                 }
            script+="\nJ2 envoie "+J2.getNom()+" !\n";
            }
        }
        /****************************Joueur 1*****************************************/

        if (J1.estKO()){

            lanceur.setScale(0,0);
            barreVieLanceur.setScale(0,0);
            barreVieLanceurBord.setScale(0,0);
            pvLanceur.setScale(0,0);
            nomLanceur.setScale(0,0);
            statut1.setScale(0,0);

              if (team1->estVide()){
                script="\nJ1 a perdu !\n";
                musique.stop();
              }
              else{

                for(unsigned int i=0;i<team1->getListePokemon().size();i++){

                    if (team1->getListePokemon()[i].getNom()==J1.getNom()){

                        team1->removePokemon(i);
                    }
                }
              }
        }

/*********************** Chargement et position Sprite **************************************************/
            /******************Joueur 1****************/
       if (!t1.loadFromFile(J1.getPath(false),IntRect(150,200,0,0))){ // Si le chargement du fichier a échoué
                  return -1; // On ferme le programme
           }
           else{
            t1.setSmooth(true);
            lanceur.setTexture(t1);
            lanceur.setTextureRect(IntRect(0,0,150,200));
            lanceur.setPosition(0,getSize().y-450);

               }
            /**************Joueur 2****************/
       if (!t2.loadFromFile(J2.getPath(true),IntRect(150,200,0,0))){
                  return -1;
            }
            else{
                t2.setSmooth(true);
                ennemi.setTexture(t2);
                ennemi.setTextureRect(IntRect(0,0,150,200));
                ennemi.setPosition(getSize().x-300,getSize().y-450);

                }

            /**************Icones & boutons switch****************/
        for (unsigned int i=0;i<team1->getListePokemon().size();i++){

            if (!textIcone[i].loadFromFile(PATH_IMAGE+ICONE+team1->getListePokemon()[i].getNom()+EXTENSION_IMAGE)){ // Si le chargement du fichier a échoué
                  return -1; // On ferme le programme
            }
            else{
                textIcone[i].setSmooth(true);                                              //lisser la texture
                iPokemon[i].setTexture(textIcone[i]);
                iPokemon[i].setPosition(PokemonSwitch[i].getPosition().x+5,PokemonSwitch[i].getPosition().y+5);
           }

            PokemonSwitch[i].setSize(Vector2f(140,50));

            nomIcone[i].setFont(police);
            nomIcone[i].setString(team1->getListePokemon()[i].getNom());
            nomIcone[i].setColor(Color::Black);
            nomIcone[i].setScale(0.5,0.5);

        }
/****************************************Positions & tailles des boutons/texte***************************************************/
			
			barreVieLanceur.setPosition(lanceur.getPosition().x+lanceur.getTextureRect().width,(lanceur.getPosition().y+lanceur.getTextureRect().height/4)-100);
            barreVieEnnemi.setPosition(ennemi.getPosition().x-ennemi.getTextureRect().width-150,(ennemi.getPosition().y+ennemi.getTextureRect().height/4)-100);

            barreVieLanceurBord.setPosition(barreVieLanceur.getPosition().x-2,barreVieLanceur.getPosition().y-2);
            barreVieEnnemiBord.setPosition(barreVieEnnemi.getPosition().x-2,barreVieEnnemi.getPosition().y-2);

            barreVieLanceurBord.setOutlineColor(Color::Black);
            barreVieEnnemiBord.setOutlineColor(Color::Black);
			
			
			statut1.setFont(police);
			statut1.setString("Statut: "+J1.getStatut());
			statut1.setColor(Color::White);
			statut1.setPosition(barreVieLanceur.getPosition().x,barreVieLanceur.getPosition().y+20);
			statut1.setCharacterSize(20);
			
			statut2.setFont(police);
			statut2.setString("Statut: "+J2.getStatut());
			statut2.setColor(Color::White);
			statut2.setPosition(barreVieEnnemi.getPosition().x,barreVieLanceur.getPosition().y+20);
			statut2.setCharacterSize(20);
			
            nomLanceur.setString(J1.getNom());
            nomLanceur.setFont(police);
            nomLanceur.setColor(Color::Red);
            nomLanceur.setPosition(lanceur.getPosition().x+lanceur.getTextureRect().width,lanceur.getPosition().y-100);

            nomEnnemi.setString(J2.getNom());
            nomEnnemi.setFont(police);
            nomEnnemi.setColor(Color::Blue);
            nomEnnemi.setPosition(barreVieEnnemi.getPosition().x,barreVieEnnemi.getPosition().y-42);

            nomAttaque1.setString(J1.getAttaque()[0].getNom());
            nomAttaque1.setFont(police);
            nomAttaque1.setPosition(attaque1.getPosition());
            nomAttaque1.setScale(0.75,0.75);
            type1.setFont(police);
            type1.setString(J1.getAttaque()[0].getType().getNom()+"         PP: "+Pokemon::Pokemon::toString(J1.getAttaque()[0].getPP())+"/"+Pokemon::Pokemon::toString(J1.getAttaque()[0].getPPfixe()));
            type1.setPosition(nomAttaque1.getPosition().x,nomAttaque1.getPosition().y+30);
            type1.setScale(0.5,0.5);

            nomAttaque2.setString(J1.getAttaque()[1].getNom());
            nomAttaque2.setFont(police);
            nomAttaque2.setPosition(attaque2.getPosition());
            nomAttaque2.setScale(0.75,0.75);
            type2.setFont(police);
            type2.setString(J1.getAttaque()[1].getType().getNom()+"         PP: "+Pokemon::Pokemon::toString(J1.getAttaque()[1].getPP())+"/"+Pokemon::Pokemon::toString(J1.getAttaque()[1].getPPfixe()));
            type2.setPosition(nomAttaque2.getPosition().x,nomAttaque2.getPosition().y+30);
            type2.setScale(0.5,0.5);

            nomAttaque3.setString(J1.getAttaque()[2].getNom());
            nomAttaque3.setFont(police);
            nomAttaque3.setPosition(attaque3.getPosition());
            nomAttaque3.setScale(0.75,0.75);
            type3.setFont(police);
            type3.setString(J1.getAttaque()[2].getType().getNom()+"         PP: "+Pokemon::toString(J1.getAttaque()[2].getPP())+"/"+Pokemon::toString(J1.getAttaque()[2].getPPfixe()));
            type3.setPosition(nomAttaque3.getPosition().x,nomAttaque3.getPosition().y+30);
            type3.setScale(0.5,0.5);

            nomAttaque4.setString(J1.getAttaque()[3].getNom());
            nomAttaque4.setFont(police);
            nomAttaque4.setPosition(attaque4.getPosition());
            nomAttaque4.setScale(0.75,0.75);
            type4.setFont(police);
            type4.setString(J1.getAttaque()[3].getType().getNom()+"         PP: "+Pokemon::toString(J1.getAttaque()[3].getPP())+"/"+Pokemon::toString(J1.getAttaque()[3].getPPfixe()));
            type4.setPosition(nomAttaque4.getPosition().x,nomAttaque4.getPosition().y+30);
            type4.setScale(0.5,0.5);

            if ((100*J1.getPV()/J1.getPVmax()) >= 66 ) {
                    barreVieLanceur.setFillColor(Color::Green);
            }
            else{

                if ((100*J1.getPV()/J1.getPVmax()) >= 33  ) {
                    barreVieLanceur.setFillColor(Color::Yellow);
                }
                else{
                    barreVieLanceur.setFillColor(Color::Red);
                }
            }

            if ((100*J2.getPV()/J2.getPVmax()) >= 66  ) {
                barreVieEnnemi.setFillColor(Color::Green);

            }
            else{

                if ((100*J2.getPV()/J2.getPVmax()) >= 33) {
                    barreVieEnnemi.setFillColor(Color::Yellow);

                }
                else{
                    barreVieEnnemi.setFillColor(Color::Red);
                }
            }



            text.setString(script);
            tour.setString("Tour: "+Pokemon::toString(nbTour)+" Pokemon restants: "+Pokemon::toString((int)team2->getListePokemon().size()));

            barreVieLanceur.setSize(Vector2f((J1.getPV()*200)/J1.getPVmax(),20));
            barreVieEnnemi.setSize(Vector2f((J2.getPV()*200)/J2.getPVmax(),20));

            pvLanceur.setFont(police);
            pvLanceur.setString(Pokemon::toString(100*J1.getPV()/J1.getPVmax())+"%");
            pvLanceur.setPosition(barreVieLanceur.getPosition().x+barreVieLanceur.getSize().x-pvLanceur.getGlobalBounds().width,barreVieLanceur.getPosition().y);
            pvLanceur.setCharacterSize(18);
            pvLanceur.setColor(Color::Black);

            pvEnnemi.setFont(police);
            pvEnnemi.setString(Pokemon::toString(100*J2.getPV()/J2.getPVmax())+"%");
            pvEnnemi.setPosition(barreVieEnnemi.getPosition().x+barreVieEnnemi.getSize().x-pvEnnemi.getGlobalBounds().width,barreVieEnnemi.getPosition().y);
            pvEnnemi.setCharacterSize(18);
            pvEnnemi.setColor(Color::Black);

/****************************Affichages ***************************************/
            clear(Color::White);

            draw(fond_ecran);

            draw(ennemi);
            draw(lanceur);

            draw(afficheText);

            draw(barreVieLanceurBord);
            draw(barreVieEnnemiBord);

            draw(barreVieLanceur);
            draw(barreVieEnnemi);

            draw(nomLanceur);
            draw(nomEnnemi);

            draw(attaque1);
            draw(attaque2);
            draw(attaque3);
            draw(attaque4);

            draw(nomAttaque1);
            draw(nomAttaque2);
            draw(nomAttaque3);
            draw(nomAttaque4);

            draw(type1);
            draw(type2);
            draw(type3);
            draw(type4);
            
            draw(statut1);
            draw(statut2);

        for(unsigned int k=0;k<team1->getListePokemon().size();k++)
        {
            draw(PokemonSwitch[k]);
            draw(iPokemon[k]);
            draw(nomIcone[k]);
        }

            draw(text);
            draw(tour);

            draw(pvEnnemi);
            draw(pvLanceur);

            display();
    }

return EXIT_SUCCESS;
}
