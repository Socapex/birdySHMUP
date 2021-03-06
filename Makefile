
# Notez bien, j'utilise l'expantion par guillemet et l'outil sdl-config,
# comme ca les parametres passez au compilateur sont toujours bon
# peu importe votre configuration.
# Linux and OSX are detected automatically and program is compiled
# accordingly. For windows uname will fail, compile with Visual Studio.

UNAME := $(shell uname)
EXEC = Game

release: compile_release
	./$(EXEC)

compile_release:
ifeq ($(UNAME), Darwin)
	clang++ `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -o $(EXEC) src/*.cpp -DMACTERMINAL
endif
ifeq ($(UNAME), Linux)
	g++  src/*.cpp src/Game/*.cpp `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lSDL_mixer -o $(EXEC)
endif

clean:
	rm $(EXEC) -f

