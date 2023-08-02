all:
	gcc -g main.c -o main -lpthread
	gcc -g passenger.c -o passenger -lpthread
	gcc -g officer.c -o officer -lpthread
	gcc -g tellers.c -o tellers -lpthread
	gcc opg.c -o opg -lglut -lGLU -lGL -lm
