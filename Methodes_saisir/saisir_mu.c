#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>


void CheckValue_mu(GtkWidget *Btn_mu, gpointer data);


/*******************************************************************************
        sous-fonction concernant "mu"
*******************************************************************************/
void CheckValue_mu(GtkWidget *Btn_mu, gpointer data)
{
        //Variables
        GtkWidget *pTempEntry;
        GtkWidget *pTempLabel;
        GtkWidget *pTempLabel_useless;
        GtkImage *pTempImage;
        GList *pList; //Liste chainé pour passer d'un widget à un autre

        const gchar* mu;
	gint mu_int;


        //DEBUT FONCTION
        pList = gtk_container_get_children(GTK_CONTAINER((GtkWidget*)data)); //On recupère tous les widget de la HBox
        pTempLabel_useless = GTK_WIDGET(pList->data); //Le premier élément est un label (ininteressant)

        pList = g_list_next(pList); //On passe à l'élément suivant => la saisi utilisateur (interessant)
        pTempEntry = GTK_WIDGET(pList->data);//On recupère sa valeur

        pList = g_list_next(pList); //Element suivant => bouton (ininteressant)

        pList = g_list_next(pList); //Element suivant => label (interessant)
        pTempLabel = GTK_WIDGET(pList->data); //On recupère sa valeur

        mu = gtk_entry_get_text(GTK_ENTRY(pTempEntry)); //On recupère la valeur contenu dans la zone de saisi

	mu_int = strtol(mu, NULL, 10);

        pList = g_list_next(pList); //Element suivant => image
        pTempImage = GTK_IMAGE(pList->data); //On la stock dans une variable

        //On analyse cette valeur pour voir si elle respecte les consignes
	if (mu_int <= 0)
        {
                gtk_image_set_from_file(GTK_IMAGE(pTempImage), "Image/Refus.jpg");
                gtk_label_set_text(GTK_LABEL(pTempLabel), "Erreur : valeur negative");
        }
        else
        {
                gtk_image_set_from_file(GTK_IMAGE(pTempImage), "Image/Validation.png");

                FILE *f = fopen(".log.txt", "a");
                fprintf(f,"%d\n", mu_int);
                fclose(f);

                gtk_label_set_text(GTK_LABEL(pTempLabel), "Valeur enregistrer");
        }

        //FIN FONCTION
        g_list_free(pList); //On libère l'espace de liste chainé
}

