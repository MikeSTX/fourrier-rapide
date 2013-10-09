#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>


void CheckValue_N(GtkWidget *Btn[4], gpointer data);


void CheckValue_N(GtkWidget *Btn[4], gpointer data)
{
        //Variables
        GtkWidget *pTempEntry;
        GtkWidget *pTempLabel;
        GtkWidget *pTempLabel_useless;
        GtkImage *pTempImage;
        GList *pList; //Liste chainé pour passer d'un widget à un autre
	
	const gchar* N;
	gint N_int, k_int;
	int mod2; //Bit pour savoir si N est modulo 2
	int i;

	//DEBUT FONCTION
	mod2 = 0;


	//Interface utilisateur
	 pList = gtk_container_get_children(GTK_CONTAINER((GtkWidget*)data)); //On recupère tous les widget de la HBox
        pTempLabel_useless = GTK_WIDGET(pList->data); //Le premier élément est un label (ininteressant)

        pList = g_list_next(pList); //On passe à l'élément suivant => la saisi utilisateur (interessant)
        pTempEntry = GTK_WIDGET(pList->data);//On recupère sa valeur 

	pList = g_list_next(pList); //Element suivant => bouton (inintéressant) 
  
        pList = g_list_next(pList); //Element suivant => label (interessant)
        pTempLabel = GTK_WIDGET(pList->data); //On recupère sa valeur

        N = gtk_entry_get_text(GTK_ENTRY(pTempEntry)); //On recupère la valeur contenu dans     la zone de saisi


        N_int = strtol(N, NULL, 10);

        pList = g_list_next(pList); //Element suivant => image
        pTempImage = GTK_IMAGE(pList->data); //On la stock dans un variable


        //On analyse cette valeur pour voir si elle respecte les consignes
	if(N_int >= 0) //On vérifie que N est bien positif
	{
		for ( i = 0; i <= 15; i = i + 1) //On vérifie que N est modulo 2
		{
			if (pow(2,i) == N_int)
			{
				mod2 = 1; //N est bien modulo 2

				if (N_int <= pow(2, P.j)) //On vérifie que N < pow(2, j)
				{
					//On peut en déduire "k"
					k_int = N_int - 1;

					//Validation
					gtk_image_set_from_file(pTempImage, "Image/Validation.png");
					P.k = k_int;
					P.N = N_int;
					gtk_label_set_text(GTK_LABEL(pTempLabel), "Valeur enregistrer");
				}
				else
				{
					gtk_image_set_from_file(pTempImage, "Image/Refus.jpg");
					gtk_label_set_text(GTK_LABEL(pTempLabel), "Erreur : N > pow(2, j)");
				}
			}
		}
		
		if (mod2 == 0) //N n'est pas modulo 2
		{
			gtk_image_set_from_file(pTempImage, "Image/Refus.jpg");
			gtk_label_set_text(GTK_LABEL(pTempLabel), "Erreur : N n'est pas modulo 2");
		}
	}
	else
	{
		gtk_image_set_from_file(pTempImage, "Image/Refus.jpg");
		gtk_label_set_text(GTK_LABEL(pTempLabel), "Erreur : valeur negative");	
	}	


	//FIN FONCTION
	g_list_free(pList); //On libère l'espace de la liste chainé

}
