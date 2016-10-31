all: stat.o
	gcc -o stattest stat.o

randfile.o: stat.c
	gcc -c stat.c

run: stattest
	./stattest

clean:
	rm ./stattest
	rm *~