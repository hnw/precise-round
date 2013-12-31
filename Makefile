CC=gcc
LD=gcc

all: test/test-round
clean:
	rm test/test-round *.o test/*.o

dtoa.o: dtoa.c
	$(CC) -c -DLong=int -DIEEE_8087 $?

test/test-round: dtoa.o precise_round.o test/test-round.o
	$(LD) -o $@ $^


