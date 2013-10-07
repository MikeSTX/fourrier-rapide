#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>

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

	//Fenêtre
	GtkWidget* CatchValue_Window; //Déclaration de la fenêtre principal

	//Box
	GtkWidget* VBox; //Box verticale contenu dans la fenêtre principal
	
	GtkWidget* HBox_function; // Box horizontale rassemblant tout ce qui permet de saisir la fonction
	GtkWidget* HBox_mu; //Box horizontale rassemblant tout ce qui permet de saisir mu
	GtkWidget* HBox_j; // Box horizontale rassemblant tout ce qui permet de saisir j
	GtkWidget* HBox_N; // Box horizontale rassemblant tout ce qui permet de saisir N (nombre de termes);
	GtkWidget* HBox_l; //Box horizontale rassemblant tout ce qui permet de saisir l

	GtkWidget* HBox_deb_p; //Box horizontale rassemblant tout ce qui permet de saisir le debut de la période
	GtkWidget* HBox_fin_p; //Box horinzontale rassemblant tout ce qui permet de saisir la fin de la période

	//Label
	GtkWidget* Label_function;
	GtkWidget* Label_Value_function;

	GtkWidget* Label_mu;
	GtkWidget* Label_Value_mu;

	GtkWidget* Label_j;
	GtkWidget* Label_Value_j;

	GtkWidget* Label_N;
	GtkWidget* Label_Value_N;

	GtkWidget* Label_l;
	GtkWidget* Label_Value_l;

	GtkWidget* Label_deb_p;
	GtkWidget* Label_Value_deb_p;
	GtkWidget* Label_fin_p;
	GtkWidget* Label_Value_fin_p;


	//Entry
	GtkWidget* Entry_function; //Zone de saisi de la fonction
	GtkWidget* Entry_mu; //Zone de saisi de mu
	GtkWidget* Entry_j; //Zone de saisi de j
	GtkWidget* Entry_N; //Zone de saisi de N	
	GtkWidget* Entry_l; //Zone de saisi de l

	GtkWidget* Entry_deb_p; //Zone de saisi du début de période
	GtkWidget* Entry_fin_p; //Zone de saisi de fin de période

	//Button
	GtkWidget* Btn_function; //Bouton pour valider la saisi de la fonction
	GtkWidget* Btn_mu; //Bouton pour valider la saisi de "mu"
	GtkWidget* Btn_j; //Bouton pour valider la saisi de "j"
	GtkWidget* Btn_N; //Bouton pour valider la saisi de "N"
	GtkWidget* Btn_l; //Bouton pour valider la saisi de "l"

	GtkWidget* Btn_deb_p; //Bouton pour valider la saisi du début de la période
	GtkWidget* Btn_fin_p; //Bouton pour valider la saisi de la fin de la période

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
	gtk_window_set_resizable(GTK_WINDOW(CatchValue_Window), FALSE); // Il n'est pas possible de modifier la taille de la fenêtre
	//gtk_window_set_focus(GTK_WINDOW(CatchValue_Window), Entry_function); //Le premier Entry de la fenêtre aura le focus

	//Insertion de la Vbox dans la fenêtre principal
	VBox = gtk_vbox_new(TRUE, 0);
	gtk_container_add(GTK_CONTAINER(CatchValue_Window), VBox);


        /**     Zone => saisi de fonction (chaine de caractère)    **/
        /************************************************************/

        //Insertion de la HBox_mu dans la VBox
        HBox_function = gtk_hbox_new(TRUE, 0);
        gtk_box_pack_start(GTK_BOX(VBox), HBox_function, TRUE, TRUE, 0);

        //Insertion du label, du entry et du bouton dans la Hbox
        Label_function = gtk_label_new("Saisir la fonction : ");
        Entry_function = gtk_entry_new();
        Btn_function = gtk_button_new_with_label(">>");
        Im_EtatValue = gtk_image_new();
        Label_Value_function = gtk_label_new(NULL); // Ce label stock le nombre que mettra l'utilisateu, on pourra alors dire si la valeur est fausse ou non

        gtk_box_pack_start(GTK_BOX(HBox_function), Label_function, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_function), Entry_function, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_function), Btn_function, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_function), Label_Value_function, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_function), Im_EtatValue, FALSE, FALSE, 0);

        gtk_window_set_focus(GTK_WINDOW(CatchValue_Window), Entry_function); //Le premier Entry de la fenêtre aura le focus

        // Connexion du signal "clicked" du bouton "Btn_mu" 
        g_signal_connect(G_OBJECT(Btn_function), "clicked", G_CALLBACK(CheckValue_function), (GtkWidget*) HBox_function);




	/**	Zone => saisi de mu (entier positif)	**/
	/*************************************************/

	//Insertion de la HBox_mu dans la VBox
	HBox_mu = gtk_hbox_new(TRUE, 0);
	gtk_box_pack_start(GTK_BOX(VBox), HBox_mu, TRUE, TRUE, 0);

	//Insertion du label, du entry et du bouton dans la Hbox
	Label_mu = gtk_label_new("Saisir mu (entier positif) : ");
	Entry_mu = gtk_entry_new();
	Btn_mu = gtk_button_new_with_label(">>");
	Im_EtatValue = gtk_image_new();
	Label_Value_mu = gtk_label_new(NULL); // Ce label stock le nombre que mettra l'utilisateu, on pourra alors dire si la valeur est fausse ou non

	gtk_box_pack_start(GTK_BOX(HBox_mu), Label_mu, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(HBox_mu), Entry_mu, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(HBox_mu), Btn_mu, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(HBox_mu), Label_Value_mu, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(HBox_mu), Im_EtatValue, FALSE, FALSE, 0);

	// Connexion du signal "clicked" du bouton "Btn_mu" 
	g_signal_connect(G_OBJECT(Btn_mu), "clicked", G_CALLBACK(CheckValue_mu), (GtkWidget*) HBox_mu);

	


	/**	Zone => saisi de j (entier positif inférieur ou égale à mu)	**/
	/*************************************************************************/
	HBox_j = gtk_hbox_new(TRUE, 0);
	gtk_box_pack_start(GTK_BOX(VBox), HBox_j, TRUE, TRUE, 0);

	//Insertion du label, du entry et du bouton dans la HBox
	Label_j = gtk_label_new("Saisir j (entier positif < mu) : ");
	Entry_j = gtk_entry_new();
	Btn_j = gtk_button_new_with_label(">>");
	Im_EtatValue = gtk_image_new();
	Label_Value_j = gtk_label_new(NULL); //Ce label stock le nombre mis par l'utilisateur

	gtk_box_pack_start(GTK_BOX(HBox_j), Label_j, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(HBox_j), Entry_j, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(HBox_j), Btn_j, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(HBox_j), Label_Value_j, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(HBox_j), Im_EtatValue, FALSE, FALSE, 0);

	// Connexion du signal "clicked" au bouton "Btn_j"
	g_signal_connect(G_OBJECT(Btn_j), "clicked", G_CALLBACK(CheckValue_j), (GtkWidget*) HBox_j);




        /**     Zone => saisi de N (entier positif modulo 2 et inférieur à pow(2,j))      **/
        /***********************************************************************************/
        HBox_N = gtk_hbox_new(TRUE, 0); 
        gtk_box_pack_start(GTK_BOX(VBox), HBox_N, TRUE, TRUE, 0); 

        //Insertion du label, du entry et du bouton dans la HBox
        Label_N = gtk_label_new("Saisir N (entier positif modulo 2 < 2^j) : ");
        Entry_N = gtk_entry_new();
        Btn_N = gtk_button_new_with_label(">>");
        Im_EtatValue = gtk_image_new();
        Label_Value_N = gtk_label_new(NULL); //Ce label stock le nombre mis par l'utilisateur

        gtk_box_pack_start(GTK_BOX(HBox_N), Label_N, TRUE, TRUE, 0); 
        gtk_box_pack_start(GTK_BOX(HBox_N), Entry_N, TRUE, TRUE, 0); 
        gtk_box_pack_start(GTK_BOX(HBox_N), Btn_N, FALSE, FALSE, 0); 
        gtk_box_pack_start(GTK_BOX(HBox_N), Label_Value_N, FALSE, FALSE, 0); 
        gtk_box_pack_start(GTK_BOX(HBox_N), Im_EtatValue, FALSE, FALSE, 0); 

        // Connexion du signal "clicked" au bouton "Btn_j"
        g_signal_connect(G_OBJECT(Btn_N), "clicked", G_CALLBACK(CheckValue_N), (GtkWidget*) HBox_N);




	/**     Zone => saisi de l (entier positif inférieur à pow(2,mu-j))      **/
        /***********************************************************************************/
        HBox_l = gtk_hbox_new(TRUE, 0);
        gtk_box_pack_start(GTK_BOX(VBox), HBox_l, TRUE, TRUE, 0);

        //Insertion du label, du entry et du bouton dans la HBox
        Label_l = gtk_label_new("Saisir l (entier positif < 2^(mu-j)) : ");
        Entry_l = gtk_entry_new();
        Btn_l = gtk_button_new_with_label(">>");
        Im_EtatValue = gtk_image_new();
        Label_Value_l = gtk_label_new(NULL); //Ce label stock le nombre mis par l'utilisateur

        gtk_box_pack_start(GTK_BOX(HBox_l), Label_l, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_l), Entry_l, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_l), Btn_l, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_l), Label_Value_l, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_l), Im_EtatValue, FALSE, FALSE, 0);

        // Connexion du signal "clicked" au bouton "Btn_j"
        g_signal_connect(G_OBJECT(Btn_l), "clicked", G_CALLBACK(CheckValue_l), (GtkWidget*) HBox_l);



        /**     Zone => saisi de deb_p (relatif à pi)				           **/
        /***********************************************************************************/
        HBox_deb_p = gtk_hbox_new(TRUE, 0);
        gtk_box_pack_start(GTK_BOX(VBox), HBox_deb_p, TRUE, TRUE, 0);

        //Insertion du label, du entry et du bouton dans la HBox
        Label_deb_p = gtk_label_new("Saisir le debut de periode : ");
        Entry_deb_p = gtk_entry_new();
        Btn_deb_p = gtk_button_new_with_label(">>");
        Im_EtatValue = gtk_image_new();
        Label_Value_deb_p = gtk_label_new(NULL); //Ce label stock le nombre mis par l'utilisateur

        gtk_box_pack_start(GTK_BOX(HBox_deb_p), Label_deb_p, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_deb_p), Entry_deb_p, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_deb_p), Btn_deb_p, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_deb_p), Label_Value_deb_p, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_deb_p), Im_EtatValue, FALSE, FALSE, 0);

        // Connexion du signal "clicked" au bouton "Btn_j"
        g_signal_connect(G_OBJECT(Btn_deb_p), "clicked", G_CALLBACK(CheckValue_deb_p), (GtkWidget*) HBox_deb_p);



        /**     Zone => saisi de fin_p (relatif à pi)				          **/
        /***********************************************************************************/
        HBox_fin_p = gtk_hbox_new(TRUE, 0);
        gtk_box_pack_start(GTK_BOX(VBox), HBox_fin_p, TRUE, TRUE, 0);

        //Insertion du label, du entry et du bouton dans la HBox
        Label_fin_p = gtk_label_new("Saisir la fin de la periode : ");
        Entry_fin_p = gtk_entry_new();
        Btn_fin_p = gtk_button_new_with_label(">>");
        Im_EtatValue = gtk_image_new();
        Label_Value_fin_p = gtk_label_new(NULL); //Ce label stock le nombre mis par l'utilisateur

        gtk_box_pack_start(GTK_BOX(HBox_fin_p), Label_fin_p, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_fin_p), Entry_fin_p, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_fin_p), Btn_fin_p, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_fin_p), Label_Value_fin_p, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(HBox_fin_p), Im_EtatValue, FALSE, FALSE, 0);

        // Connexion du signal "clicked" au bouton "Btn_j"
        g_signal_connect(G_OBJECT(Btn_fin_p), "clicked", G_CALLBACK(CheckValue_fin_p), (GtkWidget*) HBox_fin_p);




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











