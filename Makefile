CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=gnu99 -Wall -Wno-multichar -fno-stack-clash-protection -fno-stack-protector
OBJCOPY=objcopy

src/a_cycle.arsi:            \
	src/a_cycle.oars           \
	src/os.arsi
	cat $^ > $@

src/a_parse.arsi:            \
	src/a_parse.oars           \
	src/os.arsi
	cat $^ > $@

src/a_async.arsi:            \
	src/a_async.oars           \
	src/os.arsi
	cat $^ > $@

src/os.arsi:                 \
	src/a_os_extra.oars        \
	src/a_junctions.oars       \
	src/goto.bin
	cat $^ > $@

src/a_empty2.arsi:           \
	src/a_empty2.oars          \
	src/a_empty.oars           \
	src/goto.bin
	cat $^ > $@

src/os:                      \
	src/os.c                   \
	src/os_hrtime.o            \
	src/os_mc21.o              \
	src/os_ada.o               \
	src/os_bark.o              \
	src/os_exports.o           \
	src/os_exports_epoll.o     \
	src/os_test_epoll.o        \
	src/os_test_cycle_time.o   \
	src/os_next.o
	${CC} $^ -o $@ ${CFLAGS} -lraylib
#	src/a_empty2.o             \
#	src/a_empty.o              \

src/gui/ui: src/gui/ui.c
	${CC} $^ -o $@ ${CFLAGS} -lraylib

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
src/a_%.arsi: src/a_%.oars src/goto.bin
	cat $^ > $@
clean:
	rm -f                      \
		src/*.bin         \
		src/*.oars        \
		src/*.o           \
		src/*.arsi        \
		src/os            \
		src/epoll_client  \
		src/epoll_server  \
		src/seven         \
		src/ui
.PHONY: clean 
