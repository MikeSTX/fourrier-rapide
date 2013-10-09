#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>


void CheckValue_function(GtkWidget *Btn[1], gpointer data);


void CheckValue_function(GtkWidget *Btn[1], gpointer data)
{
        //Variables
        GtkWidget *pTempEntry;
        GtkWidget *pTempLabel;
        GtkWidget *pTempLabel_useless;
        GtkImage *pTempImage;
        GList *pList; //Liste chainé pour passer d'un widget à un autre

	const gchar *function;

	//DEBUT FONCTION

	//Interface utilisateur
        pList = gtk_container_get_children(GTK_CONTAINER((GtkWidget*)data)); //On recupère tous les widget de la HBox
        pTempLabel_useless = GTK_WIDGET(pList->data); //Le premier élément est un label (ininteressant) 

        pList = g_list_next(pList); //On passe à l'élément suivant => la saisi utilisateur (interessant)
        pTempEntry = GTK_WIDGET(pList->data);//On recupère sa valeur
 
        pList = g_list_next(pList); //Element suivant => bouton (ininteressant)

        pList = g_list_next(pList); //Element suivant => label (interessant)
        pTempLabel = GTK_WIDGET(pList->data); //On recupère sa valeur

        function = gtk_entry_get_text(GTK_ENTRY(pTempEntry)); //On recupère la valeur contenu dans la zone de saisi

        pList = g_list_next(pList); //Element suivant => image
        pTempImage = GTK_IMAGE(pList->data); //On la stock dans un variable


	//On met la fonction dans le fichier ".log.txt"
	FILE *f = fopen(".log_function.txt", "a");
	fprintf(f, "%s\n", function);
	fclose(f);

	gtk_image_set_from_file(pTempImage, "Image/Validation.png");
	gtk_label_set_text(GTK_LABEL(pTempLabel), "Valeur enregistrer");	


	//FIN FONCTION
	g_list_free(pList);

}
