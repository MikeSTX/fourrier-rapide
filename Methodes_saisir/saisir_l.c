#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>


void CheckValue_l(GtkWidget *Btn[3], gpointer data);


void CheckValue_l(GtkWidget *Btn[3], gpointer data)
{
	//Variables
        GtkWidget *pTempEntry;
        GtkWidget *pTempLabel;
        GtkWidget *pTempLabel_useless;
        GtkImage *pTempImage;
        GList *pList; //Liste chainé pour passer d'un widget à un autre

        const gchar* l;
        gint l_int;
  

	//DEBUT FONCTION


	//Interface utilisateur
         pList = gtk_container_get_children(GTK_CONTAINER((GtkWidget*)data)); //On recupère tous les widget de la HBox
        pTempLabel_useless = GTK_WIDGET(pList->data); //Le premier élément est un label (ininteressant)

        pList = g_list_next(pList); //On passe à l'élément suivant => la saisi utilisateur (interessant)
        pTempEntry = GTK_WIDGET(pList->data);//On recupère sa valeur 

	pList = g_list_next(pList); //Element suivant => bouton (inintéressant) 

        pList = g_list_next(pList); //Element suivant => label (interessant)
        pTempLabel = GTK_WIDGET(pList->data); //On recupère sa valeur

        l = gtk_entry_get_text(GTK_ENTRY(pTempEntry)); //On recupère la valeur contenu dans     la zone de saisi


        l_int = strtol(l, NULL, 10);

        pList = g_list_next(pList); //Element suivant => image
        pTempImage = GTK_IMAGE(pList->data); //On la stock dans un variable


        //On analyse cette valeur pour voir si elle respecte les consignes
	if ( l_int >= 0) //On vérifie que l est positif
	{
		if ( l_int < pow(2,P.mu-P.j))
		{
			gtk_image_set_from_file(pTempImage, "Image/Validation.png");
			P.l = l_int;
			gtk_label_set_text(GTK_LABEL(pTempLabel), "Valeur enregistrer"); 			
		}
		else
		{
			gtk_image_set_from_file(pTempImage, "Image/Refus.jpg");
			gtk_label_set_text(GTK_LABEL(pTempLabel), "Erreur : l >= pow(2,mu-j)");
		}
	}
	else
	{
		gtk_image_set_from_file(pTempImage, "Image/Refus.jpg");
		gtk_label_set_text(GTK_LABEL(pTempLabel), "Erreur : l est negatif");
	}


	//FIN FONCTION
	g_list_free(pList);

}
