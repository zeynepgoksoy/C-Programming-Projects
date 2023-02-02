all: compile run

compile:
	gcc -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.c
	gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c
	gcc -I ./include/ -o ./lib/Oyun.o -c ./src/Oyun.c
	gcc -I ./include/ -o ./bin/Test ./lib/Dosya.o ./lib/Oyun.o ./lib/Kisi.o ./src/Test.c

run:
	./bin/Test