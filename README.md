##### Amour Salé #####



### Description

Amour Salé est un jeu de romance où vous pouvez incarner un personnage dans un univers lycéen rempli d'émotions fortes, de flirt et de romance. Inspiré par le célèbre jeu "Amour Sucré", Amour Salé vous permet de créer votre propre personnage et de le guider à travers une aventure passionnante.

Dans le jeu, vous pourrez choisir votre propre histoire et les actions de votre personnage qui influenceront les relations que vous développez avec les différents personnages. Vous devrez faire face à de nombreux dilemmes et prendre des décisions importantes qui affecteront le déroulement de l'histoire.

De plus, vous pouvez personnaliser votre personnage, tout en interagissant avec d'autres personnages charmants. Que vous cherchiez l'amour, l'amitié ou simplement à vous amuser. Amour Salé vous permet de vivre une expérience immersive et romantique dans un monde virtuel.

Préparez-vous à des intrigues amoureuses palpitantes, des événements spéciaux et des surprises dans ce jeu passionnant et addictif. Rejoignez dès maintenant le monde merveilleux d'Amour Salé et laissez-vous emporter par cette aventure romantique pleine d'amour, de passion et de mystère.

### Règles du jeu 😉

Pour jouer à Amour Salé, vous devez sélectionner "Quête" dans le menu. Là, vous pourrez explorer le monde du jeu, rencontrer des personnages , interagir avec eux et faire des choix qui influenceront la suite de l'histoire. 😉

Pour discuter avec vos personnages favoris, choisissez une option entre A, B et C selon votre personnalité ! 😉

Ajoutons que la seule règle d'Amour Salé est de s'amuser et de profiter de l'expérience de jeu. Bonne chance dans vos aventures amoureuses et amicales ! 😉

### Installation des prérequis

Sur Windows, il sera nécessaire d'activer WSL (Windows Subsystem for Linux) et installer la distribution Linux de votre choix. Ensuite les commandes seront les memes que sur Linux.

+ Installer le compilateur gcc :
 	- sur macOS: taper dans le terminal la commande suivante : $> brew install gcc
 	- sur Linux/Windows: taper dans le terminal la commande suivante: $> sudo apt install gcc
 	
+ Installer la librairie SDL2 :
	- sur macOs : taper dans le terminal la commande suivante: $> brew install sdl2
	- sur Linux/Windows : taper dans le terminal la commande suivante: $> sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
	
+ Installer doxygen:
	- sur macOS : taper dans le terminal la commande suivante : $> brew install doxygen
	- sur Linux/Windows : $> sudo apt install doxygen


### Organisation du projet

+ Le Makefile contient toutes les dépendances et commandes permettant la compilation du projet, supprime les fichiers objets et éxécutables, et génère la documentation.
+ Le dossier src contient le code source de notre projet, c'est à dire ous les fichiers sources .h et .cpp.. C'est là que vous trouverez les fichiers qui constituent notre programme :
    - un dossier core qui contient le code principal de votre application. Il contient les fichiers qui gèrent la logique de jeu et les fonctionnalités principales.
    - un dossier sdl2 qui contient le code qui utilise la bibliothèque SDL2 pour gérer la partie graphique de votre application.
    - un dossier test qui contient les tests de regression des fichiers core.
    - un dossier txt qui contient le code de la version texte du jeu.
+ Le dossier data contient les éléments nécessaires à l'exécution de notre programme, tels que des images et des polices.
+ Le dossier doc contient le fichier de configuration doxygen ainsi que la page html (une fois générer) de la documentation.
+ Le dossier obj contient tous les fichier objets .o des fichiers .cpp après la compilation grâce au Makefile.
+ Le dossier bin contient les 3 fichiers éxécutables du module, également crées après la compilation grâce au Makefile, juste après la compilation des fichiers .o.


### Compilation du projet

+ Se situer sur le répertoire du projet au niveau du README.
+ Taper la commande $> make, le Makefile va se charger de tout compiler en fonction des fichiers, la compilation ne se fera pas sur les fichiers déjà à jour.
+ Pour effacer tous les fichiers "inutiles" situé dans les dossiers obj et bin il vous suffira de taper la commande suivante : $> make clean


### Exécution du projet

Après la compilation du module, il faudra rester sur le repertoire du projet puis taper la commande $> bin/* dans le terminal avec "*" correspondant au nom de l'exécutable que l'on veut lancer: 
	- Pour les tests de regressions :  $> bin/test.cpp
	- Pour la version texte du jeu : $> bin/affichageTXT.cpp
	- Pour la version SDL2 $> bin/affichageSDL.cpp


### Documentation du module

Amour Salé possède également une documentation doxygen qui se génere avec la commande suivante: $> doxygen doc/image.doxy 
Ceci va génerer un dossier html qui contiendra le fichier html du site où se trouve la documentation complète de notre projet.