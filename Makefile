CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=c99 -Wall -Wno-multichar
OBJCOPY=objcopy

src/a_a.arsi:        \
	src/a_a.oars       \
	src/a_b.oars       \
	src/a_c.oars       \
	src/a_junctions.oars   \
	src/goto.bin
	cat $^ > $@
src/a_cycle.arsi:        \
	src/a_cycle.oars       \
	src/a_next.oars 	     \
	src/a_junctions.oars   \
	src/goto.bin
	cat $^ > $@
src/a_init_seven.arsi:          \
	src/a_init_seven.oars  \
	src/a_init_seven2.oars \
	src/a_junctions.oars   \
	src/goto.bin
	cat $^ > $@

src/a_quick_sort.arsi:   \
	src/a_quick_sort.oars  \
	src/a_next.oars        \
	src/a_junctions.oars   \
	src/goto.bin
	cat $^ > $@

src/a_test_socket.arsi:  \
	src/a_test_socket.oars \
	src/a_epoll.oars       \
	src/a_next.oars        \
	src/a_junctions.oars   \
	src/goto.bin
	cat $^ > $@

src/os:                  \
	src/os.c               \
	src/os_exports_bark.o  \
	src/os_exports.o
#src/os_exports_epoll.o

src/ui: src/ui.c
	${CC} $^ -o $@ ${CFLAGS} -lraylib
src/seven: src/seven.c src/ada.o src/mc21.o

%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
%.bin: %.asm
	nasm -f bin $^ -o $@
%.oars: %.c
	@#compile as whole
	${CC} -c $^ -o $@ ${CFLAGS} -ffreestanding -O3 -fno-stack-clash-protection -fno-stack-protector
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
src/a_%.arsi: src/a_%.oars src/goto.bin
	cat $^ > $@
clean:
	rm -f              \
		src/*.bin        \
		src/*.oars       \
		src/*.o          \
		src/*.arsi       \
		src/os           \
		src/epoll_client \
		src/epoll_server \
		src/seven 	
.PHONY: clean 
