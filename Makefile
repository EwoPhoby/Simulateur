CC = g++
CFLAGS = -Wall -ansi -c
LDFLAGS=-lraylib -lGL -lm -lpthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor
EXEC_NAME = projet
OBJ_FILES = main.o tank.o

all : $(EXEC_NAME)

run :
	./projet

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LDFLAGS)

tank.o: tank.cpp
	$(CC) tank.cpp $(CFLAGS) $(LDFLAGS)

main.o: main.cpp
	$(CC) main.cpp $(CFLAGS) $(LDFLAGS)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

git:
	make clean
	git add *
	git commit -a
	git push