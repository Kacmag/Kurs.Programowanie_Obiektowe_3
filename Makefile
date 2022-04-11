CXXFLAGS= -c -g -Iinc -Wall -pedantic

__start__: ukladRownan
	./ukladRownan

ukladRownan: obj/main.o obj/LinearEquations.o obj/matrix.o obj/vector.o
	g++ -Wall -pedantic -o ukladRownan obj/main.o obj/vector.o\
                                   obj/matrix.o obj/LinearEquations.o

obj/main.o: src/main.cpp inc/LinearEquations.hh inc/matrix.hh inc/vector.hh\
        inc/size.h
	g++ ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/LinearEquations.o: src/LinearEquations.cpp inc/LinearEquations.hh
	g++ ${CXXFLAGS} -o obj/LinearEquations.o src/LinearEquations.cpp

obj/matrix.o: src/matrix.cpp inc/matrix.hh 
	g++ ${CXXFLAGS} -o obj/matrix.o src/matrix.cpp

obj/vector.o: src/vector.cpp inc/vector.hh inc/size.h
	g++ ${CXXFLAGS} -o obj/vector.o src/vector.cpp

clean:
	rm -f obj/*.o ukladRownan
