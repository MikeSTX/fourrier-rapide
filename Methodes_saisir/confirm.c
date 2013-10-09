#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>




void ConfirmValue(GtkWidget *Btn_confirm, gpointer data);

/**************************************************************************
	Cette fonction ne sert qu'à passer à l'étape de calcul et
	de rétrecir le fenêre de saisi (maintenant inutile).
**************************************************************************/

void ConfirmValue(GtkWidget *Btn_confirm, gpointer data)
{
	//Variables


	//DEBUT FONCTION
	gtk_window_iconify(data);
	GetResult_Function();

	//FIN FONCTION
}

