#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>


void CheckValue_l(GtkWidget *Btn_l, gpointer data);


void CheckValue_l(GtkWidget *Btn_l, gpointer data)
{
	//Variables
        GtkWidget *pTempEntry;
        GtkWidget *pTempLabel;
        GtkWidget *pTempLabel_useless;
        GtkImage *pTempImage;
        GList *pList; //Liste chainé pour passer d'un widget à un autre

        const gchar* l;
	int i;
        gint l_int;
        gint j, mu;
        gint Value[2];


	//DEBUT FONCTION

	//Récupération des valeurs "j" et "mu" dans le fichier ".log.txt"
	FILE *f = fopen(".log.txt", "r");
	for ( i = 0; i <= 2; i = i + 1)
	{
		fscanf(f, "%d", &Value[i]);
	}
	fclose(f);

	mu = Value[0];
	j = Value[1];

	//Interface utilisateur
         pList = gtk_container_get_children(GTK_CONTAINER((GtkWidget*)data)); //On recupère tous les widget de la HBox
        pTempLabel_useless = GTK_WIDGET(pList->data); //Le premier élément est un label (ininteressant)
        pList = g_list_next(pList); //On passe à l'élément suivant => la saisi utilisateur (interessant)
        pTempEntry = GTK_WIDGET(pList->data);//On recupère sa valeur 
        pList = g_list_next(pList); //Element suivant => bouton (ininteressant)

        pList = g_list_next(pList); //Element suivant => label (interessant)
        pTempLabel = GTK_WIDGET(pList->data); //On recupère sa valeur

        l = gtk_entry_get_text(GTK_ENTRY(pTempEntry)); //On recupère la valeur contenu dans     la zone de saisi


        l_int = strtol(l, NULL, 10);

        pList = g_list_next(pList); //Element suivant => image
        pTempImage = GTK_IMAGE(pList->data); //On la stock dans un variable


        //On analyse cette valeur pour voir si elle respecte les consignes
	if ( l_int >= 0) //On vérifie que l est positif
	{
		if ( l_int < pow(2,mu-j))
		{
			gtk_image_set_from_file(pTempImage, "Image/Validation.png");
			
			FILE *f = fopen(".log.txt", "a");
			fprintf(f, "%d\n", l_int);
			fclose(f);

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
