bomberman:
	gcc Bomberman.c Bomberman_image.c Bomberman.h -o bomb -lTableauNoir -L/usr/local/lib/tableaunoir  -Wall

run:
	./bomb

clean:
	rm -f bomb
