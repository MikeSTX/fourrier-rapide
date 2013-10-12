Projet Mathématiques
========================

	*début : 27/09/2013 - fin : 15/10/2013*

	**Cahier des charges :** Coder un programme calculant la transformé rapide de fourier de n'importe quel fonction
	**Langage choisit :** C avec bibliothèques GTK+ (interface graphique)

	**Equipe :** 
		* CACHELOU Christopher <chris.esiea@gmail.com>
		* CAZEAU Isabelle <cazeau.isabelle@gmail.com>
		* CORBINEAU Nadia <nadia.corbineau@gmail.com>
		* BRUHIERE Thibaut <tbruhiere@gmail.com>





## Compilation du programme :

Ce projet a été codé en C incluant les bibliothèques GTK+ pour générer une interface graphique.
Pour compiler le code, il est nécessaire de télécharger les bibliothèques GTK+ les plus récentes (V. 2.24)
Pour se faire, il faut :

	* Sous LINUX : ouvrir un terminal, entrer la commande : 
		`sudo apt-get install libgtk2.24-dev`

		Pour compiler le code sous LINUX, il faut ouvrir un terminale de commande, se mettre dans le répertoire du projet, puis réaliser la commande :
			`gcc main.c -o main `pkg-config --cflags --libs gtk+-2.0` -lm` 
		puis la commande 
			`./main`

		Si le fichier "MakeFile est présent dans le répertoire du projet, faire la commande :
			`make run`
 
	* Sous Windows : Télécharger la bibliothèque du lien suivant : ![Telecharger GTK+](http://www.gtk.org/download/)


	Pour compiler sous Windows, c'est plus compliqué. Les différents IDE (DevCpp ou Code::Block pour les plus connus), intègre différement la bibliothèques GTK+
	, nous vous invitons donc à lire la documentation correspondante à votre IDE pour y intégrer GTK+. ce lien : "" peut également vous aider.





## Fichiers du projet mathématiques : 



-------------------------------------------------------
