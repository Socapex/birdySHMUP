
# Notez bien, j'utilise l'expantion par guillemet et l'outil sdl-config,
# comme ca les parametres passez au compilateur sont toujours bon
# peu importe votre configuration.

# TODO: Rajouter un make pour linux, voir si on peu utiliser __APPLE__ etc
# pour differencier les makes. Sinon make osx et make linux.

UNAME := $(shell uname)
EXEC = Game

release: compile_release
	./$(EXEC)

compile_release:
ifeq ($(UNAME), Darwin)
	clang++ `sdl-config --cflags --libs` -lSDL_image -o $(EXEC) src/*.cpp -DMACTERMINAL
endif
ifeq ($(UNAME), Linux)
	g++  src/*.cpp `sdl-config --cflags --libs` -lSDL_image -o $(EXEC)
endif

clean:
	rm $(EXEC) -f

