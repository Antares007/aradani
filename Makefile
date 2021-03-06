CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=gnu99 -Wall -Wno-multichar -fno-stack-clash-protection -fno-stack-protector
OBJCOPY=objcopy

run: all
	./src/os_run src/a_dynamic.arsi
all: src/os_run src/a_cycle.arsi src/a_async.arsi src/a_parse.arsi src/a_dynamic.arsi
nm: nm.c src/os/page.o

src/a_a.arsi:       \
	src/a_a.oars      \
	src/a_7.arsi
	cat $^ > $@

src/a_7.arsi:       \
	src/a_7.oars      \
	src/a_g.oars      \
	src/os.arsi
	cat $^ > $@

src/a_pp.arsi:       \
	src/a_pp.oars      \
	src/a_parsers.arsi
	cat $^ > $@

src/a_stdio.arsi:            \
	src/a_stdio.oars           \
	src/a_stdout.oars          \
	src/a_stdin.oars           \
	src/a_stream.oars          \
	src/a_epoll.oars           \
	src/os.arsi                
	cat $^ > $@

src/a_parse_tok.arsi:                   \
	src/a_parse_tok.oars           \
	src/a_parse_u8cp.arsi
	cat $^ > $@
src/a_parse_u8cp.arsi:              \
	src/a_parse_u8cp.oars      \
	src/os.arsi
	cat $^ > $@

src/a_stream.arsi:                  \
	src/a_stream.oars          \
	src/a_epoll.oars           \
	src/os.arsi
	cat $^ > $@

src/os.arsi:                 \
	src/a_queue.oars           \
	src/a_junctions.oars       \
	src/goto.bin
	cat $^ > $@

src/os_run:                  \
	src/os_run.c               \
	src/os_cycle.o             \
	src/os_hrtime.o            \
	src/os_bark.o              \
	src/os_wordump.o           \
	src/os/nar.o               \
	src/os/soll.o              \
	src/os/call.o              \
	src/os/debugger.o          \
	src/os/new.o               \
	src/os/next.o              \
	src/os/page.o              \
	src/os_epoll.o             
	${CC} $^ -o $@ ${CFLAGS} -lraylib

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
src/a_%.arsi: src/a_%.oars src/os.arsi
	cat $^ > $@
src/a_%.tarsi: src/a_%.oars src/goto.bin
	cat $^ > $@
clean:
	rm -f                   \
		src/*.bin             \
		src/*.oars            \
		src/*.o               \
		src/*.arsi            \
		src/*.tarsi           \
		src/os/*.o            \
		src/os_run            \
		src/etc/epoll_client  \
		src/etc/epoll_server  \
		src/etc/epoll_stdin   \
		src/etc/epoll_server_oneshot   \
		src/gui/ui
.PHONY: clean run all
