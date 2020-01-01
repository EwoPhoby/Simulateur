CC = g++
CFLAGS = -Wall -ansi -c
LDFLAGS=-lraylib -lGL -lm -lpthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor
EXEC_NAME = projet
OBJ_FILES = Main.o Tank.o Launcher.o Moteur.o Vanne.o Pompe.o

all : $(EXEC_NAME)

run :$(EXEC_NAME)
	./projet

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LDFLAGS)

Tank.o: Tank.cpp
	$(CC) Tank.cpp $(CFLAGS) $(LDFLAGS)

Moteur.o: Moteur.cpp
	$(CC) Moteur.cpp $(CFLAGS) $(LDFLAGS)

Pompe.o: Pompe.cpp
	$(CC) Pompe.cpp $(CFLAGS) $(LDFLAGS)

Vanne.o: Vanne.cpp
	$(CC) Vanne.cpp $(CFLAGS) $(LDFLAGS)

Launcher.o: Launcher.cpp
	$(CC) Launcher.cpp $(CFLAGS) $(LDFLAGS)

Main.o: Main.cpp
	$(CC) Main.cpp $(CFLAGS) $(LDFLAGS)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

git:
	git add .
	git commit -a --allow-empty-message -m ''
	git push