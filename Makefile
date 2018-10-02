all: player.o
	gcc -o out player.o

player.o: player.c
	gcc -c player.c

run:
	./out

clean:
	rm out
	rm *.o
