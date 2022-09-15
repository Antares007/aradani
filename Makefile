CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=gnu99 -Wall
#-Wno-multichar -fno-stack-clash-protection -fno-stack-protector
OBJCOPY=objcopy

run: src4/main.out src4/a_pith2.pith
	./src4/main.out
src4/main.out: src4/main.c src4/aradani.o src4/map_pith.o src4/load_pith.o
	${CC} $^ -o $@ ${CFLAGS} -lraylib
src4/show_aradani.out: src4/show_aradani.c src4/aradani.o
	${CC} $^ -o $@ ${CFLAGS}
src4/gui.out: src4/gui.c src4/aradani.o
	${CC} $^ -o $@ ${CFLAGS} -lraylib
src4/a_pith2.pith: src4/a_pith2.oars src4/a_pith.oars src/goto.bin
	cat $^ > $@

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
