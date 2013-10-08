all: dfs

dfs: main.o object.o component.o engine.o render.o
	g++ -g main.o object.o component.o engine.o render.o -lncurses -o dfs

main.o: main.cpp engine.h 
	g++ -g -c main.cpp

object.o: object.cpp object.h component.h
	g++ -g -c object.cpp

component.o: component.cpp component.h
	g++ -g -c component.cpp

engine.o: engine.cpp engine.h render.h object.h
	g++ -g -c engine.cpp

render.o: render.cpp render.h
	g++ -g -c render.cpp
