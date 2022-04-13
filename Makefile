OS := $(shell uname)
 
debug-window:
	g++ -g -std=c++17 src/*.cpp -o Firefighter -DSFML_STATIC -I include -L lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32 -lfreetype
release-window:
	g++ -s -std=c++17 src/*.cpp -o Firefighter -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic -DSFML_STATIC -I include -L lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32 -lfreetype
clean-window:
	del *.exe
	del *.o
release-linux:
	g++ -std=c++17 src/*.cpp -o Firefighter -I include -L lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
debug-linux:
	g++ -std=c++17 -g src/*.cpp -o Firefighter -I include -L lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
clean-linux:
	rm -f *.o
	rm -f *.out 