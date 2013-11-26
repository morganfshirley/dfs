all: dfs

dfs: main.o object.o component.o baselogiccomponent.o rendercomponent.o speciescomponent.o playerlogiccomponent.o engine.o render.o
	g++ -g main.o object.o component.o baselogiccomponent.o rendercomponent.o engine.o playerlogiccomponent.o speciescomponent.o render.o -lncurses -o dfs

main.o: main.cpp engine.h 
	g++ -g -c main.cpp

object.o: object.cpp object.h component.h
	g++ -g -c object.cpp

component.o: component.cpp component.h
	g++ -g -c component.cpp

baselogiccomponent.o: baselogiccomponent.cpp baselogiccomponent.h
	g++ -g -c baselogiccomponent.cpp

playerlogiccomponent.o : playerlogiccomponent.cpp playerlogiccomponent.h
	g++ -g -c playerlogiccomponent.cpp

rendercomponent.o: rendercomponent.cpp rendercomponent.h
	g++ -g -c rendercomponent.cpp

speciescomponent.o: speciescomponent.cpp speciescomponent.h species.h
	g++ -g -c speciescomponent.cpp

engine.o: engine.cpp engine.h render.h object.h species.h
	g++ -g -c engine.cpp

render.o: render.cpp render.h
	g++ -g -c render.cpp

clean:
	rm -rf *.o
