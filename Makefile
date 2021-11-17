CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=c99 -Wall -Wno-multichar
OBJCOPY=objcopy
src/os_g:
	CFLAGS="-O3 -g" make src/os
	
src/os: src/aradani.o   \
	src/os_debbuger.o     \
	src/os_epoll.o   			\
	src/os_impexp.o       \
	src/os_new.o          \
	src/os_next.o         \
	src/os_wordump.o      
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
%.bin: %.A
	nasm -f bin $^ -o $@
%.oars: %.c
	${CC} -c $^ -o $@ ${CFLAGS} -ffreestanding -O3 -fno-stack-clash-protection -fno-stack-protector
	# place "head" nargo body text at begining and "tail" nargo text at end.
	${LD} -T arsi.ld $@ -o $@.elf
	# copy text from elf formated object file to pure text (binary) file. 
	${OBJCOPY} -O binary -j .text.* -j .text -j .data $@.elf $@.binp
	# remove tail nargo body text. just 1 byte form behaind.
	head -c -1 $@.binp > $@
	# delete trush.
	rm $@.binp $@.elf 
%07.arsi: %07.oars %06.arsi
	cat $^ > $@
%06.arsi: %06.oars %05.arsi
	cat $^ > $@
%05.arsi: %05.oars %04.arsi
	cat $^ > $@
%04.arsi: %04.oars %03.arsi
	cat $^ > $@
%03.arsi: %03.oars %02.arsi
	cat $^ > $@
%02.arsi: %02.oars %01.arsi
	cat $^ > $@
%01.arsi: %01.oars %00.arsi
	cat $^ > $@
%00.arsi: %00.oars src/jmp.bin
	cat $^ > $@
clean:
	rm -f src/*.bin src/*.oars src/*.o src/*.arsi src/os src/epoll_client src/epoll_server
.PHONY: clean 
