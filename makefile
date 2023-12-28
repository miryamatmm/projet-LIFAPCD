OBJ_FILES_TXT = obj/mainTXT.o obj/AffichageTXT.o obj/Menu.o obj/Carte.o obj/Batiment.o obj/Salle.o obj/Joueuse.o obj/Quete.o obj/Objet.o obj/Jeu.o obj/Personnages.o obj/Personne.o obj/Jauge.o
OBJ_FILES_TEST = obj/mainTest.o obj/Menu.o obj/Carte.o obj/Batiment.o obj/Salle.o obj/Joueuse.o obj/Quete.o obj/Objet.o obj/Jeu.o obj/Personnages.o obj/Personne.o obj/Jauge.o
OBJ_FILES_SDL = obj/mainSDL.o obj/Affichage.o obj/Menu.o obj/Carte.o obj/Batiment.o obj/Salle.o obj/Joueuse.o obj/Quete.o obj/Objet.o obj/Jeu.o obj/Personnages.o obj/Personne.o obj/Jauge.o

EXEC_OUTPUT = bin/affichageTXT bin/test bin/affichageSDL

ISDL2_MACOS = /opt/homebrew/include
LSDL2_MACOS = /opt/homebrew/lib

INCLUDES = -I$(ISDL2_MACOS)
LIBS = -L$(LSDL2_MACOS) -lSDL2 -lSDL2_ttf -lSDL2_image

O= obj/
SC= src/core/
ST= src/txt/
STS = src/test/
SSDL = src/sdl2/

CC = g++
CFLAGS = -g -Wall

all: $(EXEC_OUTPUT)

bin/affichageTXT: $(OBJ_FILES_TXT)
	mkdir -p bin; $(CC) $(OBJ_FILES_TXT) -o bin/affichageTXT

bin/test: $(OBJ_FILES_TEST)
	mkdir -p bin; $(CC) $(OBJ_FILES_TEST) -o bin/test

bin/affichageSDL : $(OBJ_FILES_SDL)
	mkdir -p bin ; $(CC) $(OBJ_FILES_SDL) -o bin/affichageSDL $(LIBS)

$(O)mainTXT.o: $(ST)mainTXT.cpp $(SC)Menu.h
	mkdir -p obj; $(CC) $(CFLAGS) -c $(ST)mainTXT.cpp -o $(O)mainTXT.o

$(O)mainTest.o: $(STS)mainTest.cpp $(SC)Menu.h
	mkdir -p obj; $(CC) $(CFLAGS) -c $(STS)mainTest.cpp -o $(O)mainTest.o

$(O)mainSDL.o : $(SSDL)mainSDL.cpp $(SSDL)Affichage.h
	mkdir -p obj; $(CC) $(CFLAGS) $(INCLUDES) -c $(SSDL)mainSDL.cpp -o $(O)mainSDL.o

$(O)AffichageTXT.o: $(ST)AffichageTXT.h $(ST)AffichageTXT.cpp $(SC)Menu.h
	mkdir -p obj; $(CC) $(CFLAGS) -c $(ST)AffichageTXT.cpp -o $(O)AffichageTXT.o

$(O)Affichage.o : $(SSDL)Affichage.h $(SSDL)Affichage.cpp $(SC)Jeu.h $(SC)Menu.h
	mkdir -p obj; $(CC) $(CFLAGS) $(INCLUDES) -c $(SSDL)Affichage.cpp -o $(O)Affichage.o

$(O)Menu.o: $(SC)Menu.h $(SC)Menu.cpp $(SC)Joueuse.h $(SC)Personnages.h $(SC)Carte.h $(SC)Jeu.h
	mkdir -p obj; $(CC) $(CFLAGS) -c $(SC)Menu.cpp -o $(O)Menu.o

$(O)Carte.o: $(SC)Carte.h $(SC)Carte.cpp $(SC)Batiment.h
	mkdir -p obj; $(CC) $(CFLAGS) -c $(SC)Carte.cpp -o $(O)Carte.o

$(O)Batiment.o: $(SC)Batiment.h $(SC)Batiment.cpp $(SC)Salle.h
	mkdir -p obj; $(CC) $(CFLAGS) -c $(SC)Batiment.cpp -o $(O)Batiment.o

$(O)Salle.o: $(SC)Salle.h $(SC)Salle.cpp
	mkdir -p obj; $(CC) $(CFLAGS) -c $(SC)Salle.cpp -o $(O)Salle.o

$(O)Joueuse.o: $(SC)Joueuse.h $(SC)Joueuse.cpp $(SC)Batiment.h $(SC)Salle.h $(SC)Carte.h
	mkdir -p obj; $(CC) $(CFLAGS) -c $(SC)Joueuse.cpp -o $(O)Joueuse.o

$(O)Quete.o: $(SC)Quete.h $(SC)Quete.cpp $(SC)Personnages.h $(SC)Objet.h
	mkdir -p obj; $(CC) $(CFLAGS) -c $(SC)Quete.cpp -o $(O)Quete.o

$(O)Objet.o: $(SC)Objet.h $(SC)Objet.cpp
	mkdir -p obj; $(CC) $(CFLAGS) -c $(SC)Objet.cpp -o $(O)Objet.o

$(O)Jeu.o: $(SC)Jeu.h $(SC)Jeu.cpp $(SC)Quete.h
	mkdir -p obj; $(CC) $(CFLAGS) -c $(SC)Jeu.cpp -o $(O)Jeu.o

$(O)Personnages.o: $(SC)Personnages.h $(SC)Personnages.cpp $(SC)Personne.h
	mkdir -p obj; $(CC) $(CFLAGS) -c $(SC)Personnages.cpp -o $(O)Personnages.o

$(O)Personne.o: $(SC)Personne.h $(SC)Personne.cpp $(SC)Jauge.h
	mkdir -p obj; $(CC) $(CFLAGS) -c $(SC)Personne.cpp -o $(O)Personne.o

$(O)Jauge.o: $(SC)Jauge.h $(SC)Jauge.cpp
	mkdir -p obj; $(CC) $(CFLAGS) -c $(SC)Jauge.cpp -o $(O)Jauge.o

clean:
	rm -f $(OBJ_FILES_TEST) $(OBJ_FILES_TXT) $(EXEC_OUTPUT)
