
FLAGS = -Wall -pthread -g

all: aufgabe2 aufgabe3 aufgabe4 aufgabe5 aufgabe6

clean:
	rm -f aufgabe2 aufgabe3 aufgabe4 aufgabe5 aufgabe6

#aufgabe1: aufgabe1.c
#	gcc -o aufgabe1 aufgabe1.c $(FLAGS)

aufgabe2: aufgabe2.c aufgabe1.h common_threads.h
	gcc -o aufgabe2 aufgabe2.c aufgabe1.c $(FLAGS)

aufgabe3: aufgabe3.c aufgabe1.h common_threads.h
	gcc -o aufgabe3 aufgabe3.c aufgabe1.c $(FLAGS)

aufgabe4: aufgabe4.c aufgabe1.h common_threads.h LinkedList.h
	gcc -o aufgabe4 aufgabe4.c aufgabe1.c LinkedList.c $(FLAGS)

aufgabe5: aufgabe5.c aufgabe1.h common_threads.h LinkedList.h
	gcc -o aufgabe5 aufgabe5.c aufgabe1.c LinkedList.c $(FLAGS)

aufgabe6: aufgabe6.c aufgabe1.h common_threads.h LinkedList.h
	gcc -o aufgabe6 aufgabe6.c aufgabe1.c LinkedList.c $(FLAGS)
