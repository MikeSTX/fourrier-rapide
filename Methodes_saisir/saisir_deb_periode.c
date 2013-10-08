#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>


void CheckValue_deb_p(GtkWidget *Btn_deb_p, gpointer data);


void CheckValue_deb_p(GtkWidget *Btn_deb_p, gpointer data)
{
        //Variables
        GtkWidget *pTempEntry;
        GtkWidget *pTempLabel;
        GtkWidget *pTempLabel_useless;
        GtkImage *pTempImage;
        GList *pList; //Liste chainé pour passer d'un widget à un autre

	const gchar* deb_periode;
	float debut_periode_int;


	//DEBUT FONCTION

        //Interface utilisateur
        pList = gtk_container_get_children(GTK_CONTAINER((GtkWidget*)data)); //On recupère tous les widget de la HBox
        pTempLabel_useless = GTK_WIDGET(pList->data); //Le premier élément est un label (ininteressant)
        pList = g_list_next(pList); //On passe à l'élément suivant => la saisi utilisateur (interessant)
        pTempEntry = GTK_WIDGET(pList->data);//On recupère sa valeur 
        pList = g_list_next(pList); //Element suivant => bouton (ininteressant)

        pList = g_list_next(pList); //Element suivant => label (interessant)
        pTempLabel = GTK_WIDGET(pList->data); //On recupère sa valeur

        deb_periode = gtk_entry_get_text(GTK_ENTRY(pTempEntry)); //On recupère la valeur contenu dans la zone de saisis

        pList = g_list_next(pList); //Element suivant => image
        pTempImage = GTK_IMAGE(pList->data); //On la stock dans un variable


	//On analyse le résultat
        if ( strcmp("-2*pi", deb_periode) == 0)
        {
                debut_periode_int = -2 * M_PI;
        }

        if ( strcmp("-pi", deb_periode) == 0)
        {
                debut_periode_int = -1 *  M_PI;
        }

        if ( strcmp("-pi/2", deb_periode) == 0)
        {
                debut_periode_int = -1 * M_PI_2;
        }

        if ( strcmp("-pi/4", deb_periode) ==0)
        {
                debut_periode_int = -1 * M_PI_4;
        }

        if ( strcmp("pi", deb_periode) == 0)
        {
                debut_periode_int =  M_PI;
        }

        if ( strcmp("pi/4", deb_periode) == 0)
        {
                debut_periode_int =  M_PI_4;
        }


        if ( strcmp("pi/2", deb_periode) == 0)
        {
                debut_periode_int =  M_PI_2;
        }

        if ( strcmp("2*pi", deb_periode) == 0)
        {
                debut_periode_int = 2 * M_PI;
        }




	FILE *f = fopen(".log.txt", "a");
	fprintf(f, "%f\n", debut_periode_int);
	fclose(f);

	gtk_image_set_from_file(GTK_IMAGE(pTempImage), "Image/Validation.png");
	gtk_label_set_text(GTK_LABEL(pTempLabel), "Valeur enregitrer"); 


	//FIN FONCTION
	g_list_free(pList); //On libère l'espace de la liste chainé

}

