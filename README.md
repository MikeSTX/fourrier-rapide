************************************************************************************************************
	** Projet Mathématiques **
		début : 27/09/2013 - fin : 15/10/2013

	Cahier des charges : Coder un programme calculant la transformé rapide de fourier de n'importe quel fonction
	Langage choisit : C avec bibliothèques GTK+ (interface graphique)

	Equipe : 
		- CACHELOU Christopher <mail@gmail.com>
		- CAZEAU Isabelle <cazeau.isabelle@gmail.com>
		- CORBINEAU Nadia <nadia.corbineau@gmail.com>
		- BRUHIERE Thibaut <tbruhiere@gmail.com>

************************************************************************************************************

Information "compilation du code" :

Ce projet a été codé en C incluant les bibliothèques GTK+ pour générer une interface graphique.
Pour compiler le code, il est nécessaire de télécharger les bibliothèques GTK+ les plus récentes (V. 2.24)
Pour se faire, il faut :
	- Sous LINUX :
	- Sous Windows :

Pour compiler le code sous LINUX, il faut ouvrir un terminale de commande, se mettre dans le répertoire du projet, puis réaliser la commande :
"gcc main.c -o main `pkg-config --cflags --libs gtk+-2.0` -lm"


-------------------------------------------------------

Information "Code" : (Chaque fichier est commenté)

Le programme est composé de @nombre fichier ".C", @nombre ".h" et le fichier ".log.txt"

	- main.c => Ce fichier contient la fonction principal du code, il rassemble les autres fonction des autres fichiers .c et les met en relation afin de
			d'assurer le fonctionnement du code tout en réduisant au maximum le nombre de ligne, facilitant ainsi le débogage.

	- methodes_saisir.C => Fichier permettant à l'utilisateur de saisir les différents paramètres nécessaires au calcul

	- methodes_calcul.c => Fichier calculant la fonction

	- .log.txt => Contient en dur tous les saisis de l'utilisateur, permettant une sauvegarde de ces valeurs dans le cas d'un bug, mais également de pouvoir, à tout moment, récupérer ces valeurs pour le calcul


-------------------------------------------------------
