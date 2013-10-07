#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>

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
	GtkWidget* GetResult_Window;



        /************************************************************
        ****    DEBUT FONCTION       ***\
        ************************************************************/
	
	//Configuration de la fenêtre principale
	GetResult_Window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //Création de la fenêtre
	gtk_window_set_title(GTK_WINDOW(GetResult_Window), "Fenetre - Resultat"); //Titre de la fenêtre
	gtk_window_set_default_size(GTK_WINDOW(GetResult_Window), 50, 50); //Taille minimum de la fenêtre
	gtk_container_set_border_width(GTK_CONTAINER(GetResult_Window), 5);	


        /************************************************************
        ****    FIN FONCTION       ***\
        *************************************************************/
	gtk_widget_show_all(GetResult_Window); // affiche l'ensemble de la fenêtre principal

	gtk_main();
	g_signal_connect(G_OBJECT(GetResult_Window), "destroy", G_CALLBACK(gtk_main_quit), NULL); //Signal destroy pour fermer la fenêtre avec la croix du haut


}
