CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=c99 -Wall -Wno-multichar
OBJCOPY=objcopy

src/os: src/mmap.o
src/c2: src/c2.c src/aradani.o
	${CC} $^ -o $@ ${CFLAGS}
src/main: src/main.c src/aradani.o
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
src/main_%: src/main_%.o src/aradani.o 
	${CC} src/main.c $^ -o $@ ${CFLAGS}

%.oars: %.binp
	head -c -1 $^ > $@
%.binp: %.elf
	${OBJCOPY} -O binary -j .text.* -j .text -j .data $^ $@
%.elf: %.oO3freestanding
	${LD} -T arsi.ld $^ -o $@
%.oO3freestanding: %.c
	${CC} -c $^ -o $@ ${CFLAGS} -ffreestanding -O3

%.arsi: %.oars src/bolo.bin
	cat $^ > $@

clean:
	git clean -xdf
.PHONY: clean 
