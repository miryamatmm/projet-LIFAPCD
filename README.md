# Projet de conception et développement d'une application : **Amour Salé**

## Présentation

**Amour Salé** est un jeu narratif de romance interactif inspiré de *Amour Sucré*, dans lequel le joueur incarne un(e) lycéen(ne) évoluant dans un univers riche en émotions, en relations humaines et en choix narratifs.

Le joueur peut créer et personnaliser son personnage, interagir avec des personnages variés, et influencer le déroulement de l'histoire selon ses décisions. L’expérience de jeu repose sur des intrigues amoureuses, des dilemmes, et des événements dynamiques, créant ainsi une immersion forte dans un univers adolescent fictif et engageant.

---

## Fonctionnement du jeu

Pour jouer :
- Sélectionnez **"Quête"** dans le menu principal.
- Interagissez avec les personnages via des dialogues à choix multiples (A, B ou C).
- Vos décisions influencent les relations et le développement de l’histoire.

🎯 **Objectif principal** : s'amuser, s'immerger, et explorer différentes relations possibles dans un cadre narratif évolutif.

---

## Prérequis techniques

### 🔧 Système requis

- macOS, Linux, ou Windows avec **WSL (Windows Subsystem for Linux)** activé.
- Compilateur **GCC**
- Bibliothèque **SDL2** et ses extensions
- Générateur de documentation **Doxygen**

### 📦 Installation

```bash
# Sur macOS
brew install gcc sdl2 doxygen

# Sur Linux ou Windows (via WSL)
sudo apt install gcc libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev doxygen
```

---

## Organisation du projet

```text
📁 src/        → Code source (.cpp / .h)
  ├── core/   → Logique métier et règles du jeu
  ├── sdl2/   → Interface graphique SDL2
  ├── txt/    → Version texte du jeu
  └── test/   → Tests de régression (core)

📁 data/       → Images, polices et ressources graphiques
📁 bin/        → Fichiers exécutables (.exe)
📁 obj/        → Fichiers objets (.o)
📁 doc/        → Fichiers de configuration Doxygen + documentation générée
📄 Makefile    → Compilation, nettoyage, génération de documentation
📄 README.md   → Présentation du projet
```

---

## Compilation du projet

Depuis le répertoire racine (où se situe le `Makefile`) :

```bash
# Compiler le projet
make

# Nettoyer les fichiers objets et exécutables
make clean
```

---

## Exécution du projet

Après compilation, lancez l’un des exécutables suivants :

```bash
# Tests de régression
./bin/test

# Version texte
./bin/affichageTXT

# Version graphique SDL2
./bin/affichageSDL
```

---

## Génération de la documentation

Pour générer la documentation du module via Doxygen :

```bash
doxygen doc/image.doxy
```

La documentation HTML sera générée dans un dossier `/html`, consultable via navigateur.

---

## Auteures du projet

- **El Ouarrad Mariam**
- **Yagbasan Aleyna**
- **Atamna Miryam**

---

## Remarques finales

Ce projet a été réalisé dans le cadre d'un travail universitaire de conception et développement logiciel, avec une attention particulière portée à la modularité du code, à l'organisation des ressources et à la documentation.  
L’objectif était de développer une application interactive, engageante et techniquement rigoureuse.
