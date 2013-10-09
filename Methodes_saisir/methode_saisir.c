#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>
//#include "/home/tbruhiere/Projet_Mathematiques/Parametre.h"

#include "saisir_fonction.c"
#include "saisir_mu.c"
#include "saisir_j.c"
#include "saisir_n.c"
#include "saisir_l.c"

#include "saisir_deb_periode.c"
#include "saisir_fin_periode.c"

#include "confirm.c"

/*********************************************************************
*************************************

	Ce fichier permet de configurer la fenetre de saisi des valeurs necessaires
	au calcul de la transformer rapide de fourier d'une fonction choisi
	par l'utilisateur.

	create : 02/10/2013
	derniere modification : 02/10/2013 - 18:21

************************************
**********************************************************************/
  

void CatchValue_Function()
{
	/************************************************************
	****	Variables					  ***\
	*************************************************************/
	int i; //compteur

	//Fenêtre
	GtkWidget* CatchValue_Window; //Déclaration de la fenêtre principal

	//Box
	GtkWidget* VBox; //Box verticale contenu dans la fenêtre principal
	GtkWidget* HBox[6]; // Box horizontale rassemblant tout ce qui permet de saisir le paramètre

	//Label
	GtkWidget* Label[6]; //Exemple type : "Saisir *parametre* : "
	GtkWidget* Label_Value[6]; //Exemple type : "Valeur enregistrer" ou "Erreur : ..."

	//Entry
	GtkWidget* Entry[6]; //Zone de saisi du paramètre

	//Button
	GtkWidget* Btn[6]; //Bouton de confirmation de saisi d'un paramètre
	GtkWidget* Btn_confirm; //Bouton pour confirmer toutes les saisis

	//Image
	GtkWidget* Im_EtatValue; //Image d'illustration

	//Séparateur
	GtkWidget* HSep; //Séparateur horizontale après la saisi des valeurs


	/************************************************************
        ****    DEBUT FONCTION       ***\
        ************************************************************/

	//Configuration de la fenêtre principal
	CatchValue_Window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //Création de la fenêtre
	gtk_window_set_title(GTK_WINDOW(CatchValue_Window), "Fenetre - saisis des valeurs"); //Titre de la fenêtre
	gtk_window_set_default_size(GTK_WINDOW(CatchValue_Window), 50, 50); //Taille minimum de la fenêtre
	gtk_container_set_border_width(GTK_CONTAINER(CatchValue_Window), 5);
	gtk_window_set_position(GTK_WINDOW(CatchValue_Window), GTK_WIN_POS_CENTER); //Postionne la fenetre au centre de l'ecran
	gtk_window_set_resizable(GTK_WINDOW(CatchValue_Window), FALSE); // Il n'est pas possible de modifier la taille de la fenêtre


	//Insertion de la Vbox dans la fenêtre principal
	VBox = gtk_vbox_new(TRUE, 0);
	gtk_container_add(GTK_CONTAINER(CatchValue_Window), VBox);


        /**     Zone => saisi de fonction (chaine de caractère)    **/
        /************************************************************/

	for ( i = 0; i <=6; i = i + 1)
	{ 
		//Insertion de la HBox dans la VBox
		HBox[i] = gtk_hbox_new(TRUE, 0);
		gtk_box_pack_start(GTK_BOX(VBox), HBox[i], TRUE, TRUE, 0);

		//On veut maintenant savoir quel paramètre on est en train de gérer
		switch(i)
		{
			case 0:
				Label[i] = gtk_label_new("Saisir la fonction : ");
				break;

			case 1:
				Label[i] = gtk_label_new("Saisir mu (entier positif) : ");
				break;
			case 2:
				Label[i] = gtk_label_new("Saisir j (entier positif <= mu) : ");
				break;

			case 3:
				Label[i] = gtk_label_new("Saisir l (entier positif) : ");
				break;

			case 4:
				Label[i] = gtk_label_new("Saisir N (modulo 2) : ");
				break;

			case 5:
				Label[i] = gtk_label_new("Saisir debut de periode : ");
				break;

			case 6:
				Label[i] = gtk_label_new("Saisir fin de periode : ");
				break;

			default:
				//Nothing because impossible
				break;
		}		

		//Insertion du label, du entry et du bouton dans la Hbox
		Entry[i] = gtk_entry_new(); //Zone de saisi pour l'utilisateur
		Btn[i] = gtk_button_new_with_label(">>"); //Bouton de comfirmation de saisi
		Im_EtatValue = gtk_image_new(); // Image d'illustration
		Label_Value[i] = gtk_label_new(NULL); // Ce label indique à l'utilisateur si la valeur qu'il a mise est possible ou non

		//On insère chaque widget précedement déclaré dans la HBox
		gtk_box_pack_start(GTK_BOX(HBox[i]), Label[i], TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(HBox[i]), Entry[i], TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(HBox[i]), Btn[i], TRUE, TRUE, 0);
		gtk_box_pack_start(GTK_BOX(HBox[i]), Label_Value[i], FALSE, FALSE, 0);
		gtk_box_pack_start(GTK_BOX(HBox[i]), Im_EtatValue, FALSE, FALSE, 0);

	}

	// Lorque l'utilisateur appuie sur le bouton, alors le signal correspondant est activé 
	//g_signal_connect(G_OBJECT(Btn[0]), "clicked", G_CALLBACK(CheckValue_function), (GtkWidget*) HBox[0]);
	g_signal_connect(G_OBJECT(Btn[1]), "clicked", G_CALLBACK(CheckValue_mu), (GtkWidget*) HBox[1]);
	g_signal_connect(G_OBJECT(Btn[2]), "clicked", G_CALLBACK(CheckValue_j), (GtkWidget*) HBox[2]);
	g_signal_connect(G_OBJECT(Btn[3]), "clicked", G_CALLBACK(CheckValue_l), (GtkWidget*) HBox[3]);
	g_signal_connect(G_OBJECT(Btn[4]), "clicked", G_CALLBACK(CheckValue_N), (GtkWidget*) HBox[4]);
	g_signal_connect(G_OBJECT(Btn[5]), "clicked", G_CALLBACK(CheckValue_deb_p), (GtkWidget*) HBox[5]);
	g_signal_connect(G_OBJECT(Btn[6]), "clicked", G_CALLBACK(CheckValue_fin_p), (GtkWidget*) HBox[6]);



        /**     Zone => Confirmation des saisie                                            **/
        /***********************************************************************************/
	HSep = gtk_hseparator_new(); //Création du séparateur
	gtk_box_pack_start(GTK_BOX(VBox), HSep, TRUE, FALSE, 0); //Insertion dans la VBox

	Btn_confirm = gtk_button_new_with_label("Commencer le calculs >>");
	gtk_box_pack_start(GTK_BOX(VBox), Btn_confirm, FALSE, FALSE, 0);

	// Connexion du signal "clicked" au bouton "Btn_confirm"
	g_signal_connect(G_OBJECT(Btn_confirm), "clicked", G_CALLBACK(ConfirmValue), (GtkWidget*) CatchValue_Window);



	/************************************************************
        ****    FIN FONCTION       ***\
        *************************************************************/
	gtk_widget_show_all(CatchValue_Window); //affiche l'ensemble de la fenêtre principal

	gtk_main(); //boucle infini pour que le fenêtre reste ouverte
	g_signal_connect(G_OBJECT(CatchValue_Window), "destroy", G_CALLBACK(gtk_main_quit), NULL); //Signal destroy pour fermer la fenêtre avec la croix en haut

}











