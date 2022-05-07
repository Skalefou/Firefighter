WIN_FLAG = -DSFML_STATIC -I include -L lib -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopenal32 -lFLAC -lvorbisenc -lvorbisfile -lvorbis -logg -lopengl32 -lwinmm -lgdi32 -lfreetype
STATIC_WIN_FLAG =  -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic

debug-window:
	g++ -g -std=c++17 src/*.cpp -o Firefighter $(WIN_FLAG)
release-window:
	g++ -s -std=c++17 src/*.cpp -o Firefighter $(STATIC_WIN_FLAG) $(WIN_FLAG)
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