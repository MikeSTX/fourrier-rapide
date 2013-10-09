#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>

/*********************************************************************
*************************************

        Ce fichier permet de rappeller à l'uilisateur tous les parametre qu'il a choisit et
	d'y inscrire la fonction

        create : 02/10/2013
        derniere modification : 02/10/2013 - 18:21

************************************
**********************************************************************/


void Check_Parametre()
{

	//Variables


	//DEBUT FONCTION
	FILE *f = fopen(".StepCalcul.txt", "a");
	fprintf(f, "******* -  PARAMETRE  - ******* \n");
	fprintf(f, "fonction : %s\n", P.fonction);
	fprintf(f, "mu : %d\n", P.mu);
	fprintf(f, "j : %d\n", P.j);
	fprintf(f, "l : %d\n", P.l);
	fprintf(f, "N : %d\n", P.N);
	fprintf(f, "k : %d\n", P.k);
	fprintf(f, "debut periode : %f\n", P.deb_periode);
	fprintf(f, "fin periode : %f\n\n", P.fin_periode);

	fprintf(f, "On a donc le calcul suivant : \n");
	fprintf(f,"----");
	
	fclose(f); 



	//FIN FONCTION

}
