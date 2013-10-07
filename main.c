#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>

#include "Methodes_saisir/methode_saisir.c"
 
int main(int argc,char **argv)
{
	//Variables


	//Debut programme
	FILE *f = fopen(".log.txt", "w"); //Vide le fichier ou sont contenu toutes les valeurs entré par l'utilisateur (si prog a déjà ete utiliser)
	fclose(f); //On ferme le fichier

	FILE *f2 = fopen(".log_function.txt", "w");
	fclose(f2);

	gtk_init(&argc,&argv); //Initialisation de GTK+ 
	CatchValue_Function(); //Appelle fonction dans "methode_saisi.c"

	//Fin programme
	return 0; 
}

