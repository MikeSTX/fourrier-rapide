#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>
#include "/home/tbruhiere/Projet_Mathematiques/Parametre.h"


#include "Methodes_saisir/methode_saisir.c"
#include "Methodes_calcul/methodes_calcul.c"
 
int main(int argc,char **argv)
{
	//Variables


	//Debut programme
	FILE *f = fopen(".StepCalcul.txt", "w"); //Vide le fichier ou sont contenu toutes les étapes du calcule (si prog a déjà ete utiliser)
	fclose(f); //On ferme le fichier

	gtk_init(&argc,&argv); //Initialisation de GTK+ 
	CatchValue_Function(); //Appelle fonction dans "methode_saisi.c"

	//Fin programme
	return 0; 
}

