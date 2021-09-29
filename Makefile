CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=c99 -Wall -Wno-multichar
OBJCOPY=objcopy

src/os: src/mmap.o
src/c2: src/c2.c src/aradani.o
	${CC} $^ -o $@ ${CFLAGS}
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
src/main_%: src/main_%.o src/aradani.o 
	${CC} src/main.c $^ -o $@ ${CFLAGS}

%.bin: %.binp
	head -c -1 $^ > $@
%.binp: %.elf
	${OBJCOPY} -O binary -j .text.* -j .text -j .data $^ $@
%.elf: %.oars
	${LD} -T arsi.ld $^ -o $@
%.oars: %.c
	${CC} -c $^ -o $@ ${CFLAGS} -ffreestanding -O3


clean:
	git clean -xdf
.PHONY: clean 
