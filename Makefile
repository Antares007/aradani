CC|=clang
CFLAGS+=-std=c99 -Wall -Wno-multichar

src/c2: src/c2.c src/aradani.o
	${CC} $^ -o $@ ${CFLAGS}
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
clean:
	git clean -xdf
.PHONY: clean 
