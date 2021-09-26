CC|=clang
CFLAGS+=-std=c99 -Wall -Wno-multichar

src/c2: src/c2.c src/aradani.o
	${CC} $^ -o $@ ${CFLAGS}
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
src/echo: src/echo.o src/aradani.o 
	${CC} src/main.c $^ -o $@ ${CFLAGS}
src/%: src/%.o src/aradani.o 
	${CC} src/main.c $^ -o $@ ${CFLAGS}
clean:
	git clean -xdf
.PHONY: clean 
