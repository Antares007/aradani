CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=c99 -Wall -Wno-multichar
OBJCOPY=objcopy
src/os_g:
	CFLAGS="-O3 -g" make src/os
	
src/os: src/aradani.o   \
	src/junctions.o   		\
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
	@# place "head" nargo body text at begining and "tail" nargo text at end.
	@${LD} -T arsi.ld $@ -o $@.elf
	@# copy text from elf formated object file to pure text (binary) file. 
	@${OBJCOPY} -O binary -j .text.* -j .text -j .data $@.elf $@.binp
	@# remove tail nargo body text. just 1 byte form behaind.
	@head -c -1 $@.binp > $@
	@# delete trush.
	@rm $@.binp $@.elf 
src/a_cycle.arsi: src/a_cycle.oars src/a_debugger.oars src/jmp.bin
	cat $^ > $@
src/a_epoll.arsi: src/a_epoll.oars src/a_debugger.oars src/jmp.bin
	cat $^ > $@
src/a_test_socket.arsi: src/a_test_socket.oars src/a_epoll.oars src/a_debugger.oars src/jmp.bin
	cat $^ > $@
src/a_stream_example.arsi: src/a_stream_example.oars src/a_debugger.oars src/jmp.bin
	cat $^ > $@
src/a_%.arsi: src/a_%.oars src/a_debugger.oars src/jmp.bin
	cat $^ > $@
clean:
	rm -f src/*.bin src/*.oars src/*.o src/*.arsi 			\
	src/os src/epoll_client src/epoll_server src/seven 	
.PHONY: clean 
