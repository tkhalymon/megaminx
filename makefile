UNAME = $(shell uname -o)
ifeq ($(OS),Windows_NT)
	EXEEXT = .exe
	COMPILE_OPT = -lfreeglut -lglu32 -lopengl32
else
	COMPILE_OPT = -lGL -lGLU -lglut
endif

all: megaminx

megaminx: main.o center.o edge.o corner.o face.o utils.o megaminx.o
	g++ main.o center.o edge.o corner.o face.o utils.o megaminx.o $(COMPILE_OPT) -o megaminx

main.o: main.cpp
	g++ -c main.cpp
center.o: engine/center.cpp
	g++ -c engine/center.cpp
edge.o: engine/edge.cpp
	g++ -c engine/edge.cpp
corner.o: engine/corner.cpp
	g++ -c engine/corner.cpp
face.o: engine/face.cpp
	g++ -c engine/face.cpp
utils.o: engine/utils.cpp
	g++ -c engine/utils.cpp
megaminx.o: engine/megaminx.cpp
	g++ -c engine/megaminx.cpp

clean:
	rm -rf *.o megaminx$(EXEEXT)

run:
	./megaminx$(EXEEXT)
	
test:
	valgrind --leak-check=full ./megaminx$(EXEEXT)
