UNAME = $(shell uname -o)
ifeq ($(OS),Windows_NT)
	EXEEXT = .exe
	COMPILE_OPT = -lfreeglut -lglu32 -lopengl32
else
	COMPILE_OPT = -lGL -lGLU -lglut
endif

all: megaminx

megaminx: *.o
	g++ *.o $(COMPILE_OPT) -o megaminx

*.o: engine/*.cpp *.cpp
	g++ -c engine/*.cpp *.cpp


clean:
	rm -rf *.o megaminx$(EXEEXT)

run:
	./megaminx$(EXEEXT)
	
test:
	valgrind --leak-check=full ./megaminx$(EXEEXT)
