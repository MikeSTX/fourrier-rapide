#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>



void CheckValue_j(GtkWidget *Btn[2], gpointer data);


void CheckValue_j(GtkWidget *Btn[2], gpointer data)
{
	//Variables
	GtkWidget *pTempEntry;
        GtkWidget *pTempLabel;
        GtkWidget *pTempLabel_useless;
        GtkImage *pTempImage;
        GList *pList; //Liste chainé pour passer d'un widget à un autre

	const gchar* j;
	gint j_int;

	//DEBUT FONCTION
	

	//Interface utilisateur
	pList = gtk_container_get_children(GTK_CONTAINER((GtkWidget*)data)); //On recupère tous les widget de la HBox
	pTempLabel_useless = GTK_WIDGET(pList->data); //Le premier élément est un label (ininteressant)

        pList = g_list_next(pList); //On passe à l'élément suivant => la saisi utilisateur (interessant)
        pTempEntry = GTK_WIDGET(pList->data);//On recupère sa valeur 

	pList = g_list_next(pList); //Element suivant => bouton (inintéressant) 
  
        pList = g_list_next(pList); //Element suivant => label (interessant)
        pTempLabel = GTK_WIDGET(pList->data); //On recupère sa valeur
  
        j = gtk_entry_get_text(GTK_ENTRY(pTempEntry)); //On recupère la valeur contenu dans     la zone de saisi
	

	j_int = strtol(j, NULL, 10);	

	pList = g_list_next(pList); //Element suivant => image
	pTempImage = GTK_IMAGE(pList->data); //On la stock dans un variable

	//On analyse cette valeur pour voir si elle respecte les consignes
	if (j_int >= 0 && j_int <= P.mu)
	{
		gtk_image_set_from_file(GTK_IMAGE(pTempImage), "Image/Validation.png");
		gtk_label_set_text(GTK_LABEL(pTempLabel), "Valeur enregistrer");
		P.j = j_int;
	}
	else
	{
		gtk_image_set_from_file(GTK_IMAGE(pTempImage), "Image/Refus.jpg");
		
		if(j_int < 0)
		{
			gtk_label_set_text(GTK_LABEL(pTempLabel), "Erreur : valeur negative");
		}

		if(j_int > P.mu)
		{
			gtk_label_set_text(GTK_LABEL(pTempLabel), "Erreur : j > mu");
		}

	}

	//FIN FONCTION
	g_list_free(pList); //On libère l'espace de la liste chainé

}


