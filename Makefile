a.out: test.c
	cc test.c

test: a.out
	./a.out
