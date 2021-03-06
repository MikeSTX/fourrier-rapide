#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>

#include "Check_Parametre.c"


/*********************************************************************
*************************************

        Ce fichier permet, à partir des données renté par l'utilisateur, de calculer
	à travers les différentes étapes la transformé de FOURIER rapide

        create : 02/10/2013
        derniere modification : 02/10/2013 - 18:21

************************************
**********************************************************************/


void GetResult_Function()
{
        /************************************************************
        ****    Variables                                         ***\
        *************************************************************/

	//Fenetre
	GtkWidget* GetResult_Window;

	//Table
	GtkWidget* Table;

	//Labels
	GtkWidget* Etat_Load_Calcul;

	//Boutons

	//Barre de progression
	GtkWidget* Progress;	

	//Frame
	GtkWidget* Frame; //Décoration pour mettre en valeur le résultat finale

	//Texte de saisi
	GtkWidget* Calcul_view; //Permet de voir les différentes étapes du calcul (debug)

	//Variable nécessaire pour recopier le text d'un fichier dans la zone "texte de saisi"
	GtkTextBuffer* buffer;
	GtkTextIter start;
	GtkTextIter end;
	FILE *fichier;
	const gchar* chemain;
	gchar lecture[1024];



        /************************************************************
        ****    DEBUT FONCTION       ***\
        ************************************************************/
	
	//Configuration de la fenêtre principale
	GetResult_Window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //Création de la fenêtre
	gtk_window_set_title(GTK_WINDOW(GetResult_Window), "Fenetre - Resultat"); //Titre de la fenêtre
	gtk_window_set_default_size(GTK_WINDOW(GetResult_Window), 500, 780); //Taille minimum de la fenêtre
	gtk_window_set_position(GTK_WINDOW(GetResult_Window), GTK_WIN_POS_CENTER); //Postionne la fenetre au centre de l'ecran
	gtk_container_set_border_width(GTK_CONTAINER(GetResult_Window), 5);	

	//Insertion de la table, cela permet d'insérer une grille invisible pour placer plus facilement les différents Widget de la fenêtre
	Table = gtk_table_new(20, 10, TRUE); //La fenêtre est divisé 10 fois en x et 20 fois en y
	gtk_container_add(GTK_CONTAINER(GetResult_Window), GTK_WIDGET(Table)); //Insertion de la table dans la fenetre

	//Insertion de label qui indique si le calcul est en cours ou fini
	Etat_Load_Calcul = gtk_label_new("Calcul en cours ...");
	gtk_table_attach_defaults(GTK_TABLE(Table), Etat_Load_Calcul, 3, 7, 0, 1); //Positionne le label dans la table

	//Insertion de la barre de progression, indicateur du temps de calcul
	Progress = gtk_progress_bar_new();
	gtk_table_attach_defaults(GTK_TABLE(Table), Progress, 1, 9, 1, 2);
		
	//Insertion de la fenêtre de visualisation des étapes du calcul
	Calcul_view = gtk_text_view_new();
	gtk_table_attach_defaults(GTK_TABLE(Table), Calcul_view, 1, 9, 3, 13);
	gtk_widget_set_size_request(Calcul_view, 320, 240); //Ne déforme pas la fenêtre si le text dépasse la taille de zone Calcul_view


	//Insertion du cadre décoratif
	Frame = gtk_frame_new("Resultat final");
	gtk_table_attach_defaults(GTK_TABLE(Table), Frame, 1, 9, 15, 19);	

	/**********************************************************************************
	**	DEBUT DU CALCUL
	**********************************************************************************/
	Check_Parametre(); //Rappel des parametre à l'utilisateur
	//Ecriture dans la zone "saisi de texte"
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(Calcul_view));
	fichier = fopen("/home/tbruhiere/Projet_Mathematiques/.StepCalcul.txt", "rt");
	gtk_text_buffer_get_start_iter(buffer, &start);
	gtk_text_buffer_get_end_iter(buffer, &end);
	gtk_text_buffer_delete(buffer, &start, &end);

	while (fgets(lecture, 1024, fichier))
	{
		gtk_text_buffer_get_end_iter(buffer, &end);
		gtk_text_buffer_insert(buffer, &end, g_locale_to_utf8(lecture, -1, NULL, NULL, NULL), -1);
	}

	fclose(fichier);
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(Progress), 0.01);




        /************************************************************
        ****    FIN FONCTION       ***\
        *************************************************************/
	gtk_widget_show_all(GetResult_Window); // affiche l'ensemble de la fenêtre principal

	gtk_main();
	g_signal_connect(G_OBJECT(GetResult_Window), "destroy", G_CALLBACK(gtk_main_quit), NULL); //Signal destroy pour fermer la fenêtre avec la croix du haut


}
