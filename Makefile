OS := $(shell uname)

all: compile

ifeq (%(OS),Windows_NT)
compile:
	g++ src/*.cpp -o Firefighter -DSFML_STATIC -I include -L lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32
debug:
	g++ -g src/*.cpp -o Firefighter -DSFML_STATIC -I include -L lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32
clean:
	del *.exe
	del *.o
else
compile:
	g++ src/*.cpp -o Firefighter.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
debug:
	g++ -g src/*.cpp -o Firefighter.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
clean:
	rm -f *.o
	rm -f *.out 
endif