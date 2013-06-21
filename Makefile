# Notez bien, j'utilise l'expantion par guillemet et l'outil sdl-config,
# comme ca les parametres passez au compilateur sont toujours bon
# peu importe votre configuration.

# TODO: Rajouter un make pour linux, voir si on peu utiliser __APPLE__ etc
# pour differencier les makes. Sinon make osx et make linux.

EXEC = Game

release: compile_release
	./$(EXEC)

compile_release:
	clang++ `sdl-config --cflags --libs` -lSDL_image -o $(EXEC) src/*.cpp -DMACTERMINAL

clean:
	rm $(EXEC) -f

