CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=gnu99 -Wall
#-Wno-multichar -fno-stack-clash-protection -fno-stack-protector
OBJCOPY=objcopy

run: src/main.out src/a_pith2.pith
	./src/main.out
src/main.out: src/main.c src/aradani.o src/map_pith.o src/load_pith.o
	${CC} $^ -o $@ ${CFLAGS} -lraylib
src/show_aradani.out: src/show_aradani.c src/aradani.o
	${CC} $^ -o $@ ${CFLAGS}
src/gui.out: src/gui.c src/aradani.o
	${CC} $^ -o $@ ${CFLAGS} -lraylib
src/a_pith2.pith: src/a_pith2.oars src/a_pith.oars src/goto.bin
	cat $^ > $@

%.out: %.c
	${CC} $^ -o $@ ${CFLAGS}
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
%.bin: %.asm
	nasm -f bin $^ -o $@
%.oars: %.c
	@#compile as whole
	${CC} -c $^ -o $@ ${CFLAGS} -DARSI -ffreestanding -O3
	@# use linker script to place
	@# "head" function body text at the begining and
	@# "tail" - text at the end.
	@${LD} -T arsi.ld $@ -o $@.elf
	@# copy text from elf formated object file to pure text (binary) file. 
	@${OBJCOPY} -O binary -j .text.* -j .text -j .data $@.elf $@.binp
	@# remove 1 byte (ret) instruction from "tail" function body
	@head -c -1 $@.binp > $@
	@# delete trush.
	@rm $@.binp $@.elf 
%.pith: %.oars src/goto.bin
	cat $^ > $@
clean:
	rm -f **/*.bin **/*.oars **/*.o **/*.arsi **/*.pith **/*.out						
.PHONY: clean run
