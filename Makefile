CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=c99 -Wall
OBJCOPY=objcopy

src/os: src/mmap.o src/aradani.o src/os_expimp.o src/os_wordump.o
src/c2: src/c2.c src/aradani.o
	${CC} $^ -o $@ ${CFLAGS}
src/main: src/main.c src/aradani.o
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
src/main_%: src/main_%.o src/aradani.o 
	${CC} src/main.c $^ -o $@ ${CFLAGS}
%.bin: %.A
	nasm -f bin $^ -o $@

%.oars: %.binp
	head -c -1 $^ > $@
%.binp: %.elf
	${OBJCOPY} -O binary -j .text.* -j .text -j .data $^ $@
%.elf: %.oO3freestanding
	${LD} -T arsi.ld $^ -o $@
%.oO3freestanding: %.c
	${CC} -c $^ -o $@ ${CFLAGS} -ffreestanding -O3 -fno-stack-clash-protection -fno-stack-protector
src/arsi2.arsi: src/arsi2.oars src/arsi.oars src/jmp.bin
	cat $^ > $@
%.arsi: %.oars src/jmp.bin
	cat $^ > $@

clean:
	rm -f src/*.bin src/*.oars src/*.o
.PHONY: clean 
