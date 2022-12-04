
ALL: main

	./main 1
	./main 2
	./main 3
	./main 4
	./main 5
	./main 6
	./main 7
	./main 8
	./main 9
	./main 10
	./main 11
	./main 12
	./main 13
	./main 14
	./main 15
	./main 16
	./main 17
	./main 18
	./main 19
	./main 20
	./main 21
	./main 22
	./main 23
	./main 24
	./main 25
	./main 26
	./main 27
	./main 28
	./main 29
	./main 30
	./main 31
	./main 32
	./main 33
	./main 34
	./main 35
	./main 36
	./main 37
	./main 38
	./main 39
	./main 40
	./main 41
	./main 42
	./main 43
	./main 44
	./main 45
	./main 46
	./main 47
	./main 48
	./main 49
	./main 50
	./main 51
	./main 52
	./main 53
	./main 54
	./main 55
	./main 56
	./main 57
	./main 58
	./main 59
	./main 60
	./main 61
	./main 62
	./main 63
	./main 64
	./main 65
	./main 66
	./main 67
	./main 68
	./main 69
	./main 70
	./main 71
	./main 72
	./main 73
	./main 74
	./main 75
	./main 76
	./main 77
	./main 78
	./main 79
	./main 80
	./main 81
	./main 82
	./main 83
	./main 84
	./main 85
	./main 86
	./main 87
	./main 88
	./main 89
	./main 90
	./main 91
	./main 92
	./main 93
	./main 94
	./main 95
	./main 96
	./main 97
	./main 98
	./main 99
	./main 100

	
main:	main.o escalonador.o logtree.o fila_fifo.o
	gcc main.o escalonador.o logtree.o fila_fifo.o -o main
	
main.o:	main.c escalonador.h
	gcc -c main.c
	
escalonador.o:	escalonador.c escalonador.h logtree.h fila_fifo.h
	gcc -c escalonador.c

logtree.o:	logtree.c logtree.h
	gcc -c logtree.c

fila_fifo.o:	fila_fifo.c fila_fifo.h
	gcc -c fila_fifo.c	



clean:	
	rm -f *.o main
	
