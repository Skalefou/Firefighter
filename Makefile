all: compile
compile:
	g++ src/*.cpp -o Firefighter -DSFML_STATIC -I src/include -L src/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32
debug:
	g++ -g src/*.cpp -o Firefighter -DSFML_STATIC -I src/include -L src/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32
clean:
	del *.exe