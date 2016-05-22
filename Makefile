.PHONY: clean functions

bin/alphabet: obj/main.o obj/functions.o obj/interface.o
	gcc -o bin/alphabet obj/main.o obj/functions.o obj/interface.o -lm

obj/main.o: src/main.c
	gcc -c src/main.c -o obj/main.o

obj/functions.o: src/functions.c
	gcc -c src/functions.c -o obj/functions.o

obj/interface.o: src/interface.c
	gcc -c src/interface.c -o obj/interface.o
	
clean:
	rm -f bin/* obj/*
	
functions: bin/alphabet 
	bin/alphabet 